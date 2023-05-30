#include "pch.h"
#include "RoboPathVersion.h"

DataRoboPathVersion::RoboPathVersion::RoboPathVersion() {
	sVersion = "v1.4";
}
System::String^ DataRoboPathVersion::RoboPathVersion::getVersion() {
	return sVersion;
}