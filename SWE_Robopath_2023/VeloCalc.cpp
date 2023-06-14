#include "pch.h"
#include "VeloCalc.h"
//Konstruktor
Logic::VeloCalc::VeloCalc(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Funktion zum Berechnen der Geschwindigkeit aus der CSV
System::Boolean Logic::VeloCalc::VeloCalcCSV(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Datensätze werden eingeholt
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstApproxedData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstAproxedPathData());
        //Liste wird von hinten nach vorne durchgegangen. Die Distanz zwischen Punkt i und Punkt i + 1 wird berechnet
        //Die Geschwindigkeit, die benötigt wird, um von einem Punkt zum Nächsten zu kommen, wird im Startpunkt gespeichert.
        for (int i = lstApproxedData->Count - 2; i >= 0; i--) {
            System::Double dDiffX, dDiffY, dDiffZ, dDiffTime, dDistance, dVelo;

            //Differenzen bilden
            dDiffX = lstApproxedData[i + 1]->dX - lstApproxedData[i]->dX;
            dDiffY = lstApproxedData[i + 1]->dY - lstApproxedData[i]->dY;
            dDiffZ = lstApproxedData[i + 1]->dZ - lstApproxedData[i]->dZ;
            dDiffTime = lstApproxedData[i + 1]->dTimestamp - lstApproxedData[i]->dTimestamp;

            //Distanz zwischen Punkten berechnen
            dDistance = System::Math::Sqrt(dDiffX * dDiffX + dDiffY * dDiffY + dDiffZ * dDiffZ);

            //Geschwindigkeit berechnen. Da die Zeitangabe in ms ist, muss mit 1000 multipliziert werden
            dVelo = (dDistance / dDiffTime);

            //Aufnahme in den Datensatz
            lstApproxedData[i]->dVelo = dVelo;
        }
        //Speichern der Liste und Ausgabe im Log
        RoboPathData->SetlstAproxedPathData(lstApproxedData);
        UIControl->AppendLog("Geschwindigkeiten wurden berechnet\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Berechnen der Geschwindigkeit aus der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}