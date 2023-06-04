#include "pch.h"
#include "Version.h"

Projectdata::Version::Version() {
	sVersion = "v1.2";
}
System::String^ Projectdata::Version::getVersion() {
	return sVersion;
}