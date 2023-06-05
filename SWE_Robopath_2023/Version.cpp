#include "pch.h"
#include "VersionInfo.h"

Projectdata::VersionInfo::VersionInfo() {
	sVersion = "v1.3";
}
System::String^ Projectdata::VersionInfo::getVersion() {
	return sVersion;
}