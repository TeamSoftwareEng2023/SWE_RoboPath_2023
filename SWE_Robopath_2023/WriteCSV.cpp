#include "pch.h"
#include "WriteCSV.h"
//Konstruktor
Logic::WriteCSV::WriteCSV(UserInterface::RoboPathForm^ UI) {
    lstFileForMatLab = gcnew System::Collections::Generic::List<System::String^>();
    UIControl = UI;
}
//Funktion zum Erzeugen und SPeichern einer Textdatei
void Logic::WriteCSV::WriteForMatLab(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        //Liste mit den bearbeiteten Datensätzen wird geladen
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFinalRoboPathCode = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstAproxedPathData());
        //Ein saveFileDialog öffnet sich, dass den Benutzer auffordert den SPeicherort und einen Dateinamen auszuwählen
        UIControl->saveFileDialog_CSV->ShowDialog();
        //Initialisierung einen StreamWriters mit dem eben bestimmten Speicherpfad durch den Nutzer
        System::IO::StreamWriter^ srWriter = gcnew System::IO::StreamWriter(RoboPathData->GetSavePath());
        //Die Daten werden in die erforderliche Form gebracht
        for (int i = 0; i < lstFinalRoboPathCode->Count; i++) {
            lstFileForMatLab->Add(lstFinalRoboPathCode[i]->dX.ToString()->Replace(",",".") + " " + lstFinalRoboPathCode[i]->dY.ToString()->Replace(",", ".") + " " + lstFinalRoboPathCode[i]->dZ.ToString()->Replace(",", "."));
        }
        //Datensätze werden geschrieben
        for each (System::String^ sLine in lstFileForMatLab)
        {
            srWriter->WriteLine(sLine);
        }
        //Writer wird geschlossen und eine entsprechende Meldung im Log ausgegeben
        srWriter->Close();
        UIControl->AppendLog("Datei wurde unter " + RoboPathData->GetSavePath() + " gespeichert\n\n");
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Schreiben der CSV:\n" + e->Message + "\n\n");
        return;
    }
}