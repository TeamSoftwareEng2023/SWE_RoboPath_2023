#include "pch.h"
#include "ValidateRawCSV.h"

//Konstruktor
Logic::ValidateRawCSV::ValidateRawCSV(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
//Funktion um die zu einlesende CSV zu validieren
System::Boolean Logic::ValidateRawCSV::ValidateCSV(System::IO::StreamReader^ srCSV) {
    try
    {
        //Pr�fen, ob die Datei ge�ffnet werden k�nnte
        if (!srCSV->EndOfStream) {
            System::String^ sLine;
            //Z�hlen der Zeilennumer
            int iLineCount = 0;
            System::Double dLastTime = 0;
            System::Double dActVal = 0;
            //Solange noch eine Zeile da ist, wird weitergelesen
            while ((sLine = srCSV->ReadLine()) != nullptr) {
                iLineCount++;
                //Zeile wird im Leerzeichen gesplittet und in einem string array gespeichert
                array<System::String^>^ sValues = sLine->Split(' ');
                //Pr�fen, ob zu wenige oder zu viele Werte in einer Zeile sind
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
                //Z�hlt die Werte
                int iValueCount = 0;
                //Alle Werte in de string array werden durchlaufen
                for each (System::String ^ sValue in sValues) {
                    //Wert wird hochgez�hlt
                    iValueCount++;
                    //Eine g�ltige Gleitkommezahl wird mit einem Komma getrennt. Wenn die Zahl ein Punkt beinhaltet,
                    //wird dieser durch ein Komma ersetzt
                    if (sValue->Contains(".")) {
                        sValue = sValue->Replace(".", ",");
                    }
                    //Es wird gepr�ft, ob er aktuelle Wert in ein Double konvertiert werden kann
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
                            UIControl->AppendLog("In Zeile " + iLineCount.ToString() + " ist der Zeitstempel (Wert "+ iValueCount.ToString() + ") kleiner als der Vorherige\n\n");
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
        }
        //Falls die Datei mit dem StreamReader nicht gelesen werden kann, kann das unterschiedliche Gr�nde haben
        //Z.B. ist die Datei schreibgesch�tzt odfer wurde zwischen dem Ausw�hlen und dem Start des Programms gel�scht oder verschoben
        else
        {
            UIControl->AppendLog("Fehler!\nDie Datei l�sst sich nicht �ffnen.\nPr�fen Sie, ob die Datei verschoben worden, gel�scht oder schreibgesch�tzt ist\n\n");
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
        UIControl->AppendLog("In Zeile " + iLineNumber.ToString() + " ist " + sAxisname + " (Wert " + iValueNumber.ToString() + ") au�erhalb des g�ltigen Bereichs.\nMinimal - 1 und maximal + 1\n\n");
        return false;
    }
    return true;
}