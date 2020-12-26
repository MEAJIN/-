#include "MyForm.h"
#include "mainForm.h"

#include <iostream>
using namespace System;
using namespace System::Windows::Forms;





[STAThreadAttribute]
void Main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project1::MyForm form;
	Application::Run(% form);
	std::fstream os("isitlogin.txt");
	if (os) {
		std::string temp;
		while (os >> temp) {
			if (temp == "nope") {
				break;
			}
			else {
				Project1::mainForm form1;
				Application::Run(% form1);
			}
		}

	}
	std::fstream isitlogin("isitlogin.txt", std::ios::out);
	isitlogin << "nope";
	isitlogin.close();

}
