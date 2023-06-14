#include "pch.h"
#include "CalcOrientation.h"
//Konstruktor
Logic::CalcOrientation::CalcOrientation(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Berechnung von Transformationmatrix zu eulersche Winkel A, B und C
System::Boolean Logic::CalcOrientation::CalcRotMatToEulerABC(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Nuterdefinierte Toleranz wird geholt
        System::Double dTolerance = RoboPathData->GetToleranceOrientation();
        //Die Erste Orientierung soll immer übernommen werden
        System::Boolean bSetFirstValuesAlways = true;
        //Datensätze werden eingeholt
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstApproxedData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstAproxedPathData());
        //Liste wird durchlaufen und von jedem Datensatz wird die Rotationsmatrix in eulersche Winkel umgerechnet
        for (int i = 0; i < lstApproxedData->Count; i++) {
            System::Double dM11, dM12, dM13, dM21, dM22, dM23, dM31, dM32, dM33, dA, dB, dC, dA_Act, dB_Act, dC_Act;

            //Matrizenwerte aus den Datensätzen übergeben
            dM11 = lstApproxedData[i]->dXx;
            dM12 = lstApproxedData[i]->dXy;
            dM13 = lstApproxedData[i]->dXz;
            dM21 = lstApproxedData[i]->dYx;
            dM22 = lstApproxedData[i]->dYy;
            dM23 = lstApproxedData[i]->dYz;
            dM31 = lstApproxedData[i]->dZx;
            dM32 = lstApproxedData[i]->dZy;
            dM33 = lstApproxedData[i]->dZz;

            //Sonderabfrage bei bestimmten Bedingungen
            if (dM31 == 1) {
                dA_Act = System::Math::Atan(-dM12 / -dM13) * (180 / System::Math::PI);
                dB_Act = System::Math::Asin(dM31) * (-1) * (180 / System::Math::PI);
                dC_Act = 0;
            }
            else if (dM31 == -1) {
                dA_Act = System::Math::Atan(dM12 / dM13) * (180 / System::Math::PI);
                dB_Act = System::Math::Asin(dM31) * (-1) * (180 / System::Math::PI);
                dC_Act = 0;
            }
            //Allgemeines Lösungsverfahren
            else {
                dA_Act = System::Math::Atan(dM32 / dM33) * (180 / System::Math::PI);
                dB_Act = System::Math::Asin(dM31) * (-1) * (180 / System::Math::PI);
                dC_Act = System::Math::Atan(dM21 / dM11) * (180 / System::Math::PI);
            }
            //Die ersten Werte werden immer übernommen
            if (bSetFirstValuesAlways) {
                dA = dA_Act;
                dB = dB_Act;
                dC = dC_Act;
                bSetFirstValuesAlways = false;
            }
            //Wenn die Differenz zur letzten Orientierung größer als die Toleranz ist, wird die neue Orientierung übernommen und gespeichert
            if (System::Math::Abs(dA - dA_Act) > dTolerance
                || System::Math::Abs(dB - dB_Act) > dTolerance
                || System::Math::Abs(dC - dC_Act) > dTolerance) {
                
                //Neue Werte speichern
                dA = dA_Act;
                dB = dB_Act;
                dC = dC_Act;
            }
            //Orientierung in Datensatz aufnehmen
            lstApproxedData[i]->dA = dA;
            lstApproxedData[i]->dB = dB;
            lstApproxedData[i]->dC = dC;
        }
        //Speichern der Liste und Ausgabe im Log
        RoboPathData->SetlstAproxedPathData(lstApproxedData);
        UIControl->AppendLog("Orientierung wurde berechnet\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Berechnen der Orientierung aus der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}