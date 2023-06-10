#include "pch.h"
#include "ReadCSV.h"

Logic::ReadCSV::ReadCSV(UserInterface::RoboPathForm^ UI) {
    lstCSV = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>();
    UIControl = UI;
}

System::Void Logic::ReadCSV::ReadAndSaveCSV(Projectdata::RoboPath^ RoboPathData)
{
    System::IO::StreamReader^ srReader = gcnew System::IO::StreamReader(RoboPathData->GetFilePath());
    System::String^ sLine;
    try
    {
        //Prüfen, ob die Datei geöffnet werden könnte
        if (!srReader->EndOfStream)
        {
            while ((sLine = srReader->ReadLine()) != nullptr)
            {
                array<System::String^>^ Lines = sLine->Split(' ');
                Projectdata::RoboPathStruct<float>^ strctRoboPathWerte = gcnew Projectdata::RoboPathStruct<float>();
                int i = 0;
                for each (System::String^ sValue in Lines)
                {
                    if (sValue->Contains(".")) {
                        sValue = sValue->Replace(".", ",");
                    }
                    switch (i)
                    {
                    case 0:
                        strctRoboPathWerte->fTimestamp = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 1:
                        strctRoboPathWerte->fX = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 2:
                        strctRoboPathWerte->fY = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 3:
                        strctRoboPathWerte->fZ = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 4:
                        strctRoboPathWerte->fXx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 5:
                        strctRoboPathWerte->fXy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 6:
                        strctRoboPathWerte->fXz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 7:
                        strctRoboPathWerte->fYx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 8:
                        strctRoboPathWerte->fYy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 9:
                        strctRoboPathWerte->fYz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 10:
                        strctRoboPathWerte->fZx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 11:
                        strctRoboPathWerte->fZy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 12:
                        strctRoboPathWerte->fZz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    default:
                        break;
                    }
                }
                lstCSV->Add(strctRoboPathWerte);
            }
            RoboPathData->SetlstRawPathData(lstCSV);
            UIControl->AppendLog("CSV wurde eingelesen\n\n");
            System::Threading::Thread::Sleep(1000);
            return;
        }
        else
        {
            return;
        }
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Einlesen der CSV:\n" + e->Message + "\n\n");
        return;
    }
}