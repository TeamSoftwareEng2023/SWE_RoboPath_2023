#include "pch.h"
#include "RoboPath.h"

//Konstruktor
Projectdata::RoboPath::RoboPath() {
	sFilepath = "";
	fNutzerGeschwindigkeit = 0;
	fNutzerToleranz = 0;
	fNutzerMittelwertfindung = 0;
	fNutzerOrientierungA = 0;
	fNutzerOrientierungB = 0;
	fNutzerOrientierungC = 0;
	bGeschwindigkeitAusCSV = false;
	bOrientierungAusCSV = false;
	lstPathData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>();
}
//Destruktor
Projectdata::RoboPath::~RoboPath() {
	lstPathData->Clear();
}
//Erhalte/Setze die eingelesene CSV-Datei in einer Liste
void Projectdata::RoboPath::SetlstPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ lstCSV) {
	lstPathData = lstCSV;
}
System::Collections::Generic::List<Projectdata::RoboPathStruct<float>^>^ Projectdata::RoboPath::GetlstPathData() {
	return lstPathData;
}
//Erhalte/Setze den Dateipfad
void Projectdata::RoboPath::SetFilePath(System::String^ sActFilepath) {
	sFilepath = sActFilepath;
}
System::String^ Projectdata::RoboPath::GetFilePath() {
	return sFilepath;
}
//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
void Projectdata::RoboPath::SetGeschwindigkeit(float fGeschwindigkeit) {
	fNutzerGeschwindigkeit = fGeschwindigkeit;
}
float Projectdata::RoboPath::GetGeschwindigkeit() {
	return fNutzerGeschwindigkeit;
}
//Erhalte/Setze die nutzerdefinierte Toleranzangabe
void Projectdata::RoboPath::SetToleranz(float fToleranz) {
	fNutzerToleranz = fToleranz;
}
float Projectdata::RoboPath::GetToleranz() {
	return fNutzerToleranz;
}
//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
void Projectdata::RoboPath::SetMittelWert(float fMittelwert) {
	fNutzerMittelwertfindung = fMittelwert;
}
float Projectdata::RoboPath::GetMittelwert() {
	return fNutzerMittelwertfindung;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für A
void Projectdata::RoboPath::SetOrientierungA(float fA) {
	fNutzerOrientierungA = fA;
}
float Projectdata::RoboPath::GetOrientierungA() {
	return fNutzerOrientierungA;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für B
void Projectdata::RoboPath::SetOrientierungB(float fB) {
	fNutzerOrientierungB = fB;
}
float Projectdata::RoboPath::GetOrientierungB() {
	return fNutzerOrientierungB;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für C
void Projectdata::RoboPath::SetOrientierungC(float fC) {
	fNutzerOrientierungC = fC;
}
float Projectdata::RoboPath::GetOrientierungC() {
	return fNutzerOrientierungC;
}
//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
void Projectdata::RoboPath::SetNutzerdefinierteGeschwindigkeit(bool bSetGeschwindigkeit) {
	bGeschwindigkeitAusCSV = bSetGeschwindigkeit;
}
bool Projectdata::RoboPath::GetNutzerdefinierteGeschwindigkeit() {
	return bGeschwindigkeitAusCSV;
}
//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
void Projectdata::RoboPath::SetNutzerdefinierteOrientierung(bool bSetOrientierung) {
	bOrientierungAusCSV = bSetOrientierung;
}
bool Projectdata::RoboPath::GetNutzerdefinierteOrientierung() {
	return bOrientierungAusCSV;
}
void Projectdata::RoboPath::Zurücksetzen() {
    sFilepath = "";
    fNutzerGeschwindigkeit = 0;
    fNutzerToleranz = 0;
    fNutzerMittelwertfindung = 0;
    fNutzerOrientierungA = 0;
    fNutzerOrientierungB = 0;
    fNutzerOrientierungC = 0;
    bGeschwindigkeitAusCSV = false;
    bOrientierungAusCSV = false;
    lstPathData->Clear();
}
