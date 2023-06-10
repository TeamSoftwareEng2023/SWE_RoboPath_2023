#pragma once
#include"VersionInfo.h"
#include"RoboPath.h"


namespace UserInterface {
    //Diese namespaces wurden automtaisch bei Erstellung des Projektes hinzugefügt.
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class RoboPathForm : public System::Windows::Forms::Form
    {
        //Konstruktor
    public: RoboPathForm(void);
        //Destruktor
    protected: ~RoboPathForm();
    //In diesem Objekt werden alle Daten gepsiechert, die der Nutzer über die Oberfläache eingibt
    private: Projectdata::RoboPath^ Datastore;
    //Wird true, wenn der Set Button erfolgreich gedrückt worden ist. Gibt dann den Start Button frei.
    private: System::Boolean bSetted;
    //Defintion alle Elemente in der Oberfläache
    private: System::Windows::Forms::Button^ btn_Set;
    private: System::Windows::Forms::TextBox^ tb_Velo;
    private: System::Windows::Forms::TextBox^ tb_Orientation_A;
    private: System::Windows::Forms::TextBox^ tb_Tolerance;
    private: System::Windows::Forms::TextBox^ tb_Average;
    private: System::Windows::Forms::CheckBox^ cb_Velo;
    private: System::Windows::Forms::CheckBox^ cb_Orientation;
    private: System::Windows::Forms::Label^ label_Velo;
    private: System::Windows::Forms::Label^ label_Orientation;
    private: System::Windows::Forms::Label^ label_Tolerance;
    private: System::Windows::Forms::Label^ label_Average;
    private: System::Windows::Forms::Button^ btn_OpenCSV;
    private: System::Windows::Forms::Button^ btn_Start;
    private: System::Windows::Forms::TextBox^ tb_Velo_Act;
    private: System::Windows::Forms::TextBox^ tb_Orientation_Act_A;
    private: System::Windows::Forms::TextBox^ tb_Tolerance_Act;
    private: System::Windows::Forms::TextBox^ tb_Average_Act;
    private: System::Windows::Forms::Label^ label_ActValues;
    private: System::Windows::Forms::TextBox^ tb_Version;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog_CSV;
    private: System::Windows::Forms::RichTextBox^ tb_Log;
    private: System::Windows::Forms::TextBox^ tb_Orientation_Act_C;
    private: System::Windows::Forms::TextBox^ tb_Orientation_Act_B;
    private: System::Windows::Forms::TextBox^ tb_Orientation_C;
    private: System::Windows::Forms::TextBox^ tb_Orientation_B;
    private: System::Windows::Forms::Label^ label_C;
    private: System::Windows::Forms::Label^ label_B;
    private: System::Windows::Forms::Label^ label_ActB;
    private: System::Windows::Forms::Label^ label_ActA;
    private: System::Windows::Forms::Label^ label_ActC;
    private: System::Windows::Forms::Label^ label_A;
    private: System::Windows::Forms::Label^ label_ActValues_ABC;
    private: System::Windows::Forms::Label^ label_Geschwindigkeit_Einheit_Wert;
    private: System::Windows::Forms::Label^ label_Geschwindigkeit_Einheit_Act_Wert;
    private: System::Windows::Forms::Label^ label_Toleranz_Wert;
    private: System::Windows::Forms::Label^ label_Toleranz_Act_Wert;
    private: System::Windows::Forms::Label^ label_Header;
    private: System::Windows::Forms::Button^ btn_Reset;
    public: System::Windows::Forms::SaveFileDialog^ saveFileDialog_CSV;

    private: System::ComponentModel::IContainer^ components;

    //Definition aller Funktionen
    //Alle Elemente der Oberfläche werden initialisiert. 
    private: void InitializeComponent();
    //Ereignis, nachdem eine valide Datei ausgfewählt worden ist
    private: System::Void openFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
    //Eregnis, nach dem Klicken auf den ".csv öffnen" Button
    private: System::Void btn_OpenCSV_Click(System::Object^ sender, System::EventArgs^ e);
    //Funktion, um Text im Log anzuzeigen
    public: System::Void AppendLog(System::String^ sMessage);
    //Ereignis, nach dem Klickenken auf den Start Button
    private: System::Void btn_Start_Click(System::Object^ sender, System::EventArgs^ e);
    //Funktion, um die Versionnummer anzuzeigen
    private: System::Void SetVersion();
    //Ereignis nach dem un/checken der Velo Checkbox
    private: System::Void cb_Velo_CheckChanged(System::Object^ sender, System::EventArgs^ e);
    //Ereignis nach dem un/checken der Orientation Checkbox
    private: System::Void cb_Orientation_CheckChanged(System::Object^ sender, System::EventArgs^ e);
    //Ereignis nach dem Klicken auf den Set Button
    private: System::Void btn_Set_Click(System::Object^ sender, System::EventArgs^ e);
    //Funktion, um ein Fehlerfesnter mit definierten Text anzuzeigen
    private: System::Void ShowErrorWindow(String^ errorMessage);
    //Ereignis nach dem Klicken auf den Reset Button
    private: System::Void btn_Reset_Click(System::Object^ sender, System::EventArgs^ e);
    //Funktion, um ein Entscheidungsfesnter (Ja oder Nein) mit definierten Text anzuzeigen
    private: System::Boolean ShowYesNoWindow(String^ message);
    //Funktion, um die Oberfläche zu clearen
    private: System::Void ResetAll();
    //Funktion, die den eingegeben Wert kontrolliert, nachdem die Textbox den Fokus verliert
    private: System::Void ValidateInput(System::Object^ sender, System::EventArgs^ e);
    private: System::Void saveFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
    };
}
#pragma endregion