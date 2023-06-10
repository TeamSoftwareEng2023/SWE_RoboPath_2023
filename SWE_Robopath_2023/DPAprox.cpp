#include "pch.h"
#include "DPAprox.h"

Logic::DPAprox::DPAprox(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
void Logic::DPAprox::approx(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        lstAproxedPath = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>(RoboPathData->GetlstRawPathData());
        douglasPeuckerRecursive(0, lstAproxedPath->Count-1, RoboPathData->GetTolerance());
        RoboPathData->SetlstAproxedPathData(lstAproxedPath);
        UIControl->AppendLog("Daten wurden erfolgreich approximiert\n\n");
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Approximieren der CSV:\n" + e->Message + "\n\n");
        return;
    }
}
void Logic::DPAprox::douglasPeuckerRecursive(int iStartItr, int iEndItr, float fMaxDistance) {
    try
    {
        Projectdata::Point3D^ pStart = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pEnd = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pAct = gcnew Projectdata::Point3D();
        float fDist = 0, fMaxDist = 0;
        int iMaxItr = 0;

        if (lstAproxedPath->Count < 3) {
            return;
        }
        if (System::Math::Abs(iEndItr - iStartItr) == 1) {
            return;
        }
        pStart->fX = lstAproxedPath[iStartItr]->fX;
        pStart->fY = lstAproxedPath[iStartItr]->fY;
        pStart->fZ = lstAproxedPath[iStartItr]->fZ;

        pEnd->fX = lstAproxedPath[iEndItr]->fX;
        pEnd->fY = lstAproxedPath[iEndItr]->fY;
        pEnd->fZ = lstAproxedPath[iEndItr]->fZ;

        for (int iItr = iStartItr; iItr < iEndItr; iItr++) {

            pAct->fX = lstAproxedPath[iItr]->fX;
            pAct->fY = lstAproxedPath[iItr]->fY;
            pAct->fZ = lstAproxedPath[iItr]->fZ;

            fDist = PointDistanceToLine(pStart, pEnd, pAct);

            if (fDist > fMaxDist) {
                fMaxDist = fDist;
                iMaxItr = iItr;
            }
        }
        if (fMaxDist <= fMaxDistance) {
            lstAproxedPath->RemoveRange(iStartItr + 1, (iEndItr - iStartItr) - 1);
            return;
        }
        douglasPeuckerRecursive(iMaxItr, iEndItr, fMaxDistance);
        douglasPeuckerRecursive(iStartItr, iMaxItr, fMaxDistance);
        
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Approximieren der CSV:\n" + e->Message + "\n\n");
        return;
    }
}
float Logic::DPAprox::PointDistanceToLine(Projectdata::Point3D^ pStartPoint, Projectdata::Point3D^ pEndPoint, Projectdata::Point3D^ pActPoint) {
    try
    {
        float fBX, fBY, fBZ, fRV_SQ, fDist, fRVX, fRVY, fRVZ;

        fRVX = pStartPoint->fX - pEndPoint->fX;
        fRVY = pStartPoint->fY - pEndPoint->fY;
        fRVZ = pStartPoint->fZ - pEndPoint->fZ;

        fRV_SQ = fRVX * fRVX + fRVY * fRVY + fRVZ * fRVZ;

        fBX = pActPoint->fX - pStartPoint->fX;
        fBY = pActPoint->fY - pStartPoint->fY;
        fBZ = pActPoint->fZ - pStartPoint->fZ;

        fDist = static_cast<float>(System::Math::Abs((fBX * (fRVY * fRVZ) - fBY * (fRVX * fRVZ) + fBZ * (fRVX * fRVY))) / System::Math::Sqrt(fRV_SQ));
        
        return fDist;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Approximieren der CSV:\n" + e->Message + "\n\n");
        return -1;
    }
}
