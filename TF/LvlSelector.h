#pragma once
#include "MyForm.h"
#include "FormNivel2.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LvlSelector
	/// </summary>
	public ref class LvlSelector : public System::Windows::Forms::Form
	{
	public:
		LvlSelector(void)
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
		~LvlSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bLvl1;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LvlSelector::typeid));
			this->bLvl1 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// bLvl1
			// 
			this->bLvl1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bLvl1->FlatAppearance->BorderSize = 0;
			this->bLvl1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bLvl1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLvl1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bLvl1->Location = System::Drawing::Point(83, 218);
			this->bLvl1->Name = L"bLvl1";
			this->bLvl1->Size = System::Drawing::Size(189, 66);
			this->bLvl1->TabIndex = 3;
			this->bLvl1->Text = L"Nivel 1";
			this->bLvl1->UseVisualStyleBackColor = false;
			this->bLvl1->Click += gcnew System::EventHandler(this, &LvlSelector::bLvl1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(357, 218);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 66);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Nivel 2";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LvlSelector::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-35, -7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(763, 505);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// LvlSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 496);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->bLvl1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"LvlSelector";
			this->Text = L"LvlSelector";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bLvl1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ FormJuego = gcnew MyForm();
		this->Visible = false;
		FormJuego->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FormNivel2^ lvl2= gcnew FormNivel2();
		this->Visible = false;
		lvl2->Show();
}
};
}
