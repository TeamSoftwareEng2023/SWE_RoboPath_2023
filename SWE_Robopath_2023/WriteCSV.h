#pragma once
#include"pch.h"
#include"RoboPathForm.h"
#include"RoboPath.h"

namespace Logic {
    ref class WriteCSV
    {
    public:
        WriteCSV(UserInterface::RoboPathForm^);
        void WriteForMatLab(Projectdata::RoboPath^);
    private:
        System::Collections::Generic::List<System::String^>^ lstFileForMatLab;
        UserInterface::RoboPathForm^ UIControl;
    };
}

