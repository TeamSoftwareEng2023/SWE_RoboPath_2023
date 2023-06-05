#include "pch.h"
#include"RoboPathForm.h"

UI::RoboPathForm::RoboPathForm(void)
{
    InitializeComponent();
    Datastore = gcnew Projectdata::RoboPath();
    SetVersion();
}

UI::RoboPathForm::~RoboPathForm()
{
    if (components)
    {
        delete components;
    }
}

void UI::RoboPathForm::InitializeComponent()
{
    this->SetButton = (gcnew System::Windows::Forms::Button());
    this->textBox_Geschwindigkeit = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Orientierung_A = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Toleranz = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Mittelwertfindung = (gcnew System::Windows::Forms::TextBox());
    this->checkBox_Geschwindigkeit = (gcnew System::Windows::Forms::CheckBox());
    this->checkBox_Orientierung = (gcnew System::Windows::Forms::CheckBox());
    this->label_Geschwindigkeit = (gcnew System::Windows::Forms::Label());
    this->label_Orientierung = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz = (gcnew System::Windows::Forms::Label());
    this->label_Mittelwertfindung = (gcnew System::Windows::Forms::Label());
    this->CSVÖffnenButton = (gcnew System::Windows::Forms::Button());
    this->StartButton = (gcnew System::Windows::Forms::Button());
    this->textBoxGeschwindigkeit_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Orientierung_A_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Toleranz_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Mittelwert_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->label_ActWerte_1 = (gcnew System::Windows::Forms::Label());
    this->textBox_Version = (gcnew System::Windows::Forms::TextBox());
    this->openFileDialog_CSV = (gcnew System::Windows::Forms::OpenFileDialog());
    this->richTextBox_Log = (gcnew System::Windows::Forms::RichTextBox());
    this->textBox_Orientierung_C_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Orientierung_B_Aktuell = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Orientierung_C = (gcnew System::Windows::Forms::TextBox());
    this->textBox_Orientierung_B = (gcnew System::Windows::Forms::TextBox());
    this->label_C = (gcnew System::Windows::Forms::Label());
    this->label_B = (gcnew System::Windows::Forms::Label());
    this->label_ActB = (gcnew System::Windows::Forms::Label());
    this->label_ActA = (gcnew System::Windows::Forms::Label());
    this->label_ActC = (gcnew System::Windows::Forms::Label());
    this->label_A = (gcnew System::Windows::Forms::Label());
    this->label_ActWerte_2 = (gcnew System::Windows::Forms::Label());
    this->label_Geschwindigkeit_Einheit_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Geschwindigkeit_Einheit_Act_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Toleranz_Act_Wert = (gcnew System::Windows::Forms::Label());
    this->label_Überschrift = (gcnew System::Windows::Forms::Label());
    this->ClearButton = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // SetButton
    // 
    this->SetButton->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->SetButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->SetButton->Location = System::Drawing::Point(649, 213);
    this->SetButton->Name = L"SetButton";
    this->SetButton->Size = System::Drawing::Size(110, 50);
    this->SetButton->TabIndex = 3;
    this->SetButton->Text = L"Set";
    this->SetButton->UseVisualStyleBackColor = false;
    this->SetButton->Click += gcnew System::EventHandler(this, &RoboPathForm::SetButton_Click);
    // 
    // textBox_Geschwindigkeit
    // 
    this->textBox_Geschwindigkeit->Location = System::Drawing::Point(169, 101);
    this->textBox_Geschwindigkeit->Name = L"textBox_Geschwindigkeit";
    this->textBox_Geschwindigkeit->Size = System::Drawing::Size(100, 20);
    this->textBox_Geschwindigkeit->TabIndex = 1;
    this->textBox_Geschwindigkeit->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
    // 
    // textBox_Orientierung_A
    // 
    this->textBox_Orientierung_A->Location = System::Drawing::Point(319, 101);
    this->textBox_Orientierung_A->Name = L"textBox_Orientierung_A";
    this->textBox_Orientierung_A->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_A->TabIndex = 2;
    this->textBox_Orientierung_A->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
    // 
    // textBox_Toleranz
    // 
    this->textBox_Toleranz->Location = System::Drawing::Point(469, 101);
    this->textBox_Toleranz->Name = L"textBox_Toleranz";
    this->textBox_Toleranz->Size = System::Drawing::Size(100, 20);
    this->textBox_Toleranz->TabIndex = 6;
    this->textBox_Toleranz->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
    // 
    // textBox_Mittelwertfindung
    // 
    this->textBox_Mittelwertfindung->Location = System::Drawing::Point(619, 101);
    this->textBox_Mittelwertfindung->Name = L"textBox_Mittelwertfindung";
    this->textBox_Mittelwertfindung->Size = System::Drawing::Size(100, 20);
    this->textBox_Mittelwertfindung->TabIndex = 7;
    this->textBox_Mittelwertfindung->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
    // 
    // checkBox_Geschwindigkeit
    // 
    this->checkBox_Geschwindigkeit->AutoSize = true;
    this->checkBox_Geschwindigkeit->Location = System::Drawing::Point(12, 175);
    this->checkBox_Geschwindigkeit->Name = L"checkBox_Geschwindigkeit";
    this->checkBox_Geschwindigkeit->Size = System::Drawing::Size(147, 17);
    this->checkBox_Geschwindigkeit->TabIndex = 8;
    this->checkBox_Geschwindigkeit->Text = L"Geschwindigkeit aus .csv";
    this->checkBox_Geschwindigkeit->UseVisualStyleBackColor = true;
    this->checkBox_Geschwindigkeit->CheckedChanged += gcnew System::EventHandler(this, &RoboPathForm::checkbox_GeschwindigkeitAusCSV_CheckChanged);
    // 
    // checkBox_Orientierung
    // 
    this->checkBox_Orientierung->AutoSize = true;
    this->checkBox_Orientierung->Location = System::Drawing::Point(12, 194);
    this->checkBox_Orientierung->Name = L"checkBox_Orientierung";
    this->checkBox_Orientierung->Size = System::Drawing::Size(126, 17);
    this->checkBox_Orientierung->TabIndex = 9;
    this->checkBox_Orientierung->Text = L"Orientierung aus .csv";
    this->checkBox_Orientierung->UseVisualStyleBackColor = true;
    this->checkBox_Orientierung->CheckedChanged += gcnew System::EventHandler(this, &RoboPathForm::checkBox_OrientierugnngsCSV_CheckChanged);
    // 
    // label_Geschwindigkeit
    // 
    this->label_Geschwindigkeit->AutoSize = true;
    this->label_Geschwindigkeit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Geschwindigkeit->Location = System::Drawing::Point(165, 75);
    this->label_Geschwindigkeit->Name = L"label_Geschwindigkeit";
    this->label_Geschwindigkeit->Size = System::Drawing::Size(140, 20);
    this->label_Geschwindigkeit->TabIndex = 0;
    this->label_Geschwindigkeit->Text = L"Geschwindigkeit";
    // 
    // label_Orientierung
    // 
    this->label_Orientierung->AutoSize = true;
    this->label_Orientierung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Orientierung->Location = System::Drawing::Point(315, 75);
    this->label_Orientierung->Name = L"label_Orientierung";
    this->label_Orientierung->Size = System::Drawing::Size(108, 20);
    this->label_Orientierung->TabIndex = 0;
    this->label_Orientierung->Text = L"Orientierung";
    // 
    // label_Toleranz
    // 
    this->label_Toleranz->AutoSize = true;
    this->label_Toleranz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Toleranz->Location = System::Drawing::Point(465, 75);
    this->label_Toleranz->Name = L"label_Toleranz";
    this->label_Toleranz->Size = System::Drawing::Size(78, 20);
    this->label_Toleranz->TabIndex = 13;
    this->label_Toleranz->Text = L"Toleranz";
    // 
    // label_Mittelwertfindung
    // 
    this->label_Mittelwertfindung->AutoSize = true;
    this->label_Mittelwertfindung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Mittelwertfindung->Location = System::Drawing::Point(615, 75);
    this->label_Mittelwertfindung->Name = L"label_Mittelwertfindung";
    this->label_Mittelwertfindung->Size = System::Drawing::Size(147, 20);
    this->label_Mittelwertfindung->TabIndex = 14;
    this->label_Mittelwertfindung->Text = L"Mittelwertfindung";
    // 
    // CSVÖffnenButton
    // 
    this->CSVÖffnenButton->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->CSVÖffnenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->CSVÖffnenButton->Location = System::Drawing::Point(12, 417);
    this->CSVÖffnenButton->Name = L"CSVÖffnenButton";
    this->CSVÖffnenButton->Size = System::Drawing::Size(110, 50);
    this->CSVÖffnenButton->TabIndex = 15;
    this->CSVÖffnenButton->Text = L".csv öffnen";
    this->CSVÖffnenButton->UseVisualStyleBackColor = false;
    this->CSVÖffnenButton->Click += gcnew System::EventHandler(this, &RoboPathForm::CSVÖffnen_Click);
    // 
    // StartButton
    // 
    this->StartButton->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->StartButton->Location = System::Drawing::Point(12, 473);
    this->StartButton->Name = L"StartButton";
    this->StartButton->Size = System::Drawing::Size(110, 50);
    this->StartButton->TabIndex = 16;
    this->StartButton->Text = L"Start";
    this->StartButton->UseVisualStyleBackColor = false;
    this->StartButton->Click += gcnew System::EventHandler(this, &RoboPathForm::StartButton_Click);
    // 
    // textBoxGeschwindigkeit_Aktuell
    // 
    this->textBoxGeschwindigkeit_Aktuell->AcceptsTab = true;
    this->textBoxGeschwindigkeit_Aktuell->Enabled = false;
    this->textBoxGeschwindigkeit_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBoxGeschwindigkeit_Aktuell->Location = System::Drawing::Point(169, 127);
    this->textBoxGeschwindigkeit_Aktuell->Name = L"textBoxGeschwindigkeit_Aktuell";
    this->textBoxGeschwindigkeit_Aktuell->ReadOnly = true;
    this->textBoxGeschwindigkeit_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBoxGeschwindigkeit_Aktuell->TabIndex = 17;
    // 
    // textBox_Orientierung_A_Aktuell
    // 
    this->textBox_Orientierung_A_Aktuell->Enabled = false;
    this->textBox_Orientierung_A_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBox_Orientierung_A_Aktuell->Location = System::Drawing::Point(319, 191);
    this->textBox_Orientierung_A_Aktuell->Name = L"textBox_Orientierung_A_Aktuell";
    this->textBox_Orientierung_A_Aktuell->ReadOnly = true;
    this->textBox_Orientierung_A_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_A_Aktuell->TabIndex = 18;
    // 
    // textBox_Toleranz_Aktuell
    // 
    this->textBox_Toleranz_Aktuell->Enabled = false;
    this->textBox_Toleranz_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBox_Toleranz_Aktuell->Location = System::Drawing::Point(469, 127);
    this->textBox_Toleranz_Aktuell->Name = L"textBox_Toleranz_Aktuell";
    this->textBox_Toleranz_Aktuell->ReadOnly = true;
    this->textBox_Toleranz_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBox_Toleranz_Aktuell->TabIndex = 19;
    // 
    // textBox_Mittelwert_Aktuell
    // 
    this->textBox_Mittelwert_Aktuell->Enabled = false;
    this->textBox_Mittelwert_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBox_Mittelwert_Aktuell->Location = System::Drawing::Point(619, 127);
    this->textBox_Mittelwert_Aktuell->Name = L"textBox_Mittelwert_Aktuell";
    this->textBox_Mittelwert_Aktuell->ReadOnly = true;
    this->textBox_Mittelwert_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBox_Mittelwert_Aktuell->TabIndex = 20;
    // 
    // label_ActWerte_1
    // 
    this->label_ActWerte_1->AutoSize = true;
    this->label_ActWerte_1->Location = System::Drawing::Point(86, 130);
    this->label_ActWerte_1->Name = L"label_ActWerte_1";
    this->label_ActWerte_1->Size = System::Drawing::Size(77, 13);
    this->label_ActWerte_1->TabIndex = 21;
    this->label_ActWerte_1->Text = L"Aktuelle Werte";
    // 
    // textBox_Version
    // 
    this->textBox_Version->Enabled = false;
    this->textBox_Version->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->textBox_Version->Location = System::Drawing::Point(12, 529);
    this->textBox_Version->Name = L"textBox_Version";
    this->textBox_Version->ReadOnly = true;
    this->textBox_Version->Size = System::Drawing::Size(71, 20);
    this->textBox_Version->TabIndex = 22;
    this->textBox_Version->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    // 
    // openFileDialog_CSV
    // 
    this->openFileDialog_CSV->Filter = L"csv files (*.csv) |*.csv";
    this->openFileDialog_CSV->InitialDirectory = L"c:\\";
    this->openFileDialog_CSV->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &RoboPathForm::openFileDialog_CSV_FileOk);
    // 
    // richTextBox_Log
    // 
    this->richTextBox_Log->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->richTextBox_Log->Location = System::Drawing::Point(169, 273);
    this->richTextBox_Log->Name = L"richTextBox_Log";
    this->richTextBox_Log->ReadOnly = true;
    this->richTextBox_Log->Size = System::Drawing::Size(590, 267);
    this->richTextBox_Log->TabIndex = 23;
    this->richTextBox_Log->Text = L"";
    // 
    // textBox_Orientierung_C_Aktuell
    // 
    this->textBox_Orientierung_C_Aktuell->Enabled = false;
    this->textBox_Orientierung_C_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBox_Orientierung_C_Aktuell->Location = System::Drawing::Point(319, 243);
    this->textBox_Orientierung_C_Aktuell->Name = L"textBox_Orientierung_C_Aktuell";
    this->textBox_Orientierung_C_Aktuell->ReadOnly = true;
    this->textBox_Orientierung_C_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_C_Aktuell->TabIndex = 24;
    // 
    // textBox_Orientierung_B_Aktuell
    // 
    this->textBox_Orientierung_B_Aktuell->Enabled = false;
    this->textBox_Orientierung_B_Aktuell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->textBox_Orientierung_B_Aktuell->Location = System::Drawing::Point(319, 217);
    this->textBox_Orientierung_B_Aktuell->Name = L"textBox_Orientierung_B_Aktuell";
    this->textBox_Orientierung_B_Aktuell->ReadOnly = true;
    this->textBox_Orientierung_B_Aktuell->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_B_Aktuell->TabIndex = 25;
    // 
    // textBox_Orientierung_C
    // 
    this->textBox_Orientierung_C->Location = System::Drawing::Point(319, 153);
    this->textBox_Orientierung_C->Name = L"textBox_Orientierung_C";
    this->textBox_Orientierung_C->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_C->TabIndex = 26;
    this->textBox_Orientierung_C->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
    // 
    // textBox_Orientierung_B
    // 
    this->textBox_Orientierung_B->Location = System::Drawing::Point(319, 127);
    this->textBox_Orientierung_B->Name = L"textBox_Orientierung_B";
    this->textBox_Orientierung_B->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_B->TabIndex = 27;
    this->textBox_Orientierung_B->Leave += gcnew System::EventHandler(this, &RoboPathForm::ValidiereEingabe);
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
    // label_ActWerte_2
    // 
    this->label_ActWerte_2->AutoSize = true;
    this->label_ActWerte_2->Location = System::Drawing::Point(330, 175);
    this->label_ActWerte_2->Name = L"label_ActWerte_2";
    this->label_ActWerte_2->Size = System::Drawing::Size(77, 13);
    this->label_ActWerte_2->TabIndex = 34;
    this->label_ActWerte_2->Text = L"Aktuelle Werte";
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
    // label_Überschrift
    // 
    this->label_Überschrift->AutoSize = true;
    this->label_Überschrift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->label_Überschrift->Location = System::Drawing::Point(8, 9);
    this->label_Überschrift->Name = L"label_Überschrift";
    this->label_Überschrift->Size = System::Drawing::Size(384, 39);
    this->label_Überschrift->TabIndex = 40;
    this->label_Überschrift->Text = L"RoboPath Konfigurator";
    // 
    // ClearButton
    // 
    this->ClearButton->BackColor = System::Drawing::SystemColors::ButtonFace;
    this->ClearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->ClearButton->Location = System::Drawing::Point(12, 361);
    this->ClearButton->Name = L"ClearButton";
    this->ClearButton->Size = System::Drawing::Size(110, 50);
    this->ClearButton->TabIndex = 41;
    this->ClearButton->Text = L"Zurücksetzen";
    this->ClearButton->UseVisualStyleBackColor = false;
    this->ClearButton->Click += gcnew System::EventHandler(this, &RoboPathForm::ZurücksetzenButton_Click);
    // 
    // RoboPathForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::ButtonShadow;
    this->ClientSize = System::Drawing::Size(784, 561);
    this->Controls->Add(this->ClearButton);
    this->Controls->Add(this->label_Überschrift);
    this->Controls->Add(this->label_Toleranz_Act_Wert);
    this->Controls->Add(this->label_Toleranz_Wert);
    this->Controls->Add(this->label_Geschwindigkeit_Einheit_Act_Wert);
    this->Controls->Add(this->label_Geschwindigkeit_Einheit_Wert);
    this->Controls->Add(this->label_ActWerte_2);
    this->Controls->Add(this->label_A);
    this->Controls->Add(this->label_ActC);
    this->Controls->Add(this->label_ActA);
    this->Controls->Add(this->label_ActB);
    this->Controls->Add(this->label_B);
    this->Controls->Add(this->label_C);
    this->Controls->Add(this->textBox_Orientierung_B);
    this->Controls->Add(this->textBox_Orientierung_C);
    this->Controls->Add(this->textBox_Orientierung_B_Aktuell);
    this->Controls->Add(this->textBox_Orientierung_C_Aktuell);
    this->Controls->Add(this->richTextBox_Log);
    this->Controls->Add(this->textBox_Version);
    this->Controls->Add(this->label_ActWerte_1);
    this->Controls->Add(this->textBox_Mittelwert_Aktuell);
    this->Controls->Add(this->textBox_Toleranz_Aktuell);
    this->Controls->Add(this->textBox_Orientierung_A_Aktuell);
    this->Controls->Add(this->textBoxGeschwindigkeit_Aktuell);
    this->Controls->Add(this->StartButton);
    this->Controls->Add(this->CSVÖffnenButton);
    this->Controls->Add(this->label_Mittelwertfindung);
    this->Controls->Add(this->label_Toleranz);
    this->Controls->Add(this->label_Orientierung);
    this->Controls->Add(this->label_Geschwindigkeit);
    this->Controls->Add(this->checkBox_Orientierung);
    this->Controls->Add(this->checkBox_Geschwindigkeit);
    this->Controls->Add(this->textBox_Mittelwertfindung);
    this->Controls->Add(this->textBox_Toleranz);
    this->Controls->Add(this->textBox_Orientierung_A);
    this->Controls->Add(this->textBox_Geschwindigkeit);
    this->Controls->Add(this->SetButton);
    this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->MaximizeBox = false;
    this->Name = L"RoboPathForm";
    this->Text = L"RoboPath";
    this->ResumeLayout(false);
    this->PerformLayout();

}

