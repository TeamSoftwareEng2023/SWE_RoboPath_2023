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
            //Solange noch eine Zeile da ist, wird weitergelesen
            while ((sLine = srCSV->ReadLine()) != nullptr) {
                iLineCount++;
                //Zeile wird im Leerzeichen gesplittet und in einem string array gespeichert
                array<System::String^>^ sValues = sLine->Split(' ');
            }

        }
        //Falls die Datei mit dem StreamReader nicht gelesen werden kann, kann das unterschiedliche Gr�nde haben
        //Z.B. ist die Datei schreibgesch�tzt odfer wurde zwischen dem Ausw�hlen und dem Start des Programms gel�scht oder verschoben
        else
        {
            UIControl->AppendLog("Fehler!\nDie Datei l�sst sich nicht �ffnen.\nPr�fen Sie, bo die Datei verschoben worden oder schreibgesch�tzt ist\n\n");
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