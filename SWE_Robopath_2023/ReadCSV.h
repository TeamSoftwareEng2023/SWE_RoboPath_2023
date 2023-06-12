#pragma once
#include"RoboPathStruct.h"
#include"RoboPathForm.h"

namespace Logic {
	ref class ReadCSV
	{
	public:
        //Konstruktor
        ReadCSV(UserInterface::RoboPathForm^);
        //Funktion zum einlesen der CSV
        System::Boolean ReadAndSaveCSV(Projectdata::RoboPath^);
	private:
        //Liste zum einlesen der Datensätze
		System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstCSV;
        //UI Objekt zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
	};
}

