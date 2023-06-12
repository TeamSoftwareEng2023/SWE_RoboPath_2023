#pragma once
#include"pch.h"
#include"RoboPathForm.h"

namespace Logic {
    ref class VeloCalc
    {
    public:
        //Konstruktor
        VeloCalc(UserInterface::RoboPathForm^);
        //Funktion zum Berechnen der Geschwindigkeit aus der CSV
        System::Boolean VeloCalcCSV(Projectdata::RoboPath^);
    private:
        //UI Objekt zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
    };
}