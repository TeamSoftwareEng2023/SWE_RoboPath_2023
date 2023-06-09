#include "pch.h"
#include "RoboPath.h"

//Konstruktor
Projectdata::RoboPath::RoboPath() {
	sFilepath = "";
	fUserDefVelo = 0;
	fUserDefTolerance = 0;
	fUserDefAverage = 0;
	fUserDefOrientationA = 0;
	fUserDefOrientationB = 0;
	fUserDefOrientationC = 0;
	bCSVDefOrientation = false;
	bCSVDefVelo = false;
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
void Projectdata::RoboPath::SetVelo(float fGeschwindigkeit) {
    fUserDefVelo = fGeschwindigkeit;
}
float Projectdata::RoboPath::GetVelo() {
	return fUserDefVelo;
}
//Erhalte/Setze die nutzerdefinierte Toleranzangabe
void Projectdata::RoboPath::SetTolerance(float fToleranz) {
	fUserDefTolerance = fToleranz;
}
float Projectdata::RoboPath::GetTolerance() {
	return fUserDefTolerance;
}
//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
void Projectdata::RoboPath::SetAverage(float fMittelwert) {
	fUserDefAverage = fMittelwert;
}
float Projectdata::RoboPath::GetAverage() {
	return fUserDefAverage;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für A
void Projectdata::RoboPath::SetOrientationA(float fA) {
	fUserDefOrientationA = fA;
}
float Projectdata::RoboPath::GetOrientationA() {
	return fUserDefOrientationA;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für B
void Projectdata::RoboPath::SetOrientationB(float fB) {
    fUserDefOrientationB = fB;
}
float Projectdata::RoboPath::GetOrientationB() {
	return fUserDefOrientationB;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für C
void Projectdata::RoboPath::SetOrientationC(float fC) {
    fUserDefOrientationC = fC;
}
float Projectdata::RoboPath::GetOrientationC() {
	return fUserDefOrientationC;
}
//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
void Projectdata::RoboPath::SetUserDefVelo(bool bSetGeschwindigkeit) {
	bCSVDefVelo = bSetGeschwindigkeit;
}
bool Projectdata::RoboPath::GetUserDefVelo() {
	return bCSVDefVelo;
}
//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
void Projectdata::RoboPath::SetUserDefOrientation(bool bSetOrientierung) {
	bCSVDefOrientation = bSetOrientierung;
}
bool Projectdata::RoboPath::GetUserDefOrientation() {
	return bCSVDefOrientation;
}
//Standardwerte setzen
void Projectdata::RoboPath::Reset() {
    sFilepath = "";
    fUserDefVelo = 0;
    fUserDefTolerance = 0;
    fUserDefAverage = 0;
    fUserDefOrientationA = 0;
    fUserDefOrientationB = 0;
    fUserDefOrientationC = 0;
    bCSVDefOrientation = false;
    bCSVDefVelo = false;
    lstPathData->Clear();
}
