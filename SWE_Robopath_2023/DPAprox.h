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
        void approx(Projectdata::RoboPath^);
    private:
        void douglasPeuckerRecursive(int, int, float);
        float PointDistanceToLine(Projectdata::Point3D^, Projectdata::Point3D^, Projectdata::Point3D^);
        System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstAproxedPath;
        UserInterface::RoboPathForm^ UIControl;
    };
}