#pragma region EventHandler
System::Void UI::RoboPathForm::checkbox_GeschwindigkeitAusCSV_CheckChanged(System::Object^ sender, System::EventArgs^ e) {
    if (this->checkBox_Geschwindigkeit->Checked) {

        this->textBox_Geschwindigkeit->Text = "";

        this->textBox_Geschwindigkeit->Enabled = false;

        this->textBoxGeschwindigkeit_Aktuell->Text = "";
    }
    else {
        this->textBox_Geschwindigkeit->Enabled = true;
    }
}
System::Void UI::RoboPathForm::checkBox_OrientierugnngsCSV_CheckChanged(System::Object^ sender, System::EventArgs^ e) {
    if (this->checkBox_Orientierung->Checked) {

        this->textBox_Orientierung_A->Text = "";
        this->textBox_Orientierung_B->Text = "";
        this->textBox_Orientierung_C->Text = "";

        this->textBox_Orientierung_A->Enabled = false;
        this->textBox_Orientierung_B->Enabled = false;
        this->textBox_Orientierung_C->Enabled = false;

        this->textBox_Orientierung_A_Aktuell->Text = "";
        this->textBox_Orientierung_B_Aktuell->Text = "";
        this->textBox_Orientierung_C_Aktuell->Text = "";
    }
    else {
        this->textBox_Orientierung_A->Enabled = true;
        this->textBox_Orientierung_B->Enabled = true;
        this->textBox_Orientierung_C->Enabled = true;
    }
}
System::Void UI::RoboPathForm::SetButton_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if ((this->checkBox_Geschwindigkeit->Checked == false
            && this->textBox_Geschwindigkeit->Text == "")
            || (this->checkBox_Orientierung->Checked == false
                && (this->textBox_Orientierung_A->Text == ""
                    || this->textBox_Orientierung_B->Text == ""
                    || this->textBox_Orientierung_C->Text == ""))
            || this->textBox_Toleranz->Text == ""
            || this->textBox_Mittelwertfindung->Text == ""
            || Datastore->GetFilePath() == "") {

            System::Collections::Generic::List<System::String^> lstFehlermeldungen;
            if (Datastore->GetFilePath() == "") {
                lstFehlermeldungen.Add("Laden Sie eine CSV-Datei");
            }
            if (this->checkBox_Geschwindigkeit->Checked == false
                && this->textBox_Geschwindigkeit->Text == "") {
                lstFehlermeldungen.Add("Geben Sie eine Geschwindigkeit ein");
            }
            if (this->checkBox_Orientierung->Checked == false
                && (this->textBox_Orientierung_A->Text == ""
                    || this->textBox_Orientierung_B->Text == ""
                    || this->textBox_Orientierung_C->Text == "")) {
                if (this->textBox_Orientierung_A->Text == "") {
                    lstFehlermeldungen.Add("Geben Sie einen Wert in der Orientierung \"A\" ein");
                }
                if (this->textBox_Orientierung_B->Text == "") {
                    lstFehlermeldungen.Add("Geben Sie einen Wert in der Orientierung \"B\" ein");
                }
                if (this->textBox_Orientierung_C->Text == "") {
                    lstFehlermeldungen.Add("Geben Sie einen Wert in der Orientierung \"C\" ein");
                }
            }
            if (this->textBox_Toleranz->Text == "") {
                lstFehlermeldungen.Add("Geben Sie eine Toleranz ein");
            }
            if (this->textBox_Mittelwertfindung->Text == "") {
                lstFehlermeldungen.Add("Geben Sie eine Mittelwert ein");
            }

            System::String^ sFehlerMeldung = "Folgende Fehler sind aufgetreten:\n";

            for (int i = 0; i < lstFehlermeldungen.Count; i++) {
                sFehlerMeldung = sFehlerMeldung + "\n" + lstFehlermeldungen[i];
                /*this->richTextBox_Log->AppendText(lstFehlermeldungen[i] + "\n");*/
            }
            this->AppendLog(sFehlerMeldung + "\n\n");
            this->ShowErrorWindow(sFehlerMeldung);

        }
        else {
            if (this->checkBox_Geschwindigkeit->Checked == false) {
                Datastore->SetGeschwindigkeit(Single::Parse(this->textBox_Geschwindigkeit->Text));
            }
            if (this->checkBox_Orientierung->Checked == false) {
                Datastore->SetOrientierungA(Single::Parse(this->textBox_Orientierung_A->Text));
                Datastore->SetOrientierungB(Single::Parse(this->textBox_Orientierung_B->Text));
                Datastore->SetOrientierungC(Single::Parse(this->textBox_Orientierung_C->Text));
            }
            Datastore->SetToleranz(Single::Parse(this->textBox_Toleranz->Text));
            Datastore->SetMittelWert(Single::Parse(this->textBox_Mittelwertfindung->Text));
            Datastore->SetNutzerdefinierteGeschwindigkeit(this->checkBox_Geschwindigkeit->Checked);
            Datastore->SetNutzerdefinierteOrientierung(this->checkBox_Orientierung->Checked);

            this->textBoxGeschwindigkeit_Aktuell->Text = this->textBox_Geschwindigkeit->Text;
            this->textBox_Orientierung_A_Aktuell->Text = this->textBox_Orientierung_A->Text;
            this->textBox_Orientierung_B_Aktuell->Text = this->textBox_Orientierung_B->Text;
            this->textBox_Orientierung_C_Aktuell->Text = this->textBox_Orientierung_C->Text;
            this->textBox_Toleranz_Aktuell->Text = this->textBox_Toleranz->Text;
            this->textBox_Mittelwert_Aktuell->Text = this->textBox_Mittelwertfindung->Text;
            this->AppendLog("Laden der Werte erfolgreich\n\n");
        }
    }
    catch (const std::exception&) {
        this->AppendLog("Fehler beim Laden der Werte\n\n");
    }
}
System::Void UI::RoboPathForm::ZurücksetzenButton_Click(System::Object^ sender, System::EventArgs^ e) {
    try
    {
        System::Boolean bJaNein = this->ShowYesNoWindow("Sollen alle Daten gelöscht werden?");

        if (bJaNein) {
            Datastore->Zurücksetzen();
            this->AllesZurücksetzen();
        }
        else {
            return;
        }
    }
    catch (const std::exception&)
    {
        this->AppendLog("Fehler beim Zurücksetzen der Werte\n\n");
    }
}
System::Void UI::RoboPathForm::CSVÖffnen_Click(System::Object^ sender, System::EventArgs^ e) {
    openFileDialog_CSV->ShowDialog();
}
System::Void UI::RoboPathForm::openFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
    this->AppendLog("Folgende .csv ist geladen: " + openFileDialog_CSV->FileName + "\n\n");
    Datastore->SetFilePath(openFileDialog_CSV->FileName);
}
System::Void UI::RoboPathForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
    /*LogicReadCSV::ReadCSV Reader;*/
    /*Reader.ReadAndReturnCSV(DataStore.GetFilePath());*/
}
System::Void UI::RoboPathForm::ValidiereEingabe(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ tbAktuelleTextBox = dynamic_cast<TextBox^>(sender);
    if (tbAktuelleTextBox->Text == "") {
        return;
    }
    if (tbAktuelleTextBox->Text->Contains(".")) {
        tbAktuelleTextBox->Text = tbAktuelleTextBox->Text->Replace(".", ",");
    }
    float fEingabe;
    if (float::TryParse(tbAktuelleTextBox->Text, fEingabe)) {
        if (tbAktuelleTextBox->Name == "textBox_Geschwindigkeit"
            && (fEingabe <= 0
                || fEingabe > 2)) {
            this->ShowErrorWindow("Die Geschwindigkeit muss größer als 0 sein und darf maximal 2m/s betragen");
            tbAktuelleTextBox->Text = "";
        }
        else if (tbAktuelleTextBox->Name->Contains("textBox_Orientierung_")
                && (fEingabe < 0
                    || fEingabe > 360)) {
            this->ShowErrorWindow("Der Winkel muss zwischen 0° und 360° betragen");
            tbAktuelleTextBox->Text = "";
        }
        else if (tbAktuelleTextBox->Name == "textBox_Toleranz"
                && (fEingabe < 0
                    || fEingabe > 0)) {
            this->ShowErrorWindow("Die Grenzen müssen noch definiert werden.\nSolange ist erstmal alles erlaubt");
            /*tbAktuelleTextBox->Text = "";*/
        }
        else if (tbAktuelleTextBox->Name == "textBox_Mittelwertfindung"
            && (fEingabe < 0
                || fEingabe > 0)) {
            this->ShowErrorWindow("Die Grenzen müssen noch definiert werden.\nSolange ist erstmal alles erlaubt");
            /*tbAktuelleTextBox->Text = "";*/
        }
        else {
            return;
        }
    }
    else {
        this->ShowErrorWindow("Es sind nur ganze oder Gleitkommezahlen erlaubt");
        this->textBox_Geschwindigkeit->Text = "";
    }
}
#pragma endregion EventHandler

