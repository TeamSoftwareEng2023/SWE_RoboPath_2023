#pragma once
#include"pch.h"
#include"RoboPathVersion.h"
#include"RoboPath.h"

namespace UIRoboPathForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class RoboPathForm : public System::Windows::Forms::Form
	{
	public:
		RoboPathForm(void);

	protected:
		~RoboPathForm();
	private: DataRoboPath::RoboPath^ Datastore;
	private: System::Windows::Forms::Button^ SetButton;
	private: System::Windows::Forms::TextBox^ textBox_Geschwindigkeit;
	private: System::Windows::Forms::TextBox^ textBox_Orientierung_A;

	private: System::Windows::Forms::TextBox^ textBox_Toleranz;
	private: System::Windows::Forms::TextBox^ textBox_Mittelwertfindung;
	private: System::Windows::Forms::CheckBox^ checkBox_Geschwindigkeit;
	private: System::Windows::Forms::CheckBox^ checkBox_Orientierung;

	private: System::Windows::Forms::Label^ label_Geschwindigkeit;
	private: System::Windows::Forms::Label^ label_Orientierung;
	private: System::Windows::Forms::Label^ label_Toleranz;
	private: System::Windows::Forms::Label^ label_Mittelwertfindung;
	private: System::Windows::Forms::Button^ CSVÖffnenButton;

	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::TextBox^ textBoxGeschwindigkeit_Aktuell;
	private: System::Windows::Forms::TextBox^ textBox_Orientierung_A_Aktuell;

	private: System::Windows::Forms::TextBox^ textBox_Toleranz_Aktuell;
	private: System::Windows::Forms::TextBox^ textBox_Mittelwert_Aktuell;
	private: System::Windows::Forms::Label^ label_ActWerte_1;


	private: System::Windows::Forms::TextBox^ textBox_Version;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_CSV;
	private: System::Windows::Forms::RichTextBox^ richTextBox_Log;
	private: System::Windows::Forms::TextBox^ textBox_Orientierung_C_Aktuell;

	private: System::Windows::Forms::TextBox^ textBox_Orientierung_B_Aktuell;

	private: System::Windows::Forms::TextBox^ textBox_Orientierung_C;

	private: System::Windows::Forms::TextBox^ textBox_Orientierung_B;
	private: System::Windows::Forms::Label^ label_C;

	private: System::Windows::Forms::Label^ label_B;
	private: System::Windows::Forms::Label^ label_ActB;


	private: System::Windows::Forms::Label^ label_ActA;
	private: System::Windows::Forms::Label^ label_ActC;


	private: System::Windows::Forms::Label^ label_A;
	private: System::Windows::Forms::Label^ label_ActWerte_2;
	private: System::Windows::Forms::Label^ label_Geschwindigkeit_Einheit_Wert;
	private: System::Windows::Forms::Label^ label_Geschwindigkeit_Einheit_Act_Wert;
	private: System::Windows::Forms::Label^ label_Toleranz_Wert;
	private: System::Windows::Forms::Label^ label_Toleranz_Act_Wert;
	private: System::Windows::Forms::Label^ label_Überschrift;



	private: System::ComponentModel::IContainer^ components;
	private: void InitializeComponent();


	private: System::Void openFileDialog_CSV_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void CSVÖffnen_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void AppendLog(std::string sMessage);
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SetVersion();
	};
}
#pragma endregion