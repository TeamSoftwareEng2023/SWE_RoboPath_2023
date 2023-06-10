#include "pch.h"
#include "WriteCSV.h"

Logic::WriteCSV::WriteCSV(UserInterface::RoboPathForm^ UI) {
    lstFileForMatLab = gcnew System::Collections::Generic::List<System::String^>();
    UIControl = UI;
}
void Logic::WriteCSV::WriteForMatLab(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstFinalRoboPathCode = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>(RoboPathData->GetlstAproxedPathData());
        UIControl->saveFileDialog_CSV->ShowDialog();
        System::IO::StreamWriter^ srWriter = gcnew System::IO::StreamWriter(RoboPathData->GetSavePath());

        for (int i = 0; i < lstFinalRoboPathCode->Count; i++) {
            lstFileForMatLab->Add(lstFinalRoboPathCode[i]->fX.ToString() + " " + lstFinalRoboPathCode[i]->fY.ToString() + " " + lstFinalRoboPathCode[i]->fZ.ToString());
        }
        for each (System::String^ sLine in lstFileForMatLab)
        {
            srWriter->WriteLine(sLine);
        }
        srWriter->Close();
    }
    catch (const std::exception&)
    {

    }
}