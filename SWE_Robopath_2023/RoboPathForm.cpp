#include"pch.h"
#include"RoboPathForm.h"
#include"ReadCSV.h"
#include"DPAprox.h"
#include"WriteCSVForMatLab.h"
#include"SampleFilter.h"
#include"VeloCalc.h"
#include"CalcOrientation.h"
#include"CreateKUKAFile.h"

//Konstruktor
UserInterface::RoboPathForm::RoboPathForm(void)
{
    //Initialisierung aller Elemente auf der Oberfläche
    InitializeComponent();
    //Erstellung des Objekts, in dem alle benutzerdefinierte Werte auzs der Oberfläche gespeichert werden
    Datastore = gcnew Projectdata::RoboPath();
    //Funktion, um sich die aktuelle Version zu holen
    SetVersion();
}
//Destruktor
UserInterface::RoboPathForm::~RoboPathForm()
{
    if (components)
    {
        delete components;
    }
}

//Initialisierung aller Elemente der Oberfläche
void UserInterface::RoboPathForm::InitializeComponent()
{
    this->btn_Set = (gcnew System::Windows::Forms::Button());
    this->tb_Velo = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_A = (gcnew System::Windows::Forms::TextBox());
    this->tb_ToleranceApprox = (gcnew System::Windows::Forms::TextBox());
    this->tb_SampleSize = (gcnew System::Windows::Forms::TextBox());
    this->cb_Velo = (gcnew System::Windows::Forms::CheckBox());
    this->cb_Orientation = (gcnew System::Windows::Forms::CheckBox());
    this->label_Velo = (gcnew System::Windows::Forms::Label());
    this->label_Orientation = (gcnew System::Windows::Forms::Label());
    this->label_ToleranceApprox = (gcnew System::Windows::Forms::Label());
    this->label_SampleSize = (gcnew System::Windows::Forms::Label());
    this->btn_OpenCSV = (gcnew System::Windows::Forms::Button());
    this->btn_Start = (gcnew System::Windows::Forms::Button());
    this->tb_Velo_Act = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_Act_A = (gcnew System::Windows::Forms::TextBox());
    this->tb_ToleranceApprox_Act = (gcnew System::Windows::Forms::TextBox());
    this->tb_SampleSize_Act = (gcnew System::Windows::Forms::TextBox());
    this->label_ActValues = (gcnew System::Windows::Forms::Label());
    this->tb_Version = (gcnew System::Windows::Forms::TextBox());
    this->openFileDialog_CSV = (gcnew System::Windows::Forms::OpenFileDialog());
    this->tb_Log = (gcnew System::Windows::Forms::RichTextBox());
    this->tb_Orientation_Act_C = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_Act_B = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_C = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_B = (gcnew System::Windows::Forms::TextBox());
    this->label_C = (gcnew System::Windows::Forms::Label());
    this->label_B = (gcnew System::Windows::Forms::Label());
    this->label_A = (gcnew System::Windows::Forms::Label());
    this->label_Geschwindigkeit_Einheit_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Header = (gcnew System::Windows::Forms::Label());
    this->btn_Reset = (gcnew System::Windows::Forms::Button());
    this->saveFileDialog_CSV = (gcnew System::Windows::Forms::SaveFileDialog());
    this->label_Degree_A = (gcnew System::Windows::Forms::Label());
    this->label_Degree_B = (gcnew System::Windows::Forms::Label());
    this->label_Degree_C = (gcnew System::Windows::Forms::Label());
    this->label_ToleranceOrientation = (gcnew System::Windows::Forms::Label());
    this->tb_ToleranceOrientation = (gcnew System::Windows::Forms::TextBox());
    this->tb_ToleranceOrientation_Act = (gcnew System::Windows::Forms::TextBox());
    this->label_Degree_ = (gcnew System::Windows::Forms::Label());
    this->SuspendLayout();
    // 
    // btn_Set
    // 
    this->btn_Set->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_Set->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_Set->Location = System::Drawing::Point(674, 371);
    this->btn_Set->Name = L"btn_Set";
    this->btn_Set->Size = System::Drawing::Size(110, 50);
    this->btn_Set->TabIndex = 11;
    this->btn_Set->Text = L"Set";
    this->btn_Set->UseVisualStyleBackColor = false;
    this->btn_Set->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_Set_Click);
    // 
    // tb_Velo
    // 
    this->tb_Velo->Location = System::Drawing::Point(274, 82);
    this->tb_Velo->Name = L"tb_Velo";
    this->tb_Velo->Size = System::Drawing::Size(100, 20);
    this->tb_Velo->TabIndex = 5;
    this->tb_Velo->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Orientation_A
    // 
    this->tb_Orientation_A->Location = System::Drawing::Point(16, 82);
    this->tb_Orientation_A->Name = L"tb_Orientation_A";
    this->tb_Orientation_A->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_A->TabIndex = 1;
    this->tb_Orientation_A->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_ToleranceApprox
    // 
    this->tb_ToleranceApprox->Location = System::Drawing::Point(274, 181);
    this->tb_ToleranceApprox->Name = L"tb_ToleranceApprox";
    this->tb_ToleranceApprox->Size = System::Drawing::Size(100, 20);
    this->tb_ToleranceApprox->TabIndex = 7;
    this->tb_ToleranceApprox->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_SampleSize
    // 
    this->tb_SampleSize->Location = System::Drawing::Point(274, 130);
    this->tb_SampleSize->Name = L"tb_SampleSize";
    this->tb_SampleSize->Size = System::Drawing::Size(100, 20);
    this->tb_SampleSize->TabIndex = 6;
    this->tb_SampleSize->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // cb_Velo
    // 
    this->cb_Velo->AutoSize = true;
    this->cb_Velo->Location = System::Drawing::Point(636, 189);
    this->cb_Velo->Name = L"cb_Velo";
    this->cb_Velo->Size = System::Drawing::Size(147, 17);
    this->cb_Velo->TabIndex = 9;
    this->cb_Velo->Text = L"Geschwindigkeit aus .csv";
    this->cb_Velo->UseVisualStyleBackColor = true;
    this->cb_Velo->CheckedChanged += gcnew System::EventHandler(this, &RoboPathForm::cb_Velo_CheckChanged);
    // 
    // cb_Orientation
    // 
    this->cb_Orientation->AutoSize = true;
    this->cb_Orientation->Location = System::Drawing::Point(636, 170);
    this->cb_Orientation->Name = L"cb_Orientation";
    this->cb_Orientation->Size = System::Drawing::Size(126, 17);
    this->cb_Orientation->TabIndex = 8;
    this->cb_Orientation->Text = L"Orientierung aus .csv";
    this->cb_Orientation->UseVisualStyleBackColor = true;
    this->cb_Orientation->CheckedChanged += gcnew System::EventHandler(this, &RoboPathForm::cb_Orientation_CheckChanged);
    // 
    // label_Velo
    // 
    this->label_Velo->AutoSize = true;
    this->label_Velo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Velo->Location = System::Drawing::Point(270, 59);
    this->label_Velo->Name = L"label_Velo";
    this->label_Velo->Size = System::Drawing::Size(140, 20);
    this->label_Velo->TabIndex = 0;
    this->label_Velo->Text = L"Geschwindigkeit";
    // 
    // label_Orientation
    // 
    this->label_Orientation->AutoSize = true;
    this->label_Orientation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Orientation->Location = System::Drawing::Point(12, 56);
    this->label_Orientation->Name = L"label_Orientation";
    this->label_Orientation->Size = System::Drawing::Size(108, 20);
    this->label_Orientation->TabIndex = 0;
    this->label_Orientation->Text = L"Orientierung";
    // 
    // label_ToleranceApprox
    // 
    this->label_ToleranceApprox->AutoSize = true;
    this->label_ToleranceApprox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_ToleranceApprox->Location = System::Drawing::Point(270, 157);
    this->label_ToleranceApprox->Name = L"label_ToleranceApprox";
    this->label_ToleranceApprox->Size = System::Drawing::Size(228, 20);
    this->label_ToleranceApprox->TabIndex = 13;
    this->label_ToleranceApprox->Text = L"Toleranz der Approximation";
    // 
    // label_SampleSize
    // 
    this->label_SampleSize->AutoSize = true;
    this->label_SampleSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_SampleSize->Location = System::Drawing::Point(270, 106);
    this->label_SampleSize->Name = L"label_SampleSize";
    this->label_SampleSize->Size = System::Drawing::Size(205, 20);
    this->label_SampleSize->TabIndex = 14;
    this->label_SampleSize->Text = L"Anzahl Mittelwertbildung";
    // 
    // btn_OpenCSV
    // 
    this->btn_OpenCSV->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_OpenCSV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_OpenCSV->Location = System::Drawing::Point(674, 315);
    this->btn_OpenCSV->Name = L"btn_OpenCSV";
    this->btn_OpenCSV->Size = System::Drawing::Size(110, 50);
    this->btn_OpenCSV->TabIndex = 10;
    this->btn_OpenCSV->Text = L".csv öffnen";
    this->btn_OpenCSV->UseVisualStyleBackColor = false;
    this->btn_OpenCSV->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_OpenCSV_Click);
    // 
    // btn_Start
    // 
    this->btn_Start->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_Start->Location = System::Drawing::Point(674, 427);
    this->btn_Start->Name = L"btn_Start";
    this->btn_Start->Size = System::Drawing::Size(110, 50);
    this->btn_Start->TabIndex = 12;
    this->btn_Start->Text = L"Start";
    this->btn_Start->UseVisualStyleBackColor = false;
    this->btn_Start->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_Start_Click);
    // 
    // tb_Velo_Act
    // 
    this->tb_Velo_Act->AcceptsTab = true;
    this->tb_Velo_Act->Enabled = false;
    this->tb_Velo_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Velo_Act->Location = System::Drawing::Point(380, 82);
    this->tb_Velo_Act->Name = L"tb_Velo_Act";
    this->tb_Velo_Act->ReadOnly = true;
    this->tb_Velo_Act->Size = System::Drawing::Size(100, 20);
    this->tb_Velo_Act->TabIndex = 17;
    // 
    // tb_Orientation_Act_A
    // 
    this->tb_Orientation_Act_A->Enabled = false;
    this->tb_Orientation_Act_A->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_Orientation_Act_A->Location = System::Drawing::Point(122, 82);
    this->tb_Orientation_Act_A->Name = L"tb_Orientation_Act_A";
    this->tb_Orientation_Act_A->ReadOnly = true;
    this->tb_Orientation_Act_A->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_Act_A->TabIndex = 18;
    // 
    // tb_ToleranceApprox_Act
    // 
    this->tb_ToleranceApprox_Act->Enabled = false;
    this->tb_ToleranceApprox_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_ToleranceApprox_Act->Location = System::Drawing::Point(383, 181);
    this->tb_ToleranceApprox_Act->Name = L"tb_ToleranceApprox_Act";
    this->tb_ToleranceApprox_Act->ReadOnly = true;
    this->tb_ToleranceApprox_Act->Size = System::Drawing::Size(100, 20);
    this->tb_ToleranceApprox_Act->TabIndex = 19;
    // 
    // tb_SampleSize_Act
    // 
    this->tb_SampleSize_Act->Enabled = false;
    this->tb_SampleSize_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_SampleSize_Act->Location = System::Drawing::Point(380, 130);
    this->tb_SampleSize_Act->Name = L"tb_SampleSize_Act";
    this->tb_SampleSize_Act->ReadOnly = true;
    this->tb_SampleSize_Act->Size = System::Drawing::Size(100, 20);
    this->tb_SampleSize_Act->TabIndex = 20;
    // 
    // label_ActValues
    // 
    this->label_ActValues->AutoSize = true;
    this->label_ActValues->Location = System::Drawing::Point(126, 63);
    this->label_ActValues->Name = L"label_ActValues";
    this->label_ActValues->Size = System::Drawing::Size(85, 13);
    this->label_ActValues->TabIndex = 21;
    this->label_ActValues->Text = L"Geladene Werte";
    // 
    // tb_Version
    // 
    this->tb_Version->Enabled = false;
    this->tb_Version->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Version->Location = System::Drawing::Point(691, 539);
    this->tb_Version->Name = L"tb_Version";
    this->tb_Version->ReadOnly = true;
    this->tb_Version->Size = System::Drawing::Size(71, 20);
    this->tb_Version->TabIndex = 22;
    this->tb_Version->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    // 
    // openFileDialog_CSV
    // 
    this->openFileDialog_CSV->Filter = L"csv files (*.csv) |*.csv";
    this->openFileDialog_CSV->InitialDirectory = L"c:\\";
    this->openFileDialog_CSV->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &RoboPathForm::openFileDialog_CSV_FileOk);
    // 
    // tb_Log
    // 
    this->tb_Log->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Log->Location = System::Drawing::Point(3, 212);
    this->tb_Log->Name = L"tb_Log";
    this->tb_Log->ReadOnly = true;
    this->tb_Log->Size = System::Drawing::Size(665, 347);
    this->tb_Log->TabIndex = 23;
    this->tb_Log->TabStop = false;
    this->tb_Log->Text = L"";
    // 
    // tb_Orientation_Act_C
    // 
    this->tb_Orientation_Act_C->Enabled = false;
    this->tb_Orientation_Act_C->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_Orientation_Act_C->Location = System::Drawing::Point(122, 134);
    this->tb_Orientation_Act_C->Name = L"tb_Orientation_Act_C";
    this->tb_Orientation_Act_C->ReadOnly = true;
    this->tb_Orientation_Act_C->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_Act_C->TabIndex = 24;
    // 
    // tb_Orientation_Act_B
    // 
    this->tb_Orientation_Act_B->Enabled = false;
    this->tb_Orientation_Act_B->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_Orientation_Act_B->Location = System::Drawing::Point(122, 108);
    this->tb_Orientation_Act_B->Name = L"tb_Orientation_Act_B";
    this->tb_Orientation_Act_B->ReadOnly = true;
    this->tb_Orientation_Act_B->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_Act_B->TabIndex = 25;
    // 
    // tb_Orientation_C
    // 
    this->tb_Orientation_C->Location = System::Drawing::Point(16, 134);
    this->tb_Orientation_C->Name = L"tb_Orientation_C";
    this->tb_Orientation_C->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_C->TabIndex = 3;
    this->tb_Orientation_C->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Orientation_B
    // 
    this->tb_Orientation_B->Location = System::Drawing::Point(16, 108);
    this->tb_Orientation_B->Name = L"tb_Orientation_B";
    this->tb_Orientation_B->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_B->TabIndex = 2;
    this->tb_Orientation_B->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // label_C
    // 
    this->label_C->AutoSize = true;
    this->label_C->Location = System::Drawing::Point(0, 137);
    this->label_C->Name = L"label_C";
    this->label_C->Size = System::Drawing::Size(14, 13);
    this->label_C->TabIndex = 28;
    this->label_C->Text = L"C";
    // 
    // label_B
    // 
    this->label_B->AutoSize = true;
    this->label_B->Location = System::Drawing::Point(0, 111);
    this->label_B->Name = L"label_B";
    this->label_B->Size = System::Drawing::Size(14, 13);
    this->label_B->TabIndex = 29;
    this->label_B->Text = L"B";
    // 
    // label_A
    // 
    this->label_A->AutoSize = true;
    this->label_A->Location = System::Drawing::Point(0, 85);
    this->label_A->Name = L"label_A";
    this->label_A->Size = System::Drawing::Size(14, 13);
    this->label_A->TabIndex = 33;
    this->label_A->Text = L"A";
    // 
    // label_Geschwindigkeit_Einheit_Wert
    // 
    this->label_Geschwindigkeit_Einheit_Wert->AutoSize = true;
    this->label_Geschwindigkeit_Einheit_Wert->Location = System::Drawing::Point(486, 85);
    this->label_Geschwindigkeit_Einheit_Wert->Name = L"label_Geschwindigkeit_Einheit_Wert";
    this->label_Geschwindigkeit_Einheit_Wert->Size = System::Drawing::Size(25, 13);
    this->label_Geschwindigkeit_Einheit_Wert->TabIndex = 35;
    this->label_Geschwindigkeit_Einheit_Wert->Text = L"m/s";
    // 
    // label_Toleranz_Wert
    // 
    this->label_Toleranz_Wert->AutoSize = true;
    this->label_Toleranz_Wert->Location = System::Drawing::Point(489, 183);
    this->label_Toleranz_Wert->Name = L"label_Toleranz_Wert";
    this->label_Toleranz_Wert->Size = System::Drawing::Size(23, 13);
    this->label_Toleranz_Wert->TabIndex = 38;
    this->label_Toleranz_Wert->Text = L"mm";
    // 
    // label_Header
    // 
    this->label_Header->AutoSize = true;
    this->label_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Header->Location = System::Drawing::Point(213, 9);
    this->label_Header->Name = L"label_Header";
    this->label_Header->Size = System::Drawing::Size(384, 39);
    this->label_Header->TabIndex = 40;
    this->label_Header->Text = L"RoboPath Konfigurator";
    // 
    // btn_Reset
    // 
    this->btn_Reset->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_Reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_Reset->Location = System::Drawing::Point(674, 483);
    this->btn_Reset->Name = L"btn_Reset";
    this->btn_Reset->Size = System::Drawing::Size(110, 50);
    this->btn_Reset->TabIndex = 13;
    this->btn_Reset->Text = L"Zurücksetzen";
    this->btn_Reset->UseVisualStyleBackColor = false;
    this->btn_Reset->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_Reset_Click);
    // 
    // saveFileDialog_CSV
    // 
    this->saveFileDialog_CSV->Filter = L"source files (*.src) |*.src";
    this->saveFileDialog_CSV->InitialDirectory = L"c:\\";
    this->saveFileDialog_CSV->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &RoboPathForm::saveFileDialog_CSV_FileOk);
    // 
    // label_Degree_A
    // 
    this->label_Degree_A->AutoSize = true;
    this->label_Degree_A->Location = System::Drawing::Point(228, 82);
    this->label_Degree_A->Name = L"label_Degree_A";
    this->label_Degree_A->Size = System::Drawing::Size(11, 13);
    this->label_Degree_A->TabIndex = 41;
    this->label_Degree_A->Text = L"°";
    // 
    // label_Degree_B
    // 
    this->label_Degree_B->AutoSize = true;
    this->label_Degree_B->Location = System::Drawing::Point(228, 108);
    this->label_Degree_B->Name = L"label_Degree_B";
    this->label_Degree_B->Size = System::Drawing::Size(11, 13);
    this->label_Degree_B->TabIndex = 42;
    this->label_Degree_B->Text = L"°";
    // 
    // label_Degree_C
    // 
    this->label_Degree_C->AutoSize = true;
    this->label_Degree_C->Location = System::Drawing::Point(228, 134);
    this->label_Degree_C->Name = L"label_Degree_C";
    this->label_Degree_C->Size = System::Drawing::Size(11, 13);
    this->label_Degree_C->TabIndex = 43;
    this->label_Degree_C->Text = L"°";
    // 
    // label_ToleranceOrientation
    // 
    this->label_ToleranceOrientation->AutoSize = true;
    this->label_ToleranceOrientation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_ToleranceOrientation->Location = System::Drawing::Point(12, 157);
    this->label_ToleranceOrientation->Name = L"label_ToleranceOrientation";
    this->label_ToleranceOrientation->Size = System::Drawing::Size(213, 20);
    this->label_ToleranceOrientation->TabIndex = 44;
    this->label_ToleranceOrientation->Text = L"Toleranz der Orientierung";
    // 
    // tb_ToleranceOrientation
    // 
    this->tb_ToleranceOrientation->Enabled = false;
    this->tb_ToleranceOrientation->Location = System::Drawing::Point(16, 180);
    this->tb_ToleranceOrientation->Name = L"tb_ToleranceOrientation";
    this->tb_ToleranceOrientation->Size = System::Drawing::Size(100, 20);
    this->tb_ToleranceOrientation->TabIndex = 4;
    this->tb_ToleranceOrientation->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_ToleranceOrientation_Act
    // 
    this->tb_ToleranceOrientation_Act->Enabled = false;
    this->tb_ToleranceOrientation_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_ToleranceOrientation_Act->Location = System::Drawing::Point(122, 180);
    this->tb_ToleranceOrientation_Act->Name = L"tb_ToleranceOrientation_Act";
    this->tb_ToleranceOrientation_Act->ReadOnly = true;
    this->tb_ToleranceOrientation_Act->Size = System::Drawing::Size(100, 20);
    this->tb_ToleranceOrientation_Act->TabIndex = 46;
    // 
    // label_Degree_
    // 
    this->label_Degree_->AutoSize = true;
    this->label_Degree_->Location = System::Drawing::Point(228, 180);
    this->label_Degree_->Name = L"label_Degree_";
    this->label_Degree_->Size = System::Drawing::Size(11, 13);
    this->label_Degree_->TabIndex = 47;
    this->label_Degree_->Text = L"°";
    // 
    // RoboPathForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::ButtonShadow;
    this->ClientSize = System::Drawing::Size(784, 561);
    this->Controls->Add(this->label_Degree_);
    this->Controls->Add(this->tb_ToleranceOrientation_Act);
    this->Controls->Add(this->tb_ToleranceOrientation);
    this->Controls->Add(this->label_ToleranceOrientation);
    this->Controls->Add(this->label_Degree_C);
    this->Controls->Add(this->label_Degree_B);
    this->Controls->Add(this->label_Degree_A);
    this->Controls->Add(this->btn_Reset);
    this->Controls->Add(this->label_Header);
    this->Controls->Add(this->label_Toleranz_Wert);
    this->Controls->Add(this->label_Geschwindigkeit_Einheit_Wert);
    this->Controls->Add(this->label_A);
    this->Controls->Add(this->label_B);
    this->Controls->Add(this->label_C);
    this->Controls->Add(this->tb_Orientation_B);
    this->Controls->Add(this->tb_Orientation_C);
    this->Controls->Add(this->tb_Orientation_Act_B);
    this->Controls->Add(this->tb_Orientation_Act_C);
    this->Controls->Add(this->tb_Log);
    this->Controls->Add(this->tb_Version);
    this->Controls->Add(this->label_ActValues);
    this->Controls->Add(this->tb_SampleSize_Act);
    this->Controls->Add(this->tb_ToleranceApprox_Act);
    this->Controls->Add(this->tb_Orientation_Act_A);
    this->Controls->Add(this->tb_Velo_Act);
    this->Controls->Add(this->btn_Start);
    this->Controls->Add(this->btn_OpenCSV);
    this->Controls->Add(this->label_SampleSize);
    this->Controls->Add(this->label_ToleranceApprox);
    this->Controls->Add(this->label_Orientation);
    this->Controls->Add(this->label_Velo);
    this->Controls->Add(this->cb_Orientation);
    this->Controls->Add(this->cb_Velo);
    this->Controls->Add(this->tb_SampleSize);
    this->Controls->Add(this->tb_ToleranceApprox);
    this->Controls->Add(this->tb_Orientation_A);
    this->Controls->Add(this->tb_Velo);
    this->Controls->Add(this->btn_Set);
    this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
    this->MaximizeBox = false;
    this->Name = L"RoboPathForm";
    this->Text = L"RoboPath";
    this->ResumeLayout(false);
    this->PerformLayout();

}

