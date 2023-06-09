#include "pch.h"
#include"RoboPathForm.h"
#include"ReadCSV.h"
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
//Dekonstruktor
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
    this->tb_Tolerance = (gcnew System::Windows::Forms::TextBox());
    this->tb_Average = (gcnew System::Windows::Forms::TextBox());
    this->cb_Velo = (gcnew System::Windows::Forms::CheckBox());
    this->cb_Orientation = (gcnew System::Windows::Forms::CheckBox());
    this->label_Velo = (gcnew System::Windows::Forms::Label());
    this->label_Orientation = (gcnew System::Windows::Forms::Label());
    this->label_Tolerance = (gcnew System::Windows::Forms::Label());
    this->label_Average = (gcnew System::Windows::Forms::Label());
    this->btn_OpenCSV = (gcnew System::Windows::Forms::Button());
    this->btn_Start = (gcnew System::Windows::Forms::Button());
    this->tb_Velo_Act = (gcnew System::Windows::Forms::TextBox());
    this->tb_Orientation_Act_A = (gcnew System::Windows::Forms::TextBox());
    this->tb_Tolerance_Act = (gcnew System::Windows::Forms::TextBox());
    this->tb_Average_Act = (gcnew System::Windows::Forms::TextBox());
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
    this->label_ActB = (gcnew System::Windows::Forms::Label());
    this->label_ActA = (gcnew System::Windows::Forms::Label());
    this->label_ActC = (gcnew System::Windows::Forms::Label());
    this->label_A = (gcnew System::Windows::Forms::Label());
    this->label_ActValues_ABC = (gcnew System::Windows::Forms::Label());
    this->label_Geschwindigkeit_Einheit_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Geschwindigkeit_Einheit_Act_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz_Act_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Header = (gcnew System::Windows::Forms::Label());
    this->btn_Reset = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // btn_Set
    // 
    this->btn_Set->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_Set->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_Set->Location = System::Drawing::Point(649, 213);
    this->btn_Set->Name = L"btn_Set";
    this->btn_Set->Size = System::Drawing::Size(110, 50);
    this->btn_Set->TabIndex = 9;
    this->btn_Set->Text = L"Set";
    this->btn_Set->UseVisualStyleBackColor = false;
    this->btn_Set->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_Set_Click);
    // 
    // tb_Velo
    // 
    this->tb_Velo->Location = System::Drawing::Point(169, 101);
    this->tb_Velo->Name = L"tb_Velo";
    this->tb_Velo->Size = System::Drawing::Size(100, 20);
    this->tb_Velo->TabIndex = 1;
    this->tb_Velo->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Orientation_A
    // 
    this->tb_Orientation_A->Location = System::Drawing::Point(319, 101);
    this->tb_Orientation_A->Name = L"tb_Orientation_A";
    this->tb_Orientation_A->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_A->TabIndex = 2;
    this->tb_Orientation_A->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Tolerance
    // 
    this->tb_Tolerance->Location = System::Drawing::Point(469, 101);
    this->tb_Tolerance->Name = L"tb_Tolerance";
    this->tb_Tolerance->Size = System::Drawing::Size(100, 20);
    this->tb_Tolerance->TabIndex = 5;
    this->tb_Tolerance->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Average
    // 
    this->tb_Average->Location = System::Drawing::Point(619, 101);
    this->tb_Average->Name = L"tb_Average";
    this->tb_Average->Size = System::Drawing::Size(100, 20);
    this->tb_Average->TabIndex = 6;
    this->tb_Average->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // cb_Velo
    // 
    this->cb_Velo->AutoSize = true;
    this->cb_Velo->Location = System::Drawing::Point(12, 175);
    this->cb_Velo->Name = L"cb_Velo";
    this->cb_Velo->Size = System::Drawing::Size(147, 17);
    this->cb_Velo->TabIndex = 7;
    this->cb_Velo->Text = L"Geschwindigkeit aus .csv";
    this->cb_Velo->UseVisualStyleBackColor = true;
    this->cb_Velo->CheckedChanged += gcnew System::EventHandler(this, &RoboPathForm::cb_Velo_CheckChanged);
    // 
    // cb_Orientation
    // 
    this->cb_Orientation->AutoSize = true;
    this->cb_Orientation->Location = System::Drawing::Point(12, 194);
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
    this->label_Velo->Location = System::Drawing::Point(165, 75);
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
    this->label_Orientation->Location = System::Drawing::Point(315, 75);
    this->label_Orientation->Name = L"label_Orientation";
    this->label_Orientation->Size = System::Drawing::Size(108, 20);
    this->label_Orientation->TabIndex = 0;
    this->label_Orientation->Text = L"Orientierung";
    // 
    // label_Tolerance
    // 
    this->label_Tolerance->AutoSize = true;
    this->label_Tolerance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Tolerance->Location = System::Drawing::Point(465, 75);
    this->label_Tolerance->Name = L"label_Tolerance";
    this->label_Tolerance->Size = System::Drawing::Size(78, 20);
    this->label_Tolerance->TabIndex = 13;
    this->label_Tolerance->Text = L"Toleranz";
    // 
    // label_Average
    // 
    this->label_Average->AutoSize = true;
    this->label_Average->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Average->Location = System::Drawing::Point(615, 75);
    this->label_Average->Name = L"label_Average";
    this->label_Average->Size = System::Drawing::Size(147, 20);
    this->label_Average->TabIndex = 14;
    this->label_Average->Text = L"Mittelwertfindung";
    // 
    // btn_OpenCSV
    // 
    this->btn_OpenCSV->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_OpenCSV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_OpenCSV->Location = System::Drawing::Point(12, 417);
    this->btn_OpenCSV->Name = L"btn_OpenCSV";
    this->btn_OpenCSV->Size = System::Drawing::Size(110, 50);
    this->btn_OpenCSV->TabIndex = 11;
    this->btn_OpenCSV->Text = L".csv öffnen";
    this->btn_OpenCSV->UseVisualStyleBackColor = false;
    this->btn_OpenCSV->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_OpenCSV_Click);
    // 
    // btn_Start
    // 
    this->btn_Start->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->btn_Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btn_Start->Location = System::Drawing::Point(12, 473);
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
    this->tb_Velo_Act->Location = System::Drawing::Point(169, 127);
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
    this->tb_Orientation_Act_A->Location = System::Drawing::Point(319, 191);
    this->tb_Orientation_Act_A->Name = L"tb_Orientation_Act_A";
    this->tb_Orientation_Act_A->ReadOnly = true;
    this->tb_Orientation_Act_A->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_Act_A->TabIndex = 18;
    // 
    // tb_Tolerance_Act
    // 
    this->tb_Tolerance_Act->Enabled = false;
    this->tb_Tolerance_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Tolerance_Act->Location = System::Drawing::Point(469, 127);
    this->tb_Tolerance_Act->Name = L"tb_Tolerance_Act";
    this->tb_Tolerance_Act->ReadOnly = true;
    this->tb_Tolerance_Act->Size = System::Drawing::Size(100, 20);
    this->tb_Tolerance_Act->TabIndex = 19;
    // 
    // tb_Average_Act
    // 
    this->tb_Average_Act->Enabled = false;
    this->tb_Average_Act->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Average_Act->Location = System::Drawing::Point(619, 127);
    this->tb_Average_Act->Name = L"tb_Average_Act";
    this->tb_Average_Act->ReadOnly = true;
    this->tb_Average_Act->Size = System::Drawing::Size(100, 20);
    this->tb_Average_Act->TabIndex = 20;
    // 
    // label_ActValues
    // 
    this->label_ActValues->AutoSize = true;
    this->label_ActValues->Location = System::Drawing::Point(86, 130);
    this->label_ActValues->Name = L"label_ActValues";
    this->label_ActValues->Size = System::Drawing::Size(77, 13);
    this->label_ActValues->TabIndex = 21;
    this->label_ActValues->Text = L"Aktuelle Werte";
    // 
    // tb_Version
    // 
    this->tb_Version->Enabled = false;
    this->tb_Version->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->tb_Version->Location = System::Drawing::Point(12, 529);
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
    this->tb_Log->Location = System::Drawing::Point(169, 273);
    this->tb_Log->Name = L"tb_Log";
    this->tb_Log->ReadOnly = true;
    this->tb_Log->Size = System::Drawing::Size(590, 267);
    this->tb_Log->TabIndex = 23;
    this->tb_Log->TabStop = false;
    this->tb_Log->Text = L"";
    // 
    // tb_Orientation_Act_C
    // 
    this->tb_Orientation_Act_C->Enabled = false;
    this->tb_Orientation_Act_C->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tb_Orientation_Act_C->Location = System::Drawing::Point(319, 243);
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
    this->tb_Orientation_Act_B->Location = System::Drawing::Point(319, 217);
    this->tb_Orientation_Act_B->Name = L"tb_Orientation_Act_B";
    this->tb_Orientation_Act_B->ReadOnly = true;
    this->tb_Orientation_Act_B->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_Act_B->TabIndex = 25;
    // 
    // tb_Orientation_C
    // 
    this->tb_Orientation_C->Location = System::Drawing::Point(319, 153);
    this->tb_Orientation_C->Name = L"tb_Orientation_C";
    this->tb_Orientation_C->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_C->TabIndex = 4;
    this->tb_Orientation_C->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // tb_Orientation_B
    // 
    this->tb_Orientation_B->Location = System::Drawing::Point(319, 127);
    this->tb_Orientation_B->Name = L"tb_Orientation_B";
    this->tb_Orientation_B->Size = System::Drawing::Size(100, 20);
    this->tb_Orientation_B->TabIndex = 3;
    this->tb_Orientation_B->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidateInput);
    // 
    // label_C
    // 
    this->label_C->AutoSize = true;
    this->label_C->Location = System::Drawing::Point(299, 156);
    this->label_C->Name = L"label_C";
    this->label_C->Size = System::Drawing::Size(14, 13);
    this->label_C->TabIndex = 28;
    this->label_C->Text = L"C";
    // 
    // label_B
    // 
    this->label_B->AutoSize = true;
    this->label_B->Location = System::Drawing::Point(299, 130);
    this->label_B->Name = L"label_B";
    this->label_B->Size = System::Drawing::Size(14, 13);
    this->label_B->TabIndex = 29;
    this->label_B->Text = L"B";
    // 
    // label_ActB
    // 
    this->label_ActB->AutoSize = true;
    this->label_ActB->Location = System::Drawing::Point(299, 220);
    this->label_ActB->Name = L"label_ActB";
    this->label_ActB->Size = System::Drawing::Size(14, 13);
    this->label_ActB->TabIndex = 30;
    this->label_ActB->Text = L"B";
    // 
    // label_ActA
    // 
    this->label_ActA->AutoSize = true;
    this->label_ActA->Location = System::Drawing::Point(299, 194);
    this->label_ActA->Name = L"label_ActA";
    this->label_ActA->Size = System::Drawing::Size(14, 13);
    this->label_ActA->TabIndex = 31;
    this->label_ActA->Text = L"A";
    // 
    // label_ActC
    // 
    this->label_ActC->AutoSize = true;
    this->label_ActC->Location = System::Drawing::Point(299, 246);
    this->label_ActC->Name = L"label_ActC";
    this->label_ActC->Size = System::Drawing::Size(14, 13);
    this->label_ActC->TabIndex = 32;
    this->label_ActC->Text = L"C";
    // 
    // label_A
    // 
    this->label_A->AutoSize = true;
    this->label_A->Location = System::Drawing::Point(299, 104);
    this->label_A->Name = L"label_A";
    this->label_A->Size = System::Drawing::Size(14, 13);
    this->label_A->TabIndex = 33;
    this->label_A->Text = L"A";
    // 
    // label_ActValues_ABC
    // 
    this->label_ActValues_ABC->AutoSize = true;
    this->label_ActValues_ABC->Location = System::Drawing::Point(330, 175);
    this->label_ActValues_ABC->Name = L"label_ActValues_ABC";
    this->label_ActValues_ABC->Size = System::Drawing::Size(77, 13);
    this->label_ActValues_ABC->TabIndex = 34;
    this->label_ActValues_ABC->Text = L"Aktuelle Werte";
    // 
    // label_Geschwindigkeit_Einheit_Wert
    // 
    this->label_Geschwindigkeit_Einheit_Wert->AutoSize = true;
    this->label_Geschwindigkeit_Einheit_Wert->Location = System::Drawing::Point(270, 104);
    this->label_Geschwindigkeit_Einheit_Wert->Name = L"label_Geschwindigkeit_Einheit_Wert";
    this->label_Geschwindigkeit_Einheit_Wert->Size = System::Drawing::Size(25, 13);
    this->label_Geschwindigkeit_Einheit_Wert->TabIndex = 35;
    this->label_Geschwindigkeit_Einheit_Wert->Text = L"m/s";
    // 
    // label_Geschwindigkeit_Einheit_Act_Wert
    // 
    this->label_Geschwindigkeit_Einheit_Act_Wert->AutoSize = true;
    this->label_Geschwindigkeit_Einheit_Act_Wert->Location = System::Drawing::Point(270, 130);
    this->label_Geschwindigkeit_Einheit_Act_Wert->Name = L"label_Geschwindigkeit_Einheit_Act_Wert";
    this->label_Geschwindigkeit_Einheit_Act_Wert->Size = System::Drawing::Size(25, 13);
    this->label_Geschwindigkeit_Einheit_Act_Wert->TabIndex = 36;
    this->label_Geschwindigkeit_Einheit_Act_Wert->Text = L"m/s";
    // 
    // label_Toleranz_Wert
    // 
    this->label_Toleranz_Wert->AutoSize = true;
    this->label_Toleranz_Wert->Location = System::Drawing::Point(570, 104);
    this->label_Toleranz_Wert->Name = L"label_Toleranz_Wert";
    this->label_Toleranz_Wert->Size = System::Drawing::Size(23, 13);
    this->label_Toleranz_Wert->TabIndex = 38;
    this->label_Toleranz_Wert->Text = L"mm";
    // 
    // label_Toleranz_Act_Wert
    // 
    this->label_Toleranz_Act_Wert->AutoSize = true;
    this->label_Toleranz_Act_Wert->Location = System::Drawing::Point(570, 130);
    this->label_Toleranz_Act_Wert->Name = L"label_Toleranz_Act_Wert";
    this->label_Toleranz_Act_Wert->Size = System::Drawing::Size(23, 13);
    this->label_Toleranz_Act_Wert->TabIndex = 39;
    this->label_Toleranz_Act_Wert->Text = L"mm";
    // 
    // label_Header
    // 
    this->label_Header->AutoSize = true;
    this->label_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Header->Location = System::Drawing::Point(8, 9);
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
    this->btn_Reset->Location = System::Drawing::Point(12, 361);
    this->btn_Reset->Name = L"btn_Reset";
    this->btn_Reset->Size = System::Drawing::Size(110, 50);
    this->btn_Reset->TabIndex = 10;
    this->btn_Reset->Text = L"Zurücksetzen";
    this->btn_Reset->UseVisualStyleBackColor = false;
    this->btn_Reset->Click += gcnew System::EventHandler(this, &RoboPathForm::btn_Reset_Click);
    // 
    // RoboPathForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::ButtonShadow;
    this->ClientSize = System::Drawing::Size(784, 561);
    this->Controls->Add(this->btn_Reset);
    this->Controls->Add(this->label_Header);
    this->Controls->Add(this->label_Toleranz_Act_Wert);
    this->Controls->Add(this->label_Toleranz_Wert);
    this->Controls->Add(this->label_Geschwindigkeit_Einheit_Act_Wert);
    this->Controls->Add(this->label_Geschwindigkeit_Einheit_Wert);
    this->Controls->Add(this->label_ActValues_ABC);
    this->Controls->Add(this->label_A);
    this->Controls->Add(this->label_ActC);
    this->Controls->Add(this->label_ActA);
    this->Controls->Add(this->label_ActB);
    this->Controls->Add(this->label_B);
    this->Controls->Add(this->label_C);
    this->Controls->Add(this->tb_Orientation_B);
    this->Controls->Add(this->tb_Orientation_C);
    this->Controls->Add(this->tb_Orientation_Act_B);
    this->Controls->Add(this->tb_Orientation_Act_C);
    this->Controls->Add(this->tb_Log);
    this->Controls->Add(this->tb_Version);
    this->Controls->Add(this->label_ActValues);
    this->Controls->Add(this->tb_Average_Act);
    this->Controls->Add(this->tb_Tolerance_Act);
    this->Controls->Add(this->tb_Orientation_Act_A);
    this->Controls->Add(this->tb_Velo_Act);
    this->Controls->Add(this->btn_Start);
    this->Controls->Add(this->btn_OpenCSV);
    this->Controls->Add(this->label_Average);
    this->Controls->Add(this->label_Tolerance);
    this->Controls->Add(this->label_Orientation);
    this->Controls->Add(this->label_Velo);
    this->Controls->Add(this->cb_Orientation);
    this->Controls->Add(this->cb_Velo);
    this->Controls->Add(this->tb_Average);
    this->Controls->Add(this->tb_Tolerance);
    this->Controls->Add(this->tb_Orientation_A);
    this->Controls->Add(this->tb_Velo);
    this->Controls->Add(this->btn_Set);
    this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
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
    }
    //Wenn die Checkbox false ist, möchte der Benutzer die Geschwindigkeit selbst definieren.
    //Die TextBox wird enabled
    else {
        this->tb_Velo->Enabled = true;
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

        this->tb_Orientation_Act_A->Clear();
        this->tb_Orientation_Act_B->Clear();
        this->tb_Orientation_Act_C->Clear();
    }
    //Wenn die Checkbox false ist, möchte der Benutzer die Orientierung selbst bestimmen
    //Somit werden alle Orientation Textboxen enabled
    else {
        this->tb_Orientation_A->Enabled = true;
        this->tb_Orientation_B->Enabled = true;
        this->tb_Orientation_C->Enabled = true;
    }
}
//Eregnis, nachdem der Set Button geklickt worden ist. Damit möchte der Nutzer alle eingegebene Werte setzen/speichern.
System::Void UserInterface::RoboPathForm::btn_Set_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        //Fehlerabfrage
        //Falls einer der Textboxen leer ist, wird emittelt welche und eine entsprechende Fehlermeldung wird ausgegeben
        if ((this->cb_Velo->Checked == false
            && this->tb_Velo->Text == "")
            || (this->cb_Orientation->Checked == false
                && (this->tb_Orientation_A->Text == ""
                    || this->tb_Orientation_B->Text == ""
                    || this->tb_Orientation_C->Text == ""))
            || this->tb_Tolerance->Text == ""
            || this->tb_Average->Text == ""
            || Datastore->GetFilePath() == "") {
            //Fehler: Es wurde keine CSV geladen
            System::Collections::Generic::List<System::String^> lstErrorMessages;
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
            if (this->tb_Tolerance->Text == "") {
                lstErrorMessages.Add("Geben Sie eine Toleranz ein");
            }
            //Fehler: Kein Wert in der Average Textbox
            if (this->tb_Average->Text == "") {
                lstErrorMessages.Add("Geben Sie eine Mittelwert ein");
            }
            //Alle Fehlermeldungen wurden in einer Liste aufgenommen und werden jetzt in einen String aneinandergehängt um diesen dann
            //im Logfenster und in einem Fehlerfenster auszugeben
            System::String^ sFehlerMeldung = "Folgende Fehler sind aufgetreten:\n";

            for (int i = 0; i < lstErrorMessages.Count; i++) {
                sFehlerMeldung = sFehlerMeldung + "\n" + lstErrorMessages[i];
                /*this->richTextBox_Log->AppendText(lstFehlermeldungen[i] + "\n");*/
            }
            //Ausgabe im Logfesnter
            this->AppendLog(sFehlerMeldung + "\n\n");
            //Ausgabe im Fehlerfenster
            this->ShowErrorWindow(sFehlerMeldung);

        }
        //Falls alle Daten ausgefüllt worden sind, werden diese in dem dafür erstellten Klasse/Objekt gespeichert
        else {
            if (this->cb_Velo->Checked == false) {
                //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
                Datastore->SetVelo(Single::Parse(this->tb_Velo->Text));
            }
            if (this->cb_Orientation->Checked == false) {
                //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
                Datastore->SetOrientationA(Single::Parse(this->tb_Orientation_A->Text));
                Datastore->SetOrientationB(Single::Parse(this->tb_Orientation_B->Text));
                Datastore->SetOrientationC(Single::Parse(this->tb_Orientation_C->Text));
            }
            //Der Text wird in den passenden Datentyp umgewandelt und übergeben.
            Datastore->SetTolerance(Single::Parse(this->tb_Tolerance->Text));
            Datastore->SetAverage(Single::Parse(this->tb_Average->Text));
            //Der Status der Checkboxen wird übergeben
            Datastore->SetUserDefVelo(this->cb_Velo->Checked);
            Datastore->SetUserDefOrientation(this->cb_Orientation->Checked);
            //Die gespeicherten Werte werden in den dafür vorgesehenen Textboxen übernommen, um die aktuell geladenen Werte anzuzeigen
            this->tb_Velo_Act->Text = this->tb_Velo->Text;
            this->tb_Orientation_Act_A->Text = this->tb_Orientation_A->Text;
            this->tb_Orientation_Act_B->Text = this->tb_Orientation_B->Text;
            this->tb_Orientation_Act_C->Text = this->tb_Orientation_C->Text;
            this->tb_Tolerance_Act->Text = this->tb_Tolerance->Text;
            this->tb_Average_Act->Text = this->tb_Average->Text;
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
        System::Boolean bJaNein = this->ShowYesNoWindow("Sollen alle Daten gelöscht werden?");
        //Je nachdem was der Nutzer angeklickt hat, wird alles gelöscht oder auch nicht
        if (bJaNein) {
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




//Ereignis, nachdem der Start Button geklickt wird
System::Void UserInterface::RoboPathForm::btn_Start_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (bSetted) {
            Logic::ReadCSV^ Reader = gcnew Logic::ReadCSV(this);
            /*Reader->ReadAndReturnCSV("test", this);*/
            this->AppendLog("CSV wird eingelesen\n\n");
            System::Threading::Thread::Sleep(1000);
            Datastore->SetlstPathData(Reader->ReadAndReturnCSV(Datastore->GetFilePath()));
        }
        else
        {
            this->ShowErrorWindow("Der Set-Button wurde noch nicht gedrückt");
            this->AppendLog("Der Set-Button wurde noch nicht gedrückt\n\n");
        }
    }
    catch (System::Exception^ e) {
        this->AppendLog("Fehler beim Starten:\n" + e->Message + "\n\n");
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
    //Man kann GLeitkommazahlen mit einem Punkt oder einem Komma eingeben. Gültig ist aber nur ein Komma.
    //Deswegen wird geprüft, ob der eingegebene Text ein Punkt beinhaltet. Falls ja, wird dieser durch ein Komma ersetzt
    if (tbCurrentTextBox->Text->Contains(".")) {
        tbCurrentTextBox->Text = tbCurrentTextBox->Text->Replace(".", ",");
    }
    float fInput;
    //Der eingegebene Text wird in ein float umgewandelt. Falls dies gelingt, wird der Float in der Variable fInput gespeichert
    if (float::TryParse(tbCurrentTextBox->Text, fInput)) {
        //Da jede Textbox andere Bedingungen hat, wird ermittelt, um welche Textbox es sich handelt
        //Wenn es die Velo Textbox ist, darf der Wert nicht keliner als 0 und größer als 2 sein.
        if (tbCurrentTextBox->Name == "tb_Velo") {
            if (fInput <= 0 || fInput > 2) {
                //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                this->ShowErrorWindow("Die Geschwindigkeit muss größer als 0 sein und darf maximal 2m/s betragen");
                tbCurrentTextBox->Clear();
            }
            return;
        }
        //Wenn es einer der Orientation Textboxen ist, darf der Winkel nur zwischen 0 und 360 grad betragen
        else if (tbCurrentTextBox->Name->Contains("tb_Orientation_")) {
            if (fInput < 0 || fInput > 360) {
                //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                this->ShowErrorWindow("Der Winkel muss zwischen 0° und 360° betragen");
                tbCurrentTextBox->Text = "";
            }
            return;
        }
        //Wenn es die Toelrance Textbox ist, ...
        else if (tbCurrentTextBox->Name == "tb_Tolerance") {
            if (fInput < 0 || fInput > 0) {
                //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                this->ShowErrorWindow("Die Grenzen müssen noch definiert werden.\nSolange ist erstmal alles erlaubt");
                /*tbAktuelleTextBox->Text = "";*/
            }
            return;
        }
        //Falls es die Average Textbox ist, ...
        else if (tbCurrentTextBox->Name == "tb_Average") {
            if (fInput < 0 || fInput > 0) {
                //Falls doch, wird eine Fehlermeldung ausgegeben und der Text wird resettet.
                this->ShowErrorWindow("Die Grenzen müssen noch definiert werden.\nSolange ist erstmal alles erlaubt");
                /*tbAktuelleTextBox->Text = "";*/
            }
            return;
        }
        //Falls else erreicht wird, wurde eine Textbox hinzugefügt, ohne diese hier zu implementieren
        else {
            this->AppendLog("Unbekannte TextBox\n\n");
            return;
        }
    }
    //Falls der eingegebene Wert nicht in ein float umgewandelt werden kann, wird die folgende Fehlermeldung ausgegeben
    else {
        this->ShowErrorWindow("Es sind nur ganze oder Gleitkommezahlen erlaubt");
        tbCurrentTextBox->Text = "";
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
    System::Windows::Forms::DialogResult xDialogResult = MessageBox::Show(message, "", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
    return xDialogResult == System::Windows::Forms::DialogResult::Yes;
}
#pragma endregion windows forms helper

#pragma region helpers
//Standardfunktion um Text im Log anzuzeigen
System::Void UserInterface::RoboPathForm::AppendLog(System::String^ sMessage) {
    //Ein Objekt, dass die aktuelle Uhrzeit enthält, wird erstellt
    System::DateTime aktuelleUhrzeit = System::DateTime::Now;
    //Diese Uhrzeit wird noch in gewünschte Format gebracht
    System::String^ formartierteZeit = aktuelleUhrzeit.ToString("HH:mm:ss");
    //Bevor der Text ausgegeben wird, wird die Uhrzeit darüber ausgebeben als Zeitstempel
    this->tb_Log->AppendText(formartierteZeit + "\n");
    //Ausgabe des Textes
    this->tb_Log->AppendText(sMessage);
    //Scrollen bis ganz unten
    this->tb_Log->ScrollToCaret();
    System::Windows::Forms::Application::DoEvents();
}
System::Void UserInterface::RoboPathForm::SetVersion() {
    //Es wird ein Objekt erstellt, in dem die Version gepfelgt wird
    Projectdata::VersionInfo xVersion;
    //Die Versionsnummer wird der Textbox zugewiesen
    this->tb_Version->Text = xVersion.getVersion();
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
    this->tb_Tolerance->Clear();
    this->tb_Tolerance_Act->Clear();
    this->tb_Average->Clear();
    this->tb_Average_Act->Clear();
    this->tb_Log->Clear();
    bSetted = false;
}
#pragma endregion helpers
