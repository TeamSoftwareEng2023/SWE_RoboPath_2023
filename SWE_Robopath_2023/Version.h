#pragma once
namespace Projectdata
{
	ref class Version 
	{
	public:
		//Konstruktor
		Version();
		//Erhalte die aktuelle Version
		System::String^ getVersion();
	private:
		//Speicherort f�r die aktuelle Version
		System::String^ sVersion;
	};
}