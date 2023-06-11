#include "pch.h"
#include "DPAprox.h"

Logic::DPAprox::DPAprox(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
System::Boolean Logic::DPAprox::approx(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        System::Boolean bAporxDone = false;
        lstAproxedPath = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstFilteredPathData());
        bAporxDone = douglasPeuckerRecursive(0, lstAproxedPath->Count-1, RoboPathData->GetTolerance());
        if (bAporxDone) {
            RoboPathData->SetlstAproxedPathData(lstAproxedPath);
            UIControl->AppendLog("Daten wurden erfolgreich approximiert\n" + lstAproxedPath->Count.ToString() + " Datensätze verbleibend\n\n");
            return true;
        }
        else {
            return false;
        }
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Approximieren der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}
System::Boolean Logic::DPAprox::douglasPeuckerRecursive(int iStartItr, int iEndItr, System::Double fMaxDistance) {
    try
    {
        Projectdata::Point3D^ pStart = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pEnd = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pAct = gcnew Projectdata::Point3D();
        System::Double dDist = 0, dMaxDist = 0;
        System::Boolean bCalcDone = true;
        int iMaxItr = 0;

        if (lstAproxedPath->Count < 3) {
            return true;
        }
        if (System::Math::Abs(iEndItr - iStartItr) == 1) {
            return true;
        }
        pStart->dX = lstAproxedPath[iStartItr]->dX;
        pStart->dY = lstAproxedPath[iStartItr]->dY;
        pStart->dZ = lstAproxedPath[iStartItr]->dZ;

        pEnd->dX = lstAproxedPath[iEndItr]->dX;
        pEnd->dY = lstAproxedPath[iEndItr]->dY;
        pEnd->dZ = lstAproxedPath[iEndItr]->dZ;

        for (int iItr = iStartItr + 1; iItr != iEndItr; iItr++) {

            pAct->dX = lstAproxedPath[iItr]->dX;
            pAct->dY = lstAproxedPath[iItr]->dY;
            pAct->dZ = lstAproxedPath[iItr]->dZ;

            dDist = PointDistanceToLine(pStart, pEnd, pAct);
            if (dDist == -1) {
                return false;
            }

            if (dDist > dMaxDist) {
                dMaxDist = dDist;
                iMaxItr = iItr;
            }
        }
        if (dMaxDist <= fMaxDistance) {
            lstAproxedPath->RemoveRange(iStartItr + 1, (iEndItr - iStartItr) - 1);
            return true;
        }
        bCalcDone = douglasPeuckerRecursive(iMaxItr, iEndItr, fMaxDistance);
        if (!bCalcDone) {
            return false;
        }
        bCalcDone = douglasPeuckerRecursive(iStartItr, iMaxItr, fMaxDistance);
        if (!bCalcDone) {
            return false;
        }
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Approximieren der CSV:\n" + e->Message + "\n\n");
        return false;
    }
    return true;
}
System::Double Logic::DPAprox::PointDistanceToLine(Projectdata::Point3D^ pStartPoint, Projectdata::Point3D^ pEndPoint, Projectdata::Point3D^ pActPoint) {
    try
    {
        System::Double dBX, dBY, dBZ, dDist, dCrossProductX, dCrossProductY, dCrossProductZ, dScalarA, dScalarB, dRVX, dRVY, dRVZ;

        dRVX = pEndPoint->dX - pStartPoint->dX;
        dRVY = pEndPoint->dY - pStartPoint->dY;
        dRVZ = pEndPoint->dZ - pStartPoint->dZ;

        dBX = pActPoint->dX - pStartPoint->dX;
        dBY = pActPoint->dY - pStartPoint->dY;
        dBZ = pActPoint->dZ - pStartPoint->dZ;

        dCrossProductX = dRVY * dBZ - dRVZ * dBY;
        dCrossProductY = dRVZ * dBX - dRVX * dBZ;
        dCrossProductZ = dRVX * dBY - dRVY * dBX;

        dScalarA = System::Math::Sqrt(dCrossProductX * dCrossProductX + dCrossProductY * dCrossProductY + dCrossProductZ * dCrossProductZ);

        dScalarB = System::Math::Sqrt(dRVX * dRVX + dRVY * dRVY + dRVZ * dRVZ);

        dDist = dScalarA / dScalarB;

        return dDist;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler bei dem Lotpunktfußverfahren:\n" + e->Message + "\n\n");
        return -1;
    }
}

