#include "pch.h"
#include "Version.h"

Projectdata::Version::Version() {
	sVersion = "v1.1";
}
System::String^ Projectdata::Version::getVersion() {
	return sVersion;
}