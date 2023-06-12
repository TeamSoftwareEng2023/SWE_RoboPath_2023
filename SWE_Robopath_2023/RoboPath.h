#pragma once
#include"pch.h"
#include"RoboPathStruct.h"

namespace Projectdata
{
	ref class RoboPath
	{
	public:
		//Konstruktor
		RoboPath();
		//Destruktor
		~RoboPath();
		//Erhalte/Setze die eingelesene CSV-Datei in einer Liste
		void SetlstRawPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^);
		System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ GetlstRawPathData();
        //Erhalte/Setze die gefilterte CSV-Datei in einer Liste
        void SetlstFilteredPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^);
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ GetlstFilteredPathData();
        //Erhalte/Setze die approximierte CSV-Datei in einer Liste
        void SetlstAproxedPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^);
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ GetlstAproxedPathData();
		//Erhalte/Setze den Dateipfad
		void SetFilePath(System::String^);
		System::String^ GetFilePath();
        //Erhalte/Setze den Speicherpfad
        void SetSavePath(System::String^);
        System::String^ GetSavePath();
		//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
		void SetVelo(System::Double);
        System::Double GetVelo();
		//Erhalte/Setze die nutzerdefinierte Toleranzangabe für die Approximation
		void SetToleranceApprox(System::Double);
        System::Double GetToleranceApprox();
        //Erhalte/Setze die nutzerdefinierte Toleranzangabe für die Orientierung
        void SetToleranceOrientation(System::Double);
        System::Double GetToleranceOrientation();
		//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
		void SetSampleSize(int);
        int GetSampleSize();
		//Erhalte/Setze die nutzerdefinierte Orientierung für A
		void SetOrientationA(System::Double);
        System::Double GetOrientationA();
		//Erhalte/Setze die nutzerdefinierte Orientierung für B
		void SetOrientationB(System::Double);
        System::Double GetOrientationB();
		//Erhalte/Setze die nutzerdefinierte Orientierung für C
		void SetOrientationC(System::Double);
        System::Double GetOrientationC();
		//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
		void SetUserDefVelo(bool);
		bool GetUserDefVelo();
		//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
		void SetUserDefOrientation(bool);
		bool GetUserDefOrientation();
        //Setze alles zurück
        void Reset();

	private:
		System::String^ sFilepath;
        System::String^ sSavePath;
		System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstRawPathData;
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFilteredPathData;
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstAproxedPathData;
        System::Double dUserDefVelo;
        System::Double dUserDefToleranceApproximation;
        int iUserDefSampleSize;
        System::Double dUserDefOrientationA;
        System::Double dUserDefOrientationB;
        System::Double dUserDefOrientationC;
        System::Double dUserDefToleranceOrientation;
		System::Boolean bCSVDefVelo;
		System::Boolean bCSVDefOrientation;
	};
}

