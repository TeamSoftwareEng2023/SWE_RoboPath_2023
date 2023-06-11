#include "pch.h"
#include "WriteCSV.h"

Logic::WriteCSV::WriteCSV(UserInterface::RoboPathForm^ UI) {
    lstFileForMatLab = gcnew System::Collections::Generic::List<System::String^>();
    UIControl = UI;
}
void Logic::WriteCSV::WriteForMatLab(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFinalRoboPathCode = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstAproxedPathData());
        UIControl->saveFileDialog_CSV->ShowDialog();
        System::IO::StreamWriter^ srWriter = gcnew System::IO::StreamWriter(RoboPathData->GetSavePath());

        for (int i = 0; i < lstFinalRoboPathCode->Count; i++) {
            lstFileForMatLab->Add(lstFinalRoboPathCode[i]->dX.ToString()->Replace(",",".") + " " + lstFinalRoboPathCode[i]->dY.ToString()->Replace(",", ".") + " " + lstFinalRoboPathCode[i]->dZ.ToString()->Replace(",", "."));
        }
        for each (System::String^ sLine in lstFileForMatLab)
        {
            srWriter->WriteLine(sLine);
        }
        srWriter->Close();
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Schreiben der CSV:\n" + e->Message + "\n\n");
        return;
    }
}