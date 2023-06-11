#include "pch.h"
#include "ReadCSV.h"

Logic::ReadCSV::ReadCSV(UserInterface::RoboPathForm^ UI) {
    lstCSV = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
    UIControl = UI;
}

System::Boolean Logic::ReadCSV::ReadAndSaveCSV(Projectdata::RoboPath^ RoboPathData)
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
                Projectdata::RoboPathStruct<System::Double>^ strctRoboPathWerte = gcnew Projectdata::RoboPathStruct<System::Double>();
                int i = 0;
                for each (System::String^ sValue in Lines)
                {
                    if (sValue->Contains(".")) {
                        sValue = sValue->Replace(".", ",");
                    }
                    switch (i)
                    {
                    case 0:
                        strctRoboPathWerte->dTimestamp = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 1:
                        strctRoboPathWerte->dX = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 2:
                        strctRoboPathWerte->dY = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 3:
                        strctRoboPathWerte->dZ = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 4:
                        strctRoboPathWerte->dXx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 5:
                        strctRoboPathWerte->dXy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 6:
                        strctRoboPathWerte->dXz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 7:
                        strctRoboPathWerte->dYx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 8:
                        strctRoboPathWerte->dYy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 9:
                        strctRoboPathWerte->dYz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 10:
                        strctRoboPathWerte->dZx = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 11:
                        strctRoboPathWerte->dZy = System::Single::Parse(sValue);
                        i++;
                        continue;
                    case 12:
                        strctRoboPathWerte->dZz = System::Single::Parse(sValue);
                        i++;
                        continue;
                    default:
                        break;
                    }
                }
                lstCSV->Add(strctRoboPathWerte);
            }
            RoboPathData->SetlstRawPathData(lstCSV);
            UIControl->AppendLog("CSV wurde mit " + lstCSV->Count.ToString() + " Datensätzen eingelesen\n\n");
            System::Threading::Thread::Sleep(500);
            return true;
        }
        else
        {
            UIControl->AppendLog("Fehler!\nDie Datei lässt sich nicht öffnen.\nPrüfen Sie, bo die Datei verschoben worden oder schreibgeschützt ist\n\n");
            return false;
        }
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Einlesen der CSV:\n" + e->Message + "\n\n");
        return false;
    }
}