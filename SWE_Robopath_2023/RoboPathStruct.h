#pragma once
//Struktur, die eine Zeile mit Daten aus der CSV enth�lt. Diese Struktur wird in einer Liste gespeichert.
namespace Projectdata {
	generic<typename T>
	ref struct RoboPathStruct
	{
		T fTimestamp;
		T fX;
		T fY;
		T fZ;
		T fXx;
		T fXy;
		T fXz;
		T fYx;
		T fYy;
		T fYz;
		T fZx;
		T fZy;
		T fZz;
	};
}