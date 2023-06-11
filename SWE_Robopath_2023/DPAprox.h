#pragma once
#include"pch.h"
#include"RoboPath.h"
#include"RoboPathForm.h"
#include"Point3DStruct.h"
namespace Logic {
    ref class DPAprox
    {
    public:
        DPAprox(UserInterface::RoboPathForm^);
        System::Boolean approx(Projectdata::RoboPath^);
    private:
        System::Boolean douglasPeuckerRecursive(int, int, System::Double);
        System::Double PointDistanceToLine(Projectdata::Point3D^, Projectdata::Point3D^, Projectdata::Point3D^);
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstAproxedPath;
        UserInterface::RoboPathForm^ UIControl;
    };
}