#pragma once
#include"RoboPathStruct.h"
#include"RoboPathForm.h"

namespace Logic {
	ref class ReadCSV
	{
	public:
        ReadCSV(UserInterface::RoboPathForm^);
        System::Boolean ReadAndSaveCSV(Projectdata::RoboPath^);
	private:
		System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstCSV;
        UserInterface::RoboPathForm^ UIControl;
	};
}

