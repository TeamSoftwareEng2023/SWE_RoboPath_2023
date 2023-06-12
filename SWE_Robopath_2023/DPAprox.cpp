#include "pch.h"
#include "DPAprox.h"
//Konstruktor
Logic::DPAprox::DPAprox(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Funktion, initialen Aufruf des DouglasPeucker Algo
System::Boolean Logic::DPAprox::approx(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Boolsche Variable, um den erfolgreichen Dirchlauf widerzuspiegeln
        System::Boolean bApproxDone = false;
        //Eingelesene Daten werden geholt
        lstAproxedPath = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstFilteredPathData());
        //Aufruf der Approximation
        bApproxDone = douglasPeuckerRecursive(0, lstAproxedPath->Count-1, RoboPathData->GetToleranceApprox());
        //Wenn die Approximation erfolgreich durchgelaufen ist, wird die Liste gespeichert und eine entsprechende Meldung wird im Log ausgegeben
        if (bApproxDone) {
            RoboPathData->SetlstAproxedPathData(lstAproxedPath);
            UIControl->AppendLog("Daten wurden erfolgreich approximiert\n" + lstAproxedPath->Count.ToString() + " Datensätze verbleibend\n\n");
            return true;
        }
        //Falls es ein Fehler gab. Die Fehlermeldung wurde in der vorher durchlaufene Funktion ausgegeben
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
        //Erstellung Start-, End- und aktueller Punkt
        Projectdata::Point3D^ pStart = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pEnd = gcnew Projectdata::Point3D();
        Projectdata::Point3D^ pAct = gcnew Projectdata::Point3D();
        //Varibalen um die aktuell errechnete Distanz und die bislang maximale Distanz zu speichern
        System::Double dDist = 0, dMaxDist = 0;
        //Speichern des Listeneintrags mit der maximalsten Distanz
        int iMaxItr = 0;
        //Bleibt true, solange es keinen Fehler bei der Distanzberechnung gab (Lotfußpunktverfahren)
        System::Boolean bCalcDone = true;

        //Wenn in der Liste nur 3 Punkte sind, wird die Funktion verlassen
        if (lstAproxedPath->Count < 3) {
            return true;
        }
        //Wenn Zwischen Anfangs- und Endpunkt keine anderen Punkte mehr sind, wird die Funktion verlassen
        if (System::Math::Abs(iEndItr - iStartItr) == 1) {
            return true;
        }
        //Einlesen des Startpunkts
        pStart->dX = lstAproxedPath[iStartItr]->dX;
        pStart->dY = lstAproxedPath[iStartItr]->dY;
        pStart->dZ = lstAproxedPath[iStartItr]->dZ;

        //Einlesen des Endpunkts
        pEnd->dX = lstAproxedPath[iEndItr]->dX;
        pEnd->dY = lstAproxedPath[iEndItr]->dY;
        pEnd->dZ = lstAproxedPath[iEndItr]->dZ;

        //Es werden alle Punkte zwischen Start- und Endpunkt durchlaufen und deren Distanz zur Geraden, die der Start- und Endpunkt bildet, berechnet
        for (int iItr = iStartItr + 1; iItr != iEndItr; iItr++) {

            //Einlesen des aktuellen Punkts zwischen Start- und Endpunkt
            pAct->dX = lstAproxedPath[iItr]->dX;
            pAct->dY = lstAproxedPath[iItr]->dY;
            pAct->dZ = lstAproxedPath[iItr]->dZ;

            //Berechnung Distanz von Punkt zur Geraden
            dDist = PointDistanceToLine(pStart, pEnd, pAct);
            //Falls bei der Berechnung was schief gelaufen ist, wird -1 zurückgegeben.
            //Damit werden alle Funktionsaufrufe dieser Funktion verlassen und das Programm abgebrochen
            if (dDist == -1) {
                return false;
            }

            //Falls die eben berechnete Distanz größer als die bisher größte Distanz ist, wird diese ersetzt
            if (dDist > dMaxDist) {
                dMaxDist = dDist;
                iMaxItr = iItr;
            }
        }
        //Nach dem Durchlauif wird geprüft, ob die errechnete maximale Distanz kleiner als die Toleranz ist.
        //Falls ja, werden die Punkte zwischen Start- und Endpunkt gelöscht und der Funktionsaufruf verlassen
        if (dMaxDist <= fMaxDistance) {
            lstAproxedPath->RemoveRange(iStartItr + 1, (iEndItr - iStartItr) - 1);
            return true;
        }
        //Rekursiver Aufruf des Douglas Peucker Algo. Startpunkt ist der Punkt mit der maximalsten Distanz
        bCalcDone = douglasPeuckerRecursive(iMaxItr, iEndItr, fMaxDistance);
        //Falls bei der Berechnung was schief gelaufen ist, wird -1 zurückgegeben.
        //Damit werden alle Funktionsaufrufe dieser Funktion verlassen und das Programm abgebrochen
        if (!bCalcDone) {
            return false;
        }
        //Rekursiver Aufruf des Douglas Peucker Algo. Endpunkt ist der Punkt mit der maximalsten Distanz
        bCalcDone = douglasPeuckerRecursive(iStartItr, iMaxItr, fMaxDistance);
        //Falls bei der Berechnung was schief gelaufen ist, wird -1 zurückgegeben.
        //Damit werden alle Funktionsaufrufe dieser Funktion verlassen und das Programm abgebrochen
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
        //Berechnung Distanz Punkt zu Geraden in einem dreidimensionalen Koordinatensystem (Lotfußpunktverfahren)
        System::Double dBX, dBY, dBZ, dDist, dCrossProductX, dCrossProductY, dCrossProductZ, dScalarA, dScalarB, dRVX, dRVY, dRVZ;
        //Richtungsvektor zum Endpunkt ermitteln
        dRVX = pEndPoint->dX - pStartPoint->dX;
        dRVY = pEndPoint->dY - pStartPoint->dY;
        dRVZ = pEndPoint->dZ - pStartPoint->dZ;
        //Richtungsvektor zum aktuellen Punkt ermnitteln
        dBX = pActPoint->dX - pStartPoint->dX;
        dBY = pActPoint->dY - pStartPoint->dY;
        dBZ = pActPoint->dZ - pStartPoint->dZ;
        //Kreuzprodukt
        dCrossProductX = dRVY * dBZ - dRVZ * dBY;
        dCrossProductY = dRVZ * dBX - dRVX * dBZ;
        dCrossProductZ = dRVX * dBY - dRVY * dBX;
        //Skalare Größe
        dScalarA = System::Math::Sqrt(dCrossProductX * dCrossProductX + dCrossProductY * dCrossProductY + dCrossProductZ * dCrossProductZ);

        dScalarB = System::Math::Sqrt(dRVX * dRVX + dRVY * dRVY + dRVZ * dRVZ);
        //Distanz
        dDist = dScalarA / dScalarB;

        return dDist;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler bei dem Lotpunktfußverfahren:\n" + e->Message + "\n\n");
        return -1;
    }
}

