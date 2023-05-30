#include "pch.h"
#include "ReadCSV.h"

System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ LogicReadCSV::ReadCSV::ReadAndReturnCSV(System::String^ sFilepath)
{
	UIRoboPathForms::RoboPathForm^ UIControl = gcnew UIRoboPathForms::RoboPathForm();
	System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ lstLeer;
	std::ifstream CSV(msclr::interop::marshal_as<std::string>(sFilepath));
	std::string sLine;
	char cTrennzeichen = ' ';

	try
	{
		//Prüfen, ob die Datei geöffnet werden könnte
		if (CSV.is_open())
		{
			while (std::getline(CSV, sLine))
			{
				std::stringstream ssWerte(sLine);
				std::string sEinzelwert;
				DataRoboPathStruct::RoboPathStruct<float>^ strctRoboPathWerte;

				while (std::getline(ssWerte, sEinzelwert, cTrennzeichen))
				{
					int i = 0;
					switch (i)
					{
					case 0:
						strctRoboPathWerte->fZeitstempel = std::stof(sEinzelwert);
						i++;
						continue;
					case 1:
						strctRoboPathWerte->fX = std::stof(sEinzelwert);
						i++;
						continue;
					case 2:
						strctRoboPathWerte->fY = std::stof(sEinzelwert);
						i++;
						continue;
					case 3:
						strctRoboPathWerte->fZ = std::stof(sEinzelwert);
						i++;
						continue;
					case 4:
						strctRoboPathWerte->fXx = std::stof(sEinzelwert);
						i++;
						continue;
					case 5:
						strctRoboPathWerte->fXy = std::stof(sEinzelwert);
						i++;
						continue;
					case 6:
						strctRoboPathWerte->fXz = std::stof(sEinzelwert);
						i++;
						continue;
					case 7:
						strctRoboPathWerte->fYx = std::stof(sEinzelwert);
						i++;
						continue;
					case 8:
						strctRoboPathWerte->fYy = std::stof(sEinzelwert);
						i++;
						continue;
					case 9:
						strctRoboPathWerte->fYz = std::stof(sEinzelwert);
						i++;
						continue;
					case 10:
						strctRoboPathWerte->fZx = std::stof(sEinzelwert);
						i++;
						continue;
					case 11:
						strctRoboPathWerte->fZy = std::stof(sEinzelwert);
						i++;
						continue;
					case 12:
						strctRoboPathWerte->fZz = std::stof(sEinzelwert);
						i++;
						continue;
					default:
						break;
					}
				}
				lstCSV->Add(strctRoboPathWerte);
			}
			return lstCSV;
		}
		else
		{
			UIControl->AppendLog("\nDatei wurde verschoben, gelöscht oder ist schreibgeschützt!");
			return lstLeer;
		}
	}
	catch (const std::exception&)
	{
		return lstLeer;
	}
}