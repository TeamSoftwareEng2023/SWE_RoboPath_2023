#include "pch.h"
#include "VersionInfo.h"
//Hier wird die Version manuell angepasst. Diese wird dann in Hauptfesnter unten links angezeigt
Projectdata::VersionInfo::VersionInfo() {
	sVersion = "v1.8";
}
//Erhalte die aktuelle Version
System::String^ Projectdata::VersionInfo::getVersion() {
	return sVersion;
}