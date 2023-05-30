#include "pch.h"
#include"RoboPathForm.h"

UIRoboPathForms::RoboPathForm::RoboPathForm(void)
{
    InitializeComponent();
    Datastore = gcnew DataRoboPath::RoboPath();
    SetVersion();
}

UIRoboPathForms::RoboPathForm::~RoboPathForm()
{
    if (components)
    {
        delete components;
    }
}

void UIRoboPathForms::RoboPathForm::InitializeComponent()
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
    // 
    // textBox_Geschwindigkeit
    // 
    this->textBox_Geschwindigkeit->AcceptsTab = true;
    this->textBox_Geschwindigkeit->Location = System::Drawing::Point(169, 101);
    this->textBox_Geschwindigkeit->Name = L"textBox_Geschwindigkeit";
    this->textBox_Geschwindigkeit->Size = System::Drawing::Size(100, 20);
    this->textBox_Geschwindigkeit->TabIndex = 1;
    // 
    // textBox_Orientierung_A
    // 
    this->textBox_Orientierung_A->Location = System::Drawing::Point(319, 101);
    this->textBox_Orientierung_A->Name = L"textBox_Orientierung_A";
    this->textBox_Orientierung_A->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_A->TabIndex = 2;
    // 
    // textBox_Toleranz
    // 
    this->textBox_Toleranz->Location = System::Drawing::Point(469, 101);
    this->textBox_Toleranz->Name = L"textBox_Toleranz";
    this->textBox_Toleranz->Size = System::Drawing::Size(100, 20);
    this->textBox_Toleranz->TabIndex = 6;
    // 
    // textBox_Mittelwertfindung
    // 
    this->textBox_Mittelwertfindung->Location = System::Drawing::Point(619, 101);
    this->textBox_Mittelwertfindung->Name = L"textBox_Mittelwertfindung";
    this->textBox_Mittelwertfindung->Size = System::Drawing::Size(100, 20);
    this->textBox_Mittelwertfindung->TabIndex = 7;
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
    this->richTextBox_Log->Enabled = false;
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
    // 
    // textBox_Orientierung_B
    // 
    this->textBox_Orientierung_B->Location = System::Drawing::Point(319, 127);
    this->textBox_Orientierung_B->Name = L"textBox_Orientierung_B";
    this->textBox_Orientierung_B->Size = System::Drawing::Size(100, 20);
    this->textBox_Orientierung_B->TabIndex = 27;
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
    // RoboPathForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::ButtonShadow;
    this->ClientSize = System::Drawing::Size(784, 561);
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

System::Void UIRoboPathForms::RoboPathForm::CSVÖffnen_Click(System::Object^ sender, System::EventArgs^ e) {
    openFileDialog_CSV->ShowDialog();
}
System::Void UIRoboPathForms::RoboPathForm::openFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
    this->richTextBox_Log->Text = "Folgende .csv ist geladen: " + openFileDialog_CSV->FileName;
    Datastore->SetFilePath(openFileDialog_CSV->FileName);
}
System::Void UIRoboPathForms::RoboPathForm::AppendLog(std::string sMessage) {
    System::String^ sLogText = msclr::interop::marshal_as<System::String^>(sMessage);
    this->richTextBox_Log->AppendText(sLogText);
}
System::Void UIRoboPathForms::RoboPathForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
    /*LogicReadCSV::ReadCSV Reader;*/
    /*Reader.ReadAndReturnCSV(DataStore.GetFilePath());*/
}
System::Void UIRoboPathForms::RoboPathForm::SetVersion() {
    DataRoboPathVersion::RoboPathVersion xVersion;
    this->textBox_Version->Text = xVersion.getVersion();
}