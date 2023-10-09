#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormInstrucciones
	/// </summary>
	public ref class FormInstrucciones : public System::Windows::Forms::Form
	{
	public:
		FormInstrucciones(void)
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
		~FormInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormInstrucciones::typeid));
			this->SuspendLayout();
			// 
			// FormInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(577, 611);
			this->Name = L"FormInstrucciones";
			this->Text = L"FormInstrucciones";
			this->Load += gcnew System::EventHandler(this, &FormInstrucciones::FormInstrucciones_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormInstrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
