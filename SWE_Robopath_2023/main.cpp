#include "pch.h"
#include "RoboPathForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew UserInterface::RoboPathForm());
  return 0;
}