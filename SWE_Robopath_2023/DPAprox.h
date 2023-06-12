#pragma once
#include"pch.h"
#include"RoboPath.h"
#include"RoboPathForm.h"
#include"Point3DStruct.h"
namespace Logic {
    ref class DPAprox
    {
    public:
        //Konstruktor
        DPAprox(UserInterface::RoboPathForm^);
        //Funktion, initialen Aufruf des DouglasPeucker Algo
        System::Boolean approx(Projectdata::RoboPath^);
    private:
        //Douglas Peucker Algo. Zum Approximieren der Daten
        System::Boolean douglasPeuckerRecursive(int, int, System::Double);
        //Funktion, um den Abstand zwischen einer Geraden und einem Punkt zu berechnen (Lotfuﬂpunktverfahren)
        System::Double PointDistanceToLine(Projectdata::Point3D^, Projectdata::Point3D^, Projectdata::Point3D^);
        //Liste zum Approximieren der Daten
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstAproxedPath;
        //UI Objekt, zum Benutzen des Logs
        UserInterface::RoboPathForm^ UIControl;
    };
}