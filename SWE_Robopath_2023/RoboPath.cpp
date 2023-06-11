#include "pch.h"
#include "RoboPath.h"

//Konstruktor
Projectdata::RoboPath::RoboPath() {
	sFilepath = "";
    sSavePath = "";
	dUserDefVelo = 0;
	dUserDefTolerance = 0;
    iUserDefSampleSize = 0;
	dUserDefOrientationA = 0;
	dUserDefOrientationB = 0;
	dUserDefOrientationC = 0;
	bCSVDefOrientation = false;
	bCSVDefVelo = false;
	lstRawPathData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
    lstFilteredPathData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
    lstAproxedPathData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();
}
//Destruktor
Projectdata::RoboPath::~RoboPath() {
	lstRawPathData->Clear();
    lstAproxedPathData->Clear();
}
//Erhalte/Setze die eingelesene CSV-Datei in einer Liste
void Projectdata::RoboPath::SetlstRawPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstCSV) {
	lstRawPathData = lstCSV;
}
System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ Projectdata::RoboPath::GetlstRawPathData() {
	return lstRawPathData;
}
//Erhalte/Setze die gefilterte CSV-Datei in einer Liste
void Projectdata::RoboPath::SetlstFilteredPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFilteredCSV) {
    lstFilteredPathData = lstFilteredCSV;
}
System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ Projectdata::RoboPath::GetlstFilteredPathData() {
    return lstFilteredPathData;
}
//Erhalte/Setze die approximierte CSV-Datei in einer Liste
void Projectdata::RoboPath::SetlstAproxedPathData(System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstAproxedCSV) {
    lstAproxedPathData = lstAproxedCSV;
}
System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ Projectdata::RoboPath::GetlstAproxedPathData() {
    return lstAproxedPathData;
}
//Erhalte/Setze den Dateipfad
void Projectdata::RoboPath::SetFilePath(System::String^ sActFilepath) {
	sFilepath = sActFilepath;
}
System::String^ Projectdata::RoboPath::GetFilePath() {
	return sFilepath;
}
//Erhalte/Setze den Speicherpfad
void Projectdata::RoboPath::SetSavePath(System::String^ sActSavePath) {
    sSavePath = sActSavePath;
}
System::String^ Projectdata::RoboPath::GetSavePath() {
    return sSavePath;
}
//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
void Projectdata::RoboPath::SetVelo(System::Double dVelo) {
    dUserDefVelo = dVelo;
}
System::Double Projectdata::RoboPath::GetVelo() {
	return dUserDefVelo;
}
//Erhalte/Setze die nutzerdefinierte Toleranzangabe
void Projectdata::RoboPath::SetTolerance(System::Double fTolerance) {
	dUserDefTolerance = fTolerance;
}
System::Double Projectdata::RoboPath::GetTolerance() {
	return dUserDefTolerance;
}
//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
void Projectdata::RoboPath::SetSampleSize(int iSampleSize) {
    iUserDefSampleSize = iSampleSize;
}
int Projectdata::RoboPath::GetSampleSize() {
	return iUserDefSampleSize;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für A
void Projectdata::RoboPath::SetOrientationA(System::Double dA) {
	dUserDefOrientationA = dA;
}
System::Double Projectdata::RoboPath::GetOrientationA() {
	return dUserDefOrientationA;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für B
void Projectdata::RoboPath::SetOrientationB(System::Double dB) {
    dUserDefOrientationB = dB;
}
System::Double Projectdata::RoboPath::GetOrientationB() {
	return dUserDefOrientationB;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für C
void Projectdata::RoboPath::SetOrientationC(System::Double dC) {
    dUserDefOrientationC = dC;
}
System::Double Projectdata::RoboPath::GetOrientationC() {
	return dUserDefOrientationC;
}
//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
void Projectdata::RoboPath::SetUserDefVelo(bool bSetVelo) {
	bCSVDefVelo = bSetVelo;
}
bool Projectdata::RoboPath::GetUserDefVelo() {
	return bCSVDefVelo;
}
//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
void Projectdata::RoboPath::SetUserDefOrientation(bool bSetOrientation) {
	bCSVDefOrientation = bSetOrientation;
}
bool Projectdata::RoboPath::GetUserDefOrientation() {
	return bCSVDefOrientation;
}
//Standardwerte setzen
void Projectdata::RoboPath::Reset() {
    sFilepath = "";
    dUserDefVelo = 0;
    dUserDefTolerance = 0;
    iUserDefSampleSize = 0;
    dUserDefOrientationA = 0;
    dUserDefOrientationB = 0;
    dUserDefOrientationC = 0;
    bCSVDefOrientation = false;
    bCSVDefVelo = false;
    lstRawPathData->Clear();
    lstFilteredPathData->Clear();
    lstAproxedPathData->Clear();
}
