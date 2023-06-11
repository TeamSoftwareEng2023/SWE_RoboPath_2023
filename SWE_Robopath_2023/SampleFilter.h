#pragma once
#include"pch.h"
#include"RoboPathForm.h"
#include"RoboPathStruct.h"

namespace Logic {
    ref class SampleFilter {
    public:
        SampleFilter(UserInterface::RoboPathForm^);
        System::Boolean FilterData(Projectdata::RoboPath^);
    private:
        UserInterface::RoboPathForm^ UIControl;
    };
}


