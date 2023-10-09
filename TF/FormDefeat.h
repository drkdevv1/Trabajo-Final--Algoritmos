#pragma once
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormDefeat
	/// </summary>
	public ref class FormDefeat : public System::Windows::Forms::Form
	{
	public:
		FormDefeat(void)
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
		~FormDefeat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbDefeat;
	private: System::Windows::Forms::Button^ bBack;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormDefeat::typeid));
			this->pbDefeat = (gcnew System::Windows::Forms::PictureBox());
			this->bBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDefeat))->BeginInit();
			this->SuspendLayout();
			// 
			// pbDefeat
			// 
			this->pbDefeat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbDefeat.Image")));
			this->pbDefeat->Location = System::Drawing::Point(-2, -2);
			this->pbDefeat->Name = L"pbDefeat";
			this->pbDefeat->Size = System::Drawing::Size(600, 500);
			this->pbDefeat->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbDefeat->TabIndex = 0;
			this->pbDefeat->TabStop = false;
			// 
			// bBack
			// 
			this->bBack->BackColor = System::Drawing::Color::DarkRed;
			this->bBack->FlatAppearance->BorderSize = 0;
			this->bBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bBack->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bBack->Location = System::Drawing::Point(243, 370);
			this->bBack->Name = L"bBack";
			this->bBack->Size = System::Drawing::Size(126, 36);
			this->bBack->TabIndex = 1;
			this->bBack->Text = L"Salir";
			this->bBack->UseVisualStyleBackColor = false;
			this->bBack->Click += gcnew System::EventHandler(this, &FormDefeat::bBack_Click);
			// 
			// FormDefeat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 495);
			this->Controls->Add(this->bBack);
			this->Controls->Add(this->pbDefeat);
			this->Name = L"FormDefeat";
			this->Text = L"GameOver";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDefeat))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bBack_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
