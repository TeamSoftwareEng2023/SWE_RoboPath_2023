#include "pch.h"
#include "CreateKUKAFile.h"
#include"cmath"

//Konstruktor
Logic::CreateKUKAFile::CreateKUKAFile(UserInterface::RoboPathForm^ UI) {
    lstKUKAFile = gcnew System::Collections::Generic::List<System::String^>();
    UIControl = UI;
}
void Logic::CreateKUKAFile::WriteKUKA(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        System::String^ sLineBuilder = "";
        //Liste mit den bearbeiteten Datensätzen wird geladen
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFinalRoboPathCode = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstAproxedPathData());
        //Ein saveFileDialog öffnet sich, dass den Benutzer auffordert den SPeicherort und einen Dateinamen auszuwählen
        UIControl->saveFileDialog_CSV->ShowDialog();
        if (RoboPathData->GetSavePath() != "") {
            //Daraus wird der benutzerdefinierte Filename extrahiert
            System::String^ sFileName = RoboPathData->GetSavePath();
            sFileName = sFileName->Remove(0, sFileName->LastIndexOf("\\") + 1);
            sFileName = sFileName->Remove(sFileName->LastIndexOf("."));
            //Initialisierung einen StreamWriters mit dem eben bestimmten Speicherpfad durch den Nutzer
            System::IO::StreamWriter^ srWriter = gcnew System::IO::StreamWriter(RoboPathData->GetSavePath());
            //Die Daten werden in die erforderliche Form gebracht
            lstKUKAFile->Add("DEF " + sFileName);
            lstKUKAFile->Add("PTP $POS_ACT");
            //Da in der KUKA Syntax Punkte anstatt Kommas benutzt werden, werden Kommas in Punkte umgewandelt
            for (int iListCursor = 0; iListCursor < lstFinalRoboPathCode->Count; iListCursor++) {
                sLineBuilder = "LIN {X "
                    + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dX)->Replace(",", ".")
                    + ", Y "
                    + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dY)->Replace(",", ".")
                    + ", Z "
                    + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dZ)->Replace(",", ".");
                if (RoboPathData->GetUserDefOrientation()) {
                    sLineBuilder = sLineBuilder
                        + ", A "
                        + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dA)->Replace(",", ".")
                        + ", B "
                        + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dB)->Replace(",", ".")
                        + ", C "
                        + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dC)->Replace(",", ".")
                        + "}";
                }
                else {
                    sLineBuilder = sLineBuilder
                        + ", A "
                        + RoboPathData->GetOrientationA().ToString()->Replace(",", ".")
                        + ", B "
                        + RoboPathData->GetOrientationB().ToString()->Replace(",", ".")
                        + ", C "
                        + RoboPathData->GetOrientationC().ToString()->Replace(",", ".")
                        + "}";
                }
                lstKUKAFile->Add(sLineBuilder);
                if (iListCursor != lstFinalRoboPathCode->Count - 1) {
                    if (RoboPathData->GetUserDefVelo()) {
                        lstKUKAFile->Add("$VEL.CP=" + RoundBasedOnThirdDecimalPlace(lstFinalRoboPathCode[iListCursor]->dVelo)->Replace(",", "."));
                    }
                    else {
                        lstKUKAFile->Add("$VEL.CP=" + RoboPathData->GetVelo().ToString()->Replace(",", "."));
                    }
                }
            }
            lstKUKAFile->Add("END");
            //Datensätze werden geschrieben
            for each (System::String ^ sLine in lstKUKAFile)
            {
                srWriter->WriteLine(sLine);
            }
            //Writer wird geschlossen und eine entsprechende Meldung im Log ausgegeben
            srWriter->Close();
            UIControl->AppendLog("Datei wurde unter " + RoboPathData->GetSavePath() + " gespeichert\n\n");
        }
        else {
            UIControl->ShowErrorWindow("Kein Dateiname angegeben oder Vorgang abgebrochen.\nSystem wird zurückgesetzt.");
            UIControl->AppendLog("Kein Dateiname angegeben oder Vorgang abgebrochen.\nSystem wird zurückgesetzt.\n\n");
            return;
        }
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Erstellen des KUKA files:\n" + e->Message + "\n\n");
        return;
    }
}
//Funktion um eine Zahl auf ihre zweite Stelle nach dem Komma zu runden
System::String^ Logic::CreateKUKAFile::RoundBasedOnThirdDecimalPlace(System::Double dValue) {
    dValue = dValue * 1000;
    System::Double dTest = 1;
    System::Double dRoundedValue = fmod(dValue, dTest);
    System::String^ sRoundedValue;

    if (dRoundedValue < 5) {
        dValue = System::Math::Floor(dValue) / 1000;
        sRoundedValue = dValue.ToString();
        return sRoundedValue;
    }
    else {
        dValue = System::Math::Ceiling(dRoundedValue) / 100;
        sRoundedValue = dValue.ToString();
        return sRoundedValue;
    }
}