#pragma region EventHandler
//Ereignis, nachdem die Velo Checkbox un/checked wird
System::Void UserInterface::RoboPathForm::cb_Velo_CheckChanged(System::Object^ sender, System::EventArgs^ e) {
    //Wenn die Checkbock true ist, möchte der Benutzer die Geschwindigkeit aus der CSV benutzen.
    //Somit wird der Inhalt der beiden Velo Textbox gelöscht und disabled.
    if (this->cb_Velo->Checked) {

        this->tb_Velo->Clear();

        this->tb_Velo->Enabled = false;

        this->tb_Velo_Act->Clear();

        //Der Benutzer wird nochmal gezwungen den Set Button zu drücken, da der aktuell geladene Wert der Checkbox nicht ersichtlich ist
        bSetted = false;
    }
    //Wenn die Checkbox false ist, möchte der Benutzer die Geschwindigkeit selbst definieren.
    //Die TextBox wird enabled
    else {
        this->tb_Velo->Enabled = true;
        //Der Benutzer wird nochmal gezwungen den Set Button zu drücken, da der aktuell geladene Wert der Checkbox nicht ersichtlich ist
        bSetted = false;
    }
}
//Ereignis, nachdem die Orientation Checbox un/checked wird
System::Void UserInterface::RoboPathForm::cb_Orientation_CheckChanged(System::Object^ sender, System::EventArgs^ e) {
    //Wenn die Orientation Checkbox true ist, möchte der Benutzer die Orientierung aus der CSV benutzen
    //Somit wird der Inhalt alles Orientation Textboxen gelöscht und disabled
    if (this->cb_Orientation->Checked) {
        
        this->tb_Orientation_A->Clear();
        this->tb_Orientation_B->Clear();
        this->tb_Orientation_C->Clear();

        this->tb_Orientation_A->Enabled = false;
        this->tb_Orientation_B->Enabled = false;
        this->tb_Orientation_C->Enabled = false;
        this->tb_ToleranceOrientation->Enabled = true;

        this->tb_Orientation_Act_A->Clear();
        this->tb_Orientation_Act_B->Clear();
        this->tb_Orientation_Act_C->Clear();
        //Der Benutzer wird nochmal gezwungen den Set Button zu drücken, da der aktuell geladene Wert der Checkbox nicht ersichtlich ist
        bSetted = false;
    }
    //Wenn die Checkbox false ist, möchte der Benutzer die Orientierung selbst bestimmen
    //Somit werden alle Orientation Textboxen enabled
    else {
        this->tb_Orientation_A->Enabled = true;
        this->tb_Orientation_B->Enabled = true;
        this->tb_Orientation_C->Enabled = true;
        this->tb_ToleranceOrientation->Enabled = false;

        this->tb_ToleranceOrientation->Clear();

        this->tb_ToleranceOrientation_Act->Clear();
        //Der Benutzer wird nochmal gezwungen den Set Button zu drücken, da der aktuell geladene Wert der Checkbox nicht ersichtlich ist
        bSetted = false;
    }
}
//Eregnis, nachdem der Set Button geklickt worden ist. Damit möchte der Nutzer alle eingegebene Werte setzen/speichern.
System::Void UserInterface::RoboPathForm::btn_Set_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        //Fehlerabfrage
        //Falls einer der Textboxen leer ist, wird emittelt welche und eine entsprechende Fehlermeldung wird ausgegeben
        //Hier werden alle Boxen gleichzeitig abgefragt.
        if ((this->cb_Velo->Checked == false
            && this->tb_Velo->Text == "")
            || (this->cb_Orientation->Checked == false
                && (this->tb_Orientation_A->Text == ""
                    || this->tb_Orientation_B->Text == ""
                    || this->tb_Orientation_C->Text == ""))
            || this->tb_ToleranceApprox->Text == ""
            || this->tb_SampleSize->Text == ""
            || Datastore->GetFilePath() == ""
            || (this->cb_Orientation->Checked == true
                && this->tb_ToleranceOrientation->Text == "")) {
            //Liste, zum Sammeln der Fehlermeldungen
            System::Collections::Generic::List<System::String^> lstErrorMessages;

            //Fehler: Es wurde keine CSV geladen
            if (Datastore->GetFilePath() == "") {
                lstErrorMessages.Add("Laden Sie eine CSV-Datei");
            }

            //Fehler: Kein Wert in der Velo Textbox
            if (this->cb_Velo->Checked == false
                && this->tb_Velo->Text == "") {
                lstErrorMessages.Add("Geben Sie eine Geschwindigkeit ein");
            }

            //Fehler: Kein/e Wert/e in den Orientation Textboxen
            if (this->cb_Orientation->Checked == false
                && (this->tb_Orientation_A->Text == ""
                    || this->tb_Orientation_B->Text == ""
                    || this->tb_Orientation_C->Text == "")) {
                //Fehler: Kein Wert in der Orientation Textbox A
                if (this->tb_Orientation_A->Text == "") {
                    lstErrorMessages.Add("Geben Sie einen Wert in der Orientierung \"A\" ein");
                }
                //Fehler: Kein Wert in der Orientation Textbox B
                if (this->tb_Orientation_B->Text == "") {
                    lstErrorMessages.Add("Geben Sie einen Wert in der Orientierung \"B\" ein");
                }
                //Fehler: Kein Wert in der Orientation Textbox C
                if (this->tb_Orientation_C->Text == "") {
                    lstErrorMessages.Add("Geben Sie einen Wert in der Orientierung \"C\" ein");
                }
            }

            //Fehler: Kein Wert in der Tolerance Textbox
            if (this->tb_ToleranceApprox->Text == "") {
                lstErrorMessages.Add("Geben Sie eine Toleranz für die Approximation ein");
            }

            //Fehler: Kein Wert in der Average Textbox
            if (this->tb_SampleSize->Text == "") {
                lstErrorMessages.Add("Geben Sie an über wie viele Datensätze ein Mittelwert gebildet werden soll");
            }

            if (this->cb_Orientation->Checked == true
                && this->tb_ToleranceOrientation->Text == "") {
                lstErrorMessages.Add("Geben Sie eine Toleranz für die Orientierung ein");
            }

            //Alle Fehlermeldungen wurden in einer Liste aufgenommen und werden jetzt in einen String aneinandergehängt um diesen dann
            //im Logfenster und in einem Fehlerfenster auszugeben
            System::String^ sErrorMessage = "Folgende Fehler sind aufgetreten:\n";

            for (int i = 0; i < lstErrorMessages.Count; i++) {
                sErrorMessage = sErrorMessage + "\n" + lstErrorMessages[i];
            }
            //Ausgabe im Logfesnter
            this->AppendLog(sErrorMessage + "\n\n");
            //Ausgabe im Fehlerfenster
            this->ShowErrorWindow(sErrorMessage);
        }

        //Falls alle Daten ausgefüllt worden sind, werden diese in der/dem dafür erstellten Klasse/Objekt gespeichert
        else {
            if (this->cb_Velo->Checked == false) {
                //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
                Datastore->SetVelo(Double::Parse(this->tb_Velo->Text));
            }

            if (this->cb_Orientation->Checked == false) {
                //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
                Datastore->SetOrientationA(Double::Parse(this->tb_Orientation_A->Text));
                Datastore->SetOrientationB(Double::Parse(this->tb_Orientation_B->Text));
                Datastore->SetOrientationC(Double::Parse(this->tb_Orientation_C->Text));
            }

            if (this->cb_Orientation->Checked == true) {
                Datastore->SetToleranceOrientation(Double::Parse(this->tb_ToleranceOrientation->Text));
            }

            //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
            Datastore->SetToleranceApprox(Double::Parse(this->tb_ToleranceApprox->Text));
            Datastore->SetSampleSize(System::Convert::ToInt32(this->tb_SampleSize->Text));

            //Der Status der Checkboxen wird übergeben
            Datastore->SetUserDefVelo(this->cb_Velo->Checked);
            Datastore->SetUserDefOrientation(this->cb_Orientation->Checked);

            //Die gespeicherten Werte werden in den dafür vorgesehenen Textboxen übernommen, um die aktuell geladenen Werte anzuzeigen
            this->tb_Velo_Act->Text = this->tb_Velo->Text;
            this->tb_Orientation_Act_A->Text = this->tb_Orientation_A->Text;
            this->tb_Orientation_Act_B->Text = this->tb_Orientation_B->Text;
            this->tb_Orientation_Act_C->Text = this->tb_Orientation_C->Text;
            this->tb_ToleranceApprox_Act->Text = this->tb_ToleranceApprox->Text;
            this->tb_SampleSize_Act->Text = this->tb_SampleSize->Text;
            this->tb_ToleranceOrientation_Act->Text = this->tb_ToleranceOrientation->Text;

            //Zusätzlich gibt es noch eine Meldung über die erfolgreiche Speicherung
            this->AppendLog("Laden der Werte erfolgreich\n\n");

            //Gibt den Start Button frei
            bSetted = true;
        }
    }
    catch (System::Exception^ e) {
        this->AppendLog("Fehler beim Laden der Werte:\n" + e->Message + "\n");
    }
}
//Ereignis, wenn der Reset Button geklickt wird
System::Void UserInterface::RoboPathForm::btn_Reset_Click(System::Object^ sender, System::EventArgs^ e) {
    try
    {
        //Fenster, in dem der Nutzer nochmals gefragt wird, ob wirklich alle Daten gelöscht werden sollen
        //Soll verhindern, dass durch fäschliches anklicken gleich alles weg ist
        System::Boolean bYesNo = this->ShowYesNoWindow("Sollen alle Daten gelöscht werden?");
        //Je nachdem was der Nutzer angeklickt hat, wird alles gelöscht oder auch nicht
        if (bYesNo) {
            //Alle gespeicherten Werte werden zurückgesetzt
            Datastore->Reset();
            //Die Oberfläche wird zurückgesetzt
            this->ResetAll();
        }
        else {
            return;
        }
    }
    catch (System::Exception^ e)
    {
        this->AppendLog("Fehler beim Zurücksetzen der Werte:\n" + e->Message + "\n");
    }
}
//Ereignis, nachdem der .csv öffnen Button geklickt wird
System::Void UserInterface::RoboPathForm::btn_OpenCSV_Click(System::Object^ sender, System::EventArgs^ e) {
    //Es wird ein Fenster angezeigt, in dem Dateien auswählen kann
    openFileDialog_CSV->ShowDialog();
}
//Ereignis, dass nach dem öffnen einer Datei eintritt
System::Void UserInterface::RoboPathForm::openFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
    //Falls eine valide csv Datei geladen worden ist, wird der Pfad der Datei im Log ausgegeben und gespeichert
    this->AppendLog("Folgende .csv ist geladen: " + openFileDialog_CSV->FileName + "\n\n");
    Datastore->SetFilePath(openFileDialog_CSV->FileName);
}
//Ereignis, dass nachdem ein gültiger Speicherpfad gewählt worden ist
System::Void UserInterface::RoboPathForm::saveFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
    //Der Speicherort mit Dateiname wird im Log ausgegeben und der Speicherpfad gespeichert
    Datastore->SetSavePath(saveFileDialog_CSV->FileName);
}
//Ereignis, nachdem der Start Button geklickt wird
System::Void UserInterface::RoboPathForm::btn_Start_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        //Boolsche Werte, die die erfolgreiche Abbarbeitung eines Abschnitts widerspiegeln
        System::Boolean bReadDone = false;
        System::Boolean bFilteredDone = false;
        System::Boolean bApproxedDone = false;
        System::Boolean bCalcOrientationDone = false;
        System::Boolean bVeloCalcDone = false;
         //Wenn der Set Button gedrückt und alle Werte erfolgreich geladen worden sind, ist bSetted true
        if (bSetted) {
            //Ausgewählte Datei wird eingelesen
            this->AppendLog("CSV wird eingelesen\n\n");
            System::Threading::Thread::Sleep(500);
            Logic::ReadCSV^ Reader = gcnew Logic::ReadCSV(this);
            bReadDone = Reader->ReadAndSaveCSV(Datastore);
            delete Reader;
            //Datensätze werden über die nutzerdefinierte Samplegröße gemittelt
            //Falls die Samplegröße == 1 ist, dann muss nicht gemittelt werden
            if (Datastore->GetSampleSize() > 1 && bReadDone) {
                this->AppendLog("Daten werden gefiltert\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::SampleFilter^ Filter = gcnew Logic::SampleFilter(this);
                bFilteredDone = Filter->FilterData(Datastore);
                delete Filter;
            }
            //Falls die Samplegröße ==1 ist, kommt man hier rein. Hier werden die Listen übergeben, damit die
            //Reihenfolge noch funktioniert
            else if (Datastore->GetSampleSize() <= 1 && bReadDone) {
                bFilteredDone = true;
                Datastore->SetlstFilteredPathData(Datastore->GetlstRawPathData());
            }
            //Falls nichts zutrifft ist etwas schief gelaufen. Eine enstprechende Fehlermeldung sollte durch die vorher durchgelaufenen Funktionen
            //im Log erzeugt worden sein
            else {
                return;
            }
            //Datensätze werden über die nutzerdefinierte Toleranz wegapproximiert
            if (Datastore->GetToleranceApprox() != 0 && bFilteredDone) {
                this->AppendLog("Daten werden approximiert\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::DPAprox^ DPAproxer = gcnew Logic::DPAprox(this);
                bApproxedDone =  DPAproxer->approx(Datastore);
                delete DPAproxer;
            }
            //Wenn die Toleranz == 0 ist, muss nicht aproximiert werden. Hier werden die Listen übergeben, damit die
            //Reihenfolge noch funktioniert
            else if (Datastore->GetToleranceApprox() == 0 && bFilteredDone) {
                bApproxedDone = true;
                Datastore->SetlstAproxedPathData(Datastore->GetlstFilteredPathData());
            }
            //Falls nichts zutrifft ist etwas schief gelaufen. Eine enstprechende Fehlermeldung sollte durch die vorher durchgelaufenen Funktionen
            //im Log erzeugt worden sein
            else {
                return;
            }
            //Die Geschwindigkeit wird aus der CSV berechnet
            if (Datastore->GetUserDefVelo() && bApproxedDone) {
                this->AppendLog("Geschwindigkeit wird berechnet\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::VeloCalc^ VeloCalculation = gcnew Logic::VeloCalc(this);
                bVeloCalcDone = VeloCalculation->VeloCalcCSV(Datastore);
                delete VeloCalculation;
            }
            //Wenn der Nutzer die Geschwindigkeit selbst gewählt hat, wird die Ablaufkette weitergeführt
            else if (!Datastore->GetUserDefVelo() && bApproxedDone) {
                bVeloCalcDone = true;
            }
            else {
                return;
            }
            //Die Orientierung wird aus der CSV berechnet
            if (Datastore->GetUserDefOrientation() && bVeloCalcDone) {
                this->AppendLog("Orientierung wird berechnet\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::CalcOrientation^ OCalculation = gcnew Logic::CalcOrientation(this);
                bCalcOrientationDone = OCalculation->CalcRotMatToEulerABC(Datastore);
                delete OCalculation;
            }
            //Wenn der Nutzer die Geschwindigkeit selbst gewählt hat, wird die Ablaufkette weitergeführt
            else if (!Datastore->GetUserDefOrientation() && bVeloCalcDone) {
                bCalcOrientationDone = true;
            }
            else {
                return;
            }
            //Die Datei wird erzeugt und unter dem nutzerdefinierten Pfad gespeichert
            if (bCalcOrientationDone) {
                this->AppendLog("Datei wird erstellt\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::CreateKUKAFile^ KUKACreater = gcnew Logic::CreateKUKAFile(this);
                KUKACreater->WriteKUKA(Datastore);
                delete KUKACreater;
            }
            /*if (bCalcOrientationDone) {
                this->AppendLog("Datei wird erstellt\n\n");
                System::Threading::Thread::Sleep(500);
                Logic::WriteCSVForMatLab^ FileCreater = gcnew Logic::WriteCSVForMatLab(this);
                FileCreater->WriteForMatLab(Datastore);
                delete FileCreater;
            }*/

            //Nachdem alles durchgelaufen ist, wird alles resettet
            this->ResetAll();
            System::Windows::Forms::Application::DoEvents();
            Datastore->Reset();
        }
        //Fehlermeldung, wenn der Set Button noch nicht gedrückt worden ist
        else
        {
            this->ShowErrorWindow("Der Set-Button wurde noch nicht gedrückt");
            this->AppendLog("Der Set-Button wurde noch nicht gedrückt\n\n");
        }
    }
    catch (System::Exception^ e) {
        this->AppendLog("Fehler beim Abarbeiten des Programms:\n" + e->Message + "\n\n");
    }
}
//Ereignis, nachdem ein Wert in irgendeine Textbox eingegeben wird und diese Textbox dann den Fokus verliert
System::Void UserInterface::RoboPathForm::ValidateInput(System::Object^ sender, System::EventArgs^ e) {
    //Die Textbox wird in einem Objekt gespeichert. Somit kann man mit dieser Funktion alle Textboxen anfangen
    TextBox^ tbCurrentTextBox = dynamic_cast<TextBox^>(sender);
    //Wenn gar nichts eingegeben wurde, passiert nichts
    if (tbCurrentTextBox->Text == "") {
        return;
    }
    //Man kann Gleitkommazahlen mit einem Punkt oder einem Komma eingeben. Gültig ist aber nur ein Komma.
    //Deswegen wird geprüft, ob der eingegebene Text ein Punkt beinhaltet. Falls ja, wird dieser durch ein Komma ersetzt
    if (tbCurrentTextBox->Text->Contains(".")) {
        tbCurrentTextBox->Text = tbCurrentTextBox->Text->Replace(".", ",");
    }
    if (tbCurrentTextBox->Name != "tb_SampleSize") {
        System::Double dInput;
        //Der eingegebene Text wird in ein double umgewandelt. Falls dies gelingt, wird der Float in der Variable dInput gespeichert
        if (System::Double::TryParse(tbCurrentTextBox->Text, dInput)) {
            //Da jede Textbox andere Bedingungen hat, wird ermittelt, um welche Textbox es sich handelt
            //Wenn es die Velo Textbox ist, darf der Wert nicht kleiner als 0 und größer als 2 sein.
            if (tbCurrentTextBox->Name == "tb_Velo") {
                if (dInput <= 0 || dInput > 2) {
                    //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                    this->ShowErrorWindow("Die Geschwindigkeit muss größer als 0 sein und darf maximal 2m/s betragen");
                    tbCurrentTextBox->Clear();
                }
                return;
            }
            if (tbCurrentTextBox->Name == "tb_ToleranceOrientation") {
                if (dInput < 0 || dInput > 360) {
                    //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                    this->ShowErrorWindow("Die Toleranz der Orientierung muss mindestens 0° sein und darf maximal 360° betragen");
                    tbCurrentTextBox->Clear();
                }
                return;
            }
            //Wenn es einer der Orientation Textboxen ist, darf der Winkel nur zwischen 0 und 360 grad betragen
            else if (tbCurrentTextBox->Name->Contains("tb_Orientation_")) {
                if (dInput < 0 || dInput > 360) {
                    //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                    this->ShowErrorWindow("Der Winkel muss zwischen 0° und 360° betragen");
                    tbCurrentTextBox->Text = "";
                }
                return;
            }
            //Wenn es die Tolerance Textbox ist, ...
            else if (tbCurrentTextBox->Name == "tb_ToleranceApprox") {
                if (dInput < 0 || dInput > 10) {
                    //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                    this->ShowErrorWindow("Die Toleranz der Approximation darf maximal 10mm betragen\nNegative Zahlen sind nicht erlaubt");
                    tbCurrentTextBox->Text = "";
                }
                return;
            }
            //Falls else erreicht wird, wurde eine Textbox hinzugefügt, ohne diese hier zu implementieren
            else {
                this->AppendLog("Unbekannte TextBox\n\n");
                return;
            }
        }
        //Falls der eingegebene Wert nicht in ein double umgewandelt werden kann, wird die folgende Fehlermeldung ausgegeben
        else {
            this->ShowErrorWindow("Es sind nur ganze oder Gleitkommezahlen erlaubt");
            tbCurrentTextBox->Text = "";
        }
    }
    //Die Textbox akzeptiert nur ganzue Zahlen
    else if (tbCurrentTextBox->Name == "tb_SampleSize") {
        int iInput;
        //Der eingegebene Text wird in ein int32 umgewandelt. Falls dies gelingt, wird der int in der Variable iInput gespeichert
        if (System::Int32::TryParse(tbCurrentTextBox->Text, iInput)) {
            if (iInput < 0 || iInput > 10) {
                //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                this->ShowErrorWindow("Die Anzahl an Datensätze, über die gemittelt werden darf, darf maximal 10 betragen\nNegative Zahlen sind nicht erlaubt");
                tbCurrentTextBox->Text = "";
            }
            return;
        }
        //Falls keine ganze Zahl eingegeben wurde, kommt die folgende Fehlermeldung
        else {
            this->ShowErrorWindow("Es sind nur ganze Zahlen erlaubt");
            tbCurrentTextBox->Text = "";
        }
    }
}
#pragma endregion EventHandler

#pragma region windows forms helper
//Standardfunktion für ein Fehlerfenster
System::Void UserInterface::RoboPathForm::ShowErrorWindow(String^ errorMessage)
{
    //Anzeige des Fehlerfensters. Mit OK kann man das Fesnter verlassen
    MessageBox::Show(errorMessage, "Fehler", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
//Standardfunktion für ein Entscheidungsfesnter
System::Boolean UserInterface::RoboPathForm::ShowYesNoWindow(System::String^ message)
{
    // Anzeigen des Ja-Nein-Fensters und Rückgabe der Benutzerantwort als boolchen Wert
    System::Windows::Forms::DialogResult DialogResult = MessageBox::Show(message, "", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
    return DialogResult == System::Windows::Forms::DialogResult::Yes;
}
#pragma endregion windows forms helper

#pragma region helpers
//Standardfunktion um Text im Log anzuzeigen
System::Void UserInterface::RoboPathForm::AppendLog(System::String^ sMessage) {
    //Ein Objekt, dass die aktuelle Uhrzeit enthält, wird erstellt
    System::DateTime ActTime = System::DateTime::Now;
    //Diese Uhrzeit wird noch in gewünschte Format gebracht
    System::String^ formattedTime = ActTime.ToString("HH:mm:ss");
    //Bevor der Text ausgegeben wird, wird die Uhrzeit darüber ausgebeben als Zeitstempel
    this->tb_Log->AppendText(formattedTime + "\n");
    //Ausgabe des Textes
    this->tb_Log->AppendText(sMessage);
    //Scrollen bis ganz unten
    this->tb_Log->ScrollToCaret();
    System::Windows::Forms::Application::DoEvents();
}
System::Void UserInterface::RoboPathForm::SetVersion() {
    //Es wird ein Objekt erstellt, in dem die Version gepfelgt wird
    Projectdata::VersionInfo Version;
    //Die Versionsnummer wird der Textbox zugewiesen
    this->tb_Version->Text = Version.getVersion();
}
//Funktion, um alles zurück zu setzen
System::Void UserInterface::RoboPathForm::ResetAll() {
    this->tb_Velo->Clear();
    this->tb_Velo_Act->Clear();
    this->tb_Orientation_A->Clear();
    this->tb_Orientation_Act_A->Clear();
    this->tb_Orientation_B->Clear();
    this->tb_Orientation_Act_B->Clear();
    this->tb_Orientation_C->Clear();
    this->tb_Orientation_Act_C->Clear();
    this->tb_ToleranceApprox->Clear();
    this->tb_ToleranceApprox_Act->Clear();
    this->tb_ToleranceOrientation->Clear();
    this->tb_ToleranceOrientation_Act->Clear();
    this->tb_SampleSize->Clear();
    this->tb_SampleSize_Act->Clear();
    /*this->tb_Log->Clear();*/
    bSetted = false;
}
#pragma endregion helpers
