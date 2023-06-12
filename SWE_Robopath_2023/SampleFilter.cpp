#include "pch.h"
#include "SampleFilter.h"
//Konstruktor
Logic::SampleFilter::SampleFilter(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Funktion um die Datensätze über eine nutzerdefinierte Anzahl zu mitteln
System::Boolean Logic::SampleFilter::FilterData(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Diese Variable zählt die bereits summierten Datensätze
        int iCount = 0;
        //Nutzerdefinierte Anzahl wird geholt
        System::Double iSampleCount = RoboPathData->GetSampleSize();
        //Es soll einmal am Anfang des Zyklus gecheckt werden, ob die verbleibende Anzahl an Datensätzen noch für eine Mittelwertbildung ausreicht
        bool bCheckOncePerCycle = true;
        //Leere Strutkur zur Summierung der Datensätze
        Projectdata::RoboPathStruct<System::Double>^ rpsSumSamples = gcnew Projectdata::RoboPathStruct<System::Double>();
        //Liste mit Datensätze wird geholt
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstRawData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstRawPathData());
        //Leere Liste zum Speichern der gemittelten Datensätze wird erstellt
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFilteredData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
        //Der Anfangswert soll nicht mit in die Mittelwertbildung einbezogen werden und wird deshalb gleich in die neue Liste übergeben
        lstFilteredData->Add(lstRawData[0]);

        //Durchlauf aller Daten
        for (int i = 1; i < lstRawData->Count-1; i++) {

            //Wenn die verbleibende Menge an Daten kleiner als der SampleCount ist, wird der SampleCount auf die restliche ANzahl reduziert
            if (i + iSampleCount > lstRawData->Count - 2 && bCheckOncePerCycle) {
                iSampleCount = (lstRawData->Count - i) - 1;
            }
            //Damit die obige if Abfrage nur einmal am Anfang des Zyklus abgefragt wird
            bCheckOncePerCycle = false;

            //Kumlierte Summierung der Datensätze
            rpsSumSamples->dTimestamp += lstRawData[i]->dTimestamp;
            rpsSumSamples->dX += lstRawData[i]->dX;
            rpsSumSamples->dY += lstRawData[i]->dY;
            rpsSumSamples->dZ += lstRawData[i]->dZ;
            rpsSumSamples->dXx += lstRawData[i]->dXx;
            rpsSumSamples->dXy += lstRawData[i]->dXy;
            rpsSumSamples->dXz += lstRawData[i]->dXz;
            rpsSumSamples->dYx += lstRawData[i]->dYx;
            rpsSumSamples->dYy += lstRawData[i]->dYy;
            rpsSumSamples->dYz += lstRawData[i]->dYz;
            rpsSumSamples->dZx += lstRawData[i]->dZx;
            rpsSumSamples->dZy += lstRawData[i]->dZy;
            rpsSumSamples->dZz += lstRawData[i]->dZz;
            iCount++;

            //Wenn soviele Datensätze eingelesen worden sind, wie der Benutzer festgelegt hat, wird die Summe durch die Anzahl geteilt
            //Daraus entsteht ein neuer gemittelter Datensatz
            if (iCount == iSampleCount) {
                rpsSumSamples->dTimestamp /= iSampleCount;
                rpsSumSamples->dX /= iSampleCount;
                rpsSumSamples->dY /= iSampleCount;
                rpsSumSamples->dZ /= iSampleCount;
                rpsSumSamples->dXx /= iSampleCount;
                rpsSumSamples->dXy /= iSampleCount;
                rpsSumSamples->dXz /= iSampleCount;
                rpsSumSamples->dYx /= iSampleCount;
                rpsSumSamples->dYy /= iSampleCount;
                rpsSumSamples->dYz /= iSampleCount;
                rpsSumSamples->dZx /= iSampleCount;
                rpsSumSamples->dZy /= iSampleCount;
                rpsSumSamples->dZz /= iSampleCount;
                //Datensatz wird in der neuen Liste übergeben
                lstFilteredData->Add(rpsSumSamples);
                //Die Zählervariable wird danach zurück gesetzt
                iCount = 0;
                //Es wird eine neue Strutkur erstellt
                rpsSumSamples = gcnew Projectdata::RoboPathStruct<System::Double>();
                //Die Restmengenabfrage soll wieder gestartet werden
                bCheckOncePerCycle = true;
            }
        }
        //Der Endwert soll nicht mit in die Mittelwertbildung einbezogen werden und wird deshalb zum Schluss in die neue Liste übergeben
        lstFilteredData->Add(lstRawData[lstRawData->Count - 1]);
        //Neue Liste wird gespeichert und eine entsprechende Logmeldung wird ausgegeben
        RoboPathData->SetlstFilteredPathData(lstFilteredData);
        UIControl->AppendLog("Daten wurden gemittelt.\n" + lstFilteredData->Count.ToString() + " Datensätze verbleibend\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Filtern der Daten:\n" + e->Message + "\n\n");
        return false;
    }
}