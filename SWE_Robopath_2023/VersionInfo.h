#pragma once
namespace Projectdata
{
	ref class VersionInfo 
	{
	public:
		//Konstruktor
		VersionInfo();
		//Erhalte die aktuelle Version
		System::String^ getVersion();
	private:
		//Speicherort f�r die aktuelle Version
		System::String^ sVersion;
	};
}