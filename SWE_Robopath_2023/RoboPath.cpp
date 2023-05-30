#include "pch.h"
#include "RoboPath.h"

//Konstruktor
DataRoboPath::RoboPath::RoboPath() {
	sFilepath = "";
	fNutzerGeschwindigkeit = 0;
	fNutzerToleranz = 0;
	fNutzerMittelwertfindung = 0;
	fNutzerOrientierungA = 0;
	fNutzerOrientierungB = 0;
	fNutzerOrientierungC = 0;
	bGeschwindigkeitAusCSV = false;
	bOrientierungAusCSV = false;
	lstPathData = gcnew System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>();
}
//Destruktor
DataRoboPath::RoboPath::~RoboPath() {
	lstPathData->Clear();
}
//Erhalte/Setze die eingelesene CSV-Datei in einer Liste
void DataRoboPath::RoboPath::SetlstPathData(System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ lstCSV) {
	lstPathData = lstCSV;
}
System::Collections::Generic::List<DataRoboPathStruct::RoboPathStruct<float>^>^ DataRoboPath::RoboPath::GetlstPathData() {
	return lstPathData;
}
//Erhalte/Setze den Dateipfad
void DataRoboPath::RoboPath::SetFilePath(System::String^ sActFilepath) {
	sFilepath = sActFilepath;
}
System::String^ DataRoboPath::RoboPath::GetFilePath() {
	return sFilepath;
}
//Erhalte/Setze die nutzerdefinierte Geschwindigkeit
void DataRoboPath::RoboPath::SetGeschwindigkeit(float fGeschwindigkeit) {
	fNutzerGeschwindigkeit = fGeschwindigkeit;
}
float DataRoboPath::RoboPath::GetGeschwindigkeit() {
	return fNutzerGeschwindigkeit;
}
//Erhalte/Setze die nutzerdefinierte Toleranzangabe
void DataRoboPath::RoboPath::SetToleranz(float fToleranz) {
	fNutzerToleranz = fToleranz;
}
float DataRoboPath::RoboPath::GetToleranz() {
	return fNutzerToleranz;
}
//Erhalte/Setze die nutzerdefinierte Mittelwertfindung
void DataRoboPath::RoboPath::SetMittelWert(float fMittelwert) {
	fNutzerMittelwertfindung = fMittelwert;
}
float DataRoboPath::RoboPath::GetMittelwert() {
	return fNutzerMittelwertfindung;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für A
void DataRoboPath::RoboPath::SetOrientierungA(float fA) {
	fNutzerOrientierungA = fA;
}
float DataRoboPath::RoboPath::GetOrientierungA() {
	return fNutzerOrientierungA;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für B
void DataRoboPath::RoboPath::SetOrientierungB(float fB) {
	fNutzerOrientierungB = fB;
}
float DataRoboPath::RoboPath::GetOrientierungB() {
	return fNutzerOrientierungB;
}
//Erhalte/Setze die nutzerdefinierte Orientierung für C
void DataRoboPath::RoboPath::SetOrientierungC(float fC) {
	fNutzerOrientierungC = fC;
}
float DataRoboPath::RoboPath::GetOrientierungC() {
	return fNutzerOrientierungC;
}
//Erhalte/Setze die boolsche Variable für die Option "Geschwindigkeit aus CSV"
void DataRoboPath::RoboPath::SetNutzerdefinierteGeschwindigkeit(bool bSetGeschwindigkeit) {
	bGeschwindigkeitAusCSV = bSetGeschwindigkeit;
}
bool DataRoboPath::RoboPath::GetNutzerdefinierteGeschwindigkeit() {
	return bGeschwindigkeitAusCSV;
}
//Erhalte/Setze die boolsche Variable für die Option "Orientierung aus CSV"
void DataRoboPath::RoboPath::SetNutzerdefinierteOrientierung(bool bSetOrientierung) {
	bOrientierungAusCSV = bSetOrientierung;
}
bool DataRoboPath::RoboPath::GetNutzerdefinierteOrientierung() {
	return bOrientierungAusCSV;
}
