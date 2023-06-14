#pragma once
#include"pch.h"
#include"RoboPathForm.h"
#include"RoboPath.h"
namespace Logic {
    ref class CreateKUKAFile
    {
    public:
        //Konstruktor
        CreateKUKAFile(UserInterface::RoboPathForm^);
        //Funktion zum Erzeugen und Speichern einer Datei
        void WriteKUKA(Projectdata::RoboPath^);
    private:
        //Liste mit dem finalen RoboCode
        System::Collections::Generic::List<System::String^>^ lstKUKAFile;
        //UI Objekt zum Bentuzen des Logs
        UserInterface::RoboPathForm^ UIControl;
        System::String^ RoundBasedOnThirdDecimalPlace(System::Double);
    };
}