#pragma once
#include"pch.h"
#include"RoboPathForm.h"

namespace Logic {
    ref class CalcOrientation
    {
    public:
        //Konstruktor
        CalcOrientation(UserInterface::RoboPathForm^);
        //Berechnung von Transformationmatrix zu eulersche Winkel A, B und C
        System::Boolean CalcRotMatToEulerABC(Projectdata::RoboPath^);
    private:
        //UI Objekt zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
    };
}