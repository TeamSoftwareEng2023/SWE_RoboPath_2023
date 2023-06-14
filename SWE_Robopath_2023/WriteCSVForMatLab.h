#pragma once
#include"pch.h"
#include"RoboPathForm.h"
#include"RoboPath.h"

namespace Logic {
    ref class WriteCSVForMatLab
    {
    public:
        //Konstruktor
        WriteCSVForMatLab(UserInterface::RoboPathForm^);
        //Funktion zum Erzeugen und Speichern einer Datei
        void WriteForMatLab(Projectdata::RoboPath^);
    private:
        //Liste mit dem finalen RoboCode
        System::Collections::Generic::List<System::String^>^ lstFileForMatLab;
        //UI Objekt zum Bentuzen des Logs
        UserInterface::RoboPathForm^ UIControl;
    };
}