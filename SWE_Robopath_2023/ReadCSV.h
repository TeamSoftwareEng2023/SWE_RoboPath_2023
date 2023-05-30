#pragma once
#include"RoboPathStruct.h"
#include"RoboPathForm.h"

namespace LogicReadCSV {
	ref class ReadCSV
	{
	public:
		System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ ReadAndReturnCSV(System::String^);
	private:
		System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ lstCSV;
	};
}

