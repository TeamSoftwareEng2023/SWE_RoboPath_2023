#pragma once
#include"pch.h"
#include"RoboPathForm.h"

namespace Logic {
    ref class ValidateRawCSV
    {
    public:
        //Konstruktor
        ValidateRawCSV(UserInterface::RoboPathForm^);
        //Funktion um die zu einlesende CSV zu validieren
        System::Boolean ValidateCSV(Projectdata::RoboPath^);
    private:
        //UI Objekt zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
        System::Boolean CheckValueRotMat(System::Double, int, int, System::String^);
    };
}