#pragma once
#include"RoboPathStruct.h"
#include"RoboPathForm.h"

namespace Logic {
	ref class ReadCSV
	{
	public:
        ReadCSV(UserInterface::RoboPathForm^);
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ ReadAndReturnCSV(System::String^);
	private:
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstCSV;
        UserInterface::RoboPathForm^ UIControl;
	};
}

