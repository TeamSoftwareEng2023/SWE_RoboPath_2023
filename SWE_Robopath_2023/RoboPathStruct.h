#pragma once
//Struktur, die eine Zeile mit Daten aus der CSV enthält. Diese Struktur wird in einer Liste gespeichert.
namespace Projectdata {
	generic<typename T>
    ref struct RoboPathStruct
    {
        T dTimestamp;
        T dX;
        T dY;
        T dZ;
        T dXx;
        T dXy;
        T dXz;
        T dYx;
        T dYy;
        T dYz;
        T dZx;
        T dZy;
        T dZz;
        T dVelo;
        T dA;
        T dB;
        T dC;
    };
}