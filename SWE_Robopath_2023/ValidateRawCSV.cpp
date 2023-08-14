#include "pch.h"
#include "ValidateRawCSV.h"

//Konstruktor
Logic::ValidateRawCSV::ValidateRawCSV(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Funktion um die zu einlesende CSV zu validieren
System::Boolean Logic::ValidateRawCSV::ValidateCSV(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Streamreader mit dem Pfad der CSV initialisieren. Falls die Datei verschoben oder gelöscht worden ist, wird
        //hier eine exception geworfen
        System::IO::StreamReader^ srReader = gcnew System::IO::StreamReader(RoboPathData->GetFilePath());
        System::String^ sLine;
        //Zählen der Zeilennumer
        int iLineCount = 0;
        System::Double dLastTime = 0;
        System::Double dActVal = 0;
        //Solange noch eine Zeile da ist, wird weitergelesen
        while ((sLine = srReader->ReadLine()) != nullptr) {
            iLineCount++;
            //Zeile wird im Leerzeichen gesplittet und in einem string array gespeichert
            array<System::String^>^ sValues = sLine->Split(' ');
            //Prüfen, ob zu wenige oder zu viele Werte in einer Zeile sind
            if (sValues->Length != 13) {
                if (sValues->Length < 13) {
                    UIControl->AppendLog("In Zeile " + iLineCount.ToString() + " sind zu wenige Werte oder Leerzeichen\n\n");
                    return false;
                }
                else if (sValues->Length > 13) {
                    UIControl->AppendLog("In Zeile " + iLineCount.ToString() + " sind zu viele Werte oder Leerzeichen\n\n");
                    return false;
                }
            }
            //Zählt die Werte
            int iValueCount = 0;
            //Alle Werte in de string array werden durchlaufen
            for each (System::String ^ sValue in sValues) {
                //Wert wird hochgezählt
                iValueCount++;
                //Eine gültige Gleitkommazahl wird mit einem Komma getrennt. Wenn die Zahl ein Punkt beinhaltet,
                //wird dieser durch ein Komma ersetzt
                if (sValue->Contains(".")) {
                    sValue = sValue->Replace(".", ",");
                }
                //Es wird geprüft, ob der aktuelle Wert in ein Double konvertiert werden kann
                if (System::Double::TryParse(sValue, dActVal)) {
                    dActVal = System::Double::Parse(sValue);
                }
                else {
                    UIControl->AppendLog("In Zeile " + iLineCount.ToString() + " ist der Wert " + iValueCount.ToString() + " fehlerhaft\n\n");
                    return false;
                }
                switch (iValueCount)
                {
                    //Zeitstempel
                case 1:
                    if (dActVal > dLastTime) {
                        dLastTime = dActVal;
                    }
                    else {
                        UIControl->AppendLog("In Zeile " + iLineCount.ToString() + " ist der Zeitstempel (Wert " + iValueCount.ToString() + ") kleiner als der Vorherige\n\n");
                        return false;
                    }
                    continue;
                    //X
                case 2:
                    continue;
                    //Y
                case 3:
                    continue;
                    //Z
                case 4:
                    continue;
                    //Xx
                case 5:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Xx")) {
                        return false;
                    }
                    continue;
                    //Xy
                case 6:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Xy")) {
                        return false;
                    }
                    continue;
                    //Xz
                case 7:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Xz")) {
                        return false;
                    }
                    continue;
                    //Yx
                case 8:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Yx")) {
                        return false;
                    }
                    continue;
                    //Yy
                case 9:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Yy")) {
                        return false;
                    }
                    continue;
                    //Yz
                case 10:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Yz")) {
                        return false;
                    }
                    continue;
                    //Zx
                case 11:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Zx")) {
                        return false;
                    }
                    continue;
                    //Zy
                case 12:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Zy")) {
                        return false;
                    }
                    continue;
                    //Zz
                case 13:
                    if (!CheckValueRotMat(dActVal, iLineCount, iValueCount, "Zz")) {
                        return false;
                    }
                    continue;
                default:
                    break;
                }
            }
        }
        if (iLineCount <= 1) {
            UIControl->AppendLog("Die CSV besteht nur aus einem Datensatz oder weniger\n\n");
            return false;
        }
        UIControl->AppendLog("Die CSV wurde erfolgreich validiert\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Validieren der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}
System::Boolean Logic::ValidateRawCSV::CheckValueRotMat(System::Double dActValue, int iLineNumber, int iValueNumber, System::String^ sAxisname) {
    if (dActValue < -1 || dActValue > 1) {
        UIControl->AppendLog("In Zeile " + iLineNumber.ToString() + " ist " + sAxisname + " (Wert " + iValueNumber.ToString() + ") außerhalb des gültigen Bereichs.\nMinimal - 1 und maximal + 1\n\n");
        return false;
    }
    return true;
}