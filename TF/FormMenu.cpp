#include "FormMenu.h"
using namespace System::Windows::Forms;
using namespace TF;
int main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew FormMenu());
	return 0;
}

