#pragma once
#include"pch.h"
#include"RoboPathForm.h"
#include"RoboPathStruct.h"

namespace Logic {
    ref class SampleFilter {
    public:
        //Konstruktor
        SampleFilter(UserInterface::RoboPathForm^);
        //Funktion zum Mittelwertbilden
        System::Boolean FilterData(Projectdata::RoboPath^);
    private:
        //UI Objekt zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
    };
}


