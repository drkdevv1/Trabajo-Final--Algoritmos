#pragma once
#include "Juego.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormNivel2 : public System::Windows::Forms::Form
	{
		Juego^ juego;

		   //Bitmap^ background = gcnew Bitmap("img/mapa1.jpg");
		Bitmap^ background2 = gcnew Bitmap("img/mapa2.gif");
	public:
		FormNivel2(void)
		{
			InitializeComponent();
			juego = gcnew Juego(3, 6, 30,10);

		}

	protected:

		~FormNivel2()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 35;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FormNivel2::timer1_Tick);
			   // 
			   // FormNivel2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(908, 538);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"FormNivel2";
			   this->Text = L"FormNivel2";
			   this->Load += gcnew System::EventHandler(this, &FormNivel2::FormNivel2_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormNivel2::FormNivel2_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormNivel2::FormNivel2_KeyUp);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void FormNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = true;
	}

	private: System::Void FormNivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MovimientoJugador(true, e->KeyCode);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->DrawImage(background2, 0, 0, (int)bf->Graphics->VisibleClipBounds.Width, (int)bf->Graphics->VisibleClipBounds.Height);

		//bf->Graphics->Clear(Color::White);
		juego->Mostrar2(bf->Graphics);
		bf->Render(g);

		if (juego->Mover2(g) == false) {
			timer1->Enabled = false;  // Deshabilitamos el timer en lugar de cerrar la forma.
		}
		delete bf;
		delete bfc; 
		delete g;

	}
	private: System::Void FormNivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MovimientoJugador(false, e->KeyCode);
	}
		   /*
		   * private: System::Void FormNivel2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		juego->Disparar(e->Button);
	}
		   */
	
	};
}