#pragma region windows forms helper
System::Void UI::RoboPathForm::ShowErrorWindow(String^ errorMessage)
{
    MessageBox::Show(errorMessage, "Fehler", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
System::Boolean UI::RoboPathForm::ShowYesNoWindow(System::String^ message)
{

    // Anzeigen des Ja-Nein-Fensters und Rückgabe der Benutzerantwort
    System::Windows::Forms::DialogResult xDialogResult = MessageBox::Show(message, "", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
    return xDialogResult == System::Windows::Forms::DialogResult::Yes;
}
#pragma endregion windows forms helper

#pragma region helpers
System::Void UI::RoboPathForm::AppendLog(System::String^ sMessage) {
    System::DateTime aktuelleUhrzeit = System::DateTime::Now;
    System::String^ formartierteZeit = aktuelleUhrzeit.ToString("HH:mm:ss");
    this->richTextBox_Log->AppendText(formartierteZeit + "\n");
    this->richTextBox_Log->AppendText(sMessage);
    this->richTextBox_Log->ScrollToCaret();
}
System::Void UI::RoboPathForm::SetVersion() {
    Projectdata::VersionInfo xVersion;
    this->textBox_Version->Text = xVersion.getVersion();
}
System::Void UI::RoboPathForm::AllesZurücksetzen() {
    this->textBox_Geschwindigkeit->Clear();
    this->textBoxGeschwindigkeit_Aktuell->Clear();
    this->textBox_Orientierung_A->Clear();
    this->textBox_Orientierung_A_Aktuell->Clear();
    this->textBox_Orientierung_B->Clear();
    this->textBox_Orientierung_B_Aktuell->Clear();
    this->textBox_Orientierung_C->Clear();
    this->textBox_Orientierung_C_Aktuell->Clear();
    this->textBox_Toleranz->Clear();
    this->textBox_Toleranz_Aktuell->Clear();
    this->textBox_Mittelwertfindung->Clear();
    this->textBox_Mittelwert_Aktuell->Clear();
    this->richTextBox_Log->Clear();
}
#pragma endregion helpers
