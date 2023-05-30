#pragma once
namespace DataRoboPathVersion
{
	ref class RoboPathVersion 
	{
	public:
		//Konstruktor
		RoboPathVersion();
		//Erhalte die aktuelle Version
		System::String^ getVersion();
	private:
		//Speicherort für die aktuelle Version
		System::String^ sVersion;
	};
}