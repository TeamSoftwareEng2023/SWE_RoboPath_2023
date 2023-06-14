#include "pch.h"
#include "ReadCSV.h"
//Konstruktor
Logic::ReadCSV::ReadCSV(UserInterface::RoboPathForm^ UI) {
    lstCSV = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
    UIControl = UI;
}

System::Boolean Logic::ReadCSV::ReadAndSaveCSV(Projectdata::RoboPath^ RoboPathData)
{
    //Streamreader mit dem Pfad der CSV initialisieren
    System::IO::StreamReader^ srReader = gcnew System::IO::StreamReader(RoboPathData->GetFilePath());
    //Hilfsstring zum auslesen der Datei
    System::String^ sLine;
    try
    {
        //Hier wird die die CSV validiert. Bei einem Fehler wird der Programmdurchlauf abgebrochen
        UIControl->AppendLog("Datei wird validiert\n\n");
        System::Threading::Thread::Sleep(500);
        Logic::ValidateRawCSV^ Validater = gcnew Logic::ValidateRawCSV(UIControl);
        if (!Validater->ValidateCSV(srReader)) {
            return false;
        }
        delete Validater;
        srReader->Close();
        srReader = gcnew System::IO::StreamReader(RoboPathData->GetFilePath());
        //Solange noch eine Zeile da ist, wird weitergelesen
        while ((sLine = srReader->ReadLine()) != nullptr)
        {
            //Zeile wird im Leerzeichen gesplittet und in einem string array gespeichert
            array<System::String^>^ sValues = sLine->Split(' ');
            //Struktur zum Speichern der Werte
            Projectdata::RoboPathStruct<System::Double>^ strctRoboPathWerte = gcnew Projectdata::RoboPathStruct<System::Double>();
            //Zählt die Werte pro Zeile
            int i = 0;
            //Alle Werte in de string array werden ausgelesen und in der Struktur gespeichert
            for each (System::String ^ sValue in sValues)
            {
                //Eine gültige Gleitkommezahl wird mit einem Komma getrennt. Wenn Die zahl ein Punkt beinhaltet,
                //wird dieser durch ein Komma ersetzt
                if (sValue->Contains(".")) {
                    sValue = sValue->Replace(".", ",");
                }
                switch (i)
                {
                    //Je nachdem bei welcher Zahl die variable "i" ist, wird der Wert in die entsprechende Strutktur gespeichert
                    //Zeitstempel
                case 0:
                    strctRoboPathWerte->dTimestamp = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //X
                case 1:
                    strctRoboPathWerte->dX = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Y
                case 2:
                    strctRoboPathWerte->dY = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Z
                case 3:
                    strctRoboPathWerte->dZ = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Xx
                case 4:
                    strctRoboPathWerte->dXx = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Xy
                case 5:
                    strctRoboPathWerte->dXy = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Xz
                case 6:
                    strctRoboPathWerte->dXz = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Yx
                case 7:
                    strctRoboPathWerte->dYx = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Yy
                case 8:
                    strctRoboPathWerte->dYy = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Yz
                case 9:
                    strctRoboPathWerte->dYz = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Zx
                case 10:
                    strctRoboPathWerte->dZx = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Zy
                case 11:
                    strctRoboPathWerte->dZy = System::Double::Parse(sValue);
                    i++;
                    continue;
                    //Zz
                case 12:
                    strctRoboPathWerte->dZz = System::Double::Parse(sValue);
                    i++;
                    continue;
                default:
                    break;
                }
            }
            //Nach dem Einlesen eines Datensatzes, wird dieser Datensatz in der Liste gespeichert
            lstCSV->Add(strctRoboPathWerte);
        }
        //Nach dem gesamten Durchlauf wird die Liste gespeichert und eine Meldung im Log ausgegeben
        RoboPathData->SetlstRawPathData(lstCSV);
        UIControl->AppendLog("CSV wurde mit " + lstCSV->Count.ToString() + " Datensätzen eingelesen\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Einlesen der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}