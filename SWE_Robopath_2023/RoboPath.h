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
		//Dekonstruktor
		~RoboPath();
		//Erhalte/Setze die eingelesene CSV-Datei in einer Liste
		void SetlstRawPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^);
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ GetlstRawPathData();
        //Erhalte/Setze die approximierte CSV-Datei in einer Liste
        void SetlstAproxedPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^);
        System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ GetlstAproxedPathData();
		//Erhalte/Setze den Dateipfad
		void SetFilePath(System::String^);
		System::String^ GetFilePath();
        //Erhalte/Setze den Speicherpfad
        void SetSavePath(System::String^);
        System::String^ GetSavePath();
		//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
		void SetVelo(float);
		float GetVelo();
		//Erhalte/Setze die nutzerdefinierte Toleranzangabe
		void SetTolerance(float);
		float GetTolerance();
		//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
		void SetAverage(float);
		float GetAverage();
		//Erhalte/Setze die nutzerdefinierte Orientierung für A
		void SetOrientationA(float);
		float GetOrientationA();
		//Erhalte/Setze die nutzerdefinierte Orientierung für B
		void SetOrientationB(float);
		float GetOrientationB();
		//Erhalte/Setze die nutzerdefinierte Orientierung für C
		void SetOrientationC(float);
		float GetOrientationC();
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
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstRawPathData;
        System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstAproxedPathData;
		float fUserDefVelo;
		float fUserDefTolerance;
		float fUserDefAverage;
		float fUserDefOrientationA;
		float fUserDefOrientationB;
		float fUserDefOrientationC;
		bool bCSVDefVelo;
		bool bCSVDefOrientation;
	};
}

