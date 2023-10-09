#pragma once
#include "MyForm.h"
#include "Creditos.h"
#include "FormInstrucciones.h"
#include "LvlSelector.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de FormMenu
	/// </summary>
	public ref class FormMenu : public System::Windows::Forms::Form {
	public:
		FormMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ bJugar;
	private: System::Windows::Forms::Button^ bInstrucciones;
	private: System::Windows::Forms::Button^ bCreditos;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenu::typeid));
			this->bJugar = (gcnew System::Windows::Forms::Button());
			this->bInstrucciones = (gcnew System::Windows::Forms::Button());
			this->bCreditos = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// bJugar
			// 
			this->bJugar->BackColor = System::Drawing::Color::OrangeRed;
			this->bJugar->FlatAppearance->BorderSize = 0;
			this->bJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bJugar->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bJugar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bJugar->Location = System::Drawing::Point(159, 274);
			this->bJugar->Name = L"bJugar";
			this->bJugar->Size = System::Drawing::Size(189, 66);
			this->bJugar->TabIndex = 2;
			this->bJugar->Text = L"Jugar";
			this->bJugar->UseVisualStyleBackColor = false;
			this->bJugar->Click += gcnew System::EventHandler(this, &FormMenu::bJugar_Click);
			// 
			// bInstrucciones
			// 
			this->bInstrucciones->BackColor = System::Drawing::Color::OrangeRed;
			this->bInstrucciones->FlatAppearance->BorderSize = 0;
			this->bInstrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bInstrucciones->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bInstrucciones->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bInstrucciones->Location = System::Drawing::Point(159, 372);
			this->bInstrucciones->Name = L"bInstrucciones";
			this->bInstrucciones->Size = System::Drawing::Size(189, 66);
			this->bInstrucciones->TabIndex = 3;
			this->bInstrucciones->Text = L"Instrucciones";
			this->bInstrucciones->UseVisualStyleBackColor = false;
			this->bInstrucciones->Click += gcnew System::EventHandler(this, &FormMenu::bInstrucciones_Click);
			// 
			// bCreditos
			// 
			this->bCreditos->BackColor = System::Drawing::Color::OrangeRed;
			this->bCreditos->FlatAppearance->BorderSize = 0;
			this->bCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bCreditos->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bCreditos->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bCreditos->Location = System::Drawing::Point(159, 468);
			this->bCreditos->Name = L"bCreditos";
			this->bCreditos->Size = System::Drawing::Size(189, 66);
			this->bCreditos->TabIndex = 4;
			this->bCreditos->Text = L"Creditos";
			this->bCreditos->UseVisualStyleBackColor = false;
			this->bCreditos->Click += gcnew System::EventHandler(this, &FormMenu::bCreditos_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(506, 675);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// FormMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(498, 654);
			this->Controls->Add(this->bCreditos);
			this->Controls->Add(this->bInstrucciones);
			this->Controls->Add(this->bJugar);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->Name = L"FormMenu";
			this->Text = L"FormMenu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ FormCreditos = gcnew Creditos();
		this->Visible = false;
		FormCreditos->ShowDialog();
		this->Visible = true;
	}
	private: System::Void bJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		LvlSelector^ selector = gcnew LvlSelector();
		this->Visible = false;
		selector->ShowDialog();
		//this->Visible = true;
	}

	private: System::Void bInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		FormInstrucciones^ instrucciones = gcnew FormInstrucciones();
		this->Visible = false;
		instrucciones->ShowDialog();
		this->Visible = true;
	}
	};
}
