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
		void SetlstPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^);
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ GetlstPathData();
		//Erhalte/Setze den Dateipfad
		void SetFilePath(System::String^);
		System::String^ GetFilePath();
		//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
		void SetGeschwindigkeit(float);
		float GetGeschwindigkeit();
		//Erhalte/Setze die nutzerdefinierte Toleranzangabe
		void SetToleranz(float);
		float GetToleranz();
		//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
		void SetMittelWert(float);
		float GetMittelwert();
		//Erhalte/Setze die nutzerdefinierte Orientierung für A
		void SetOrientierungA(float);
		float GetOrientierungA();
		//Erhalte/Setze die nutzerdefinierte Orientierung für B
		void SetOrientierungB(float);
		float GetOrientierungB();
		//Erhalte/Setze die nutzerdefinierte Orientierung für C
		void SetOrientierungC(float);
		float GetOrientierungC();
		//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
		void SetNutzerdefinierteGeschwindigkeit(bool);
		bool GetNutzerdefinierteGeschwindigkeit();
		//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
		void SetNutzerdefinierteOrientierung(bool);
		bool GetNutzerdefinierteOrientierung();
        //Setze alles zurück
        void Zurücksetzen();

	private:
		System::String^ sFilepath;
		System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstPathData;
		float fNutzerGeschwindigkeit;
		float fNutzerToleranz;
		float fNutzerMittelwertfindung;
		float fNutzerOrientierungA;
		float fNutzerOrientierungB;
		float fNutzerOrientierungC;
		bool bGeschwindigkeitAusCSV;
		bool bOrientierungAusCSV;
	};
}

