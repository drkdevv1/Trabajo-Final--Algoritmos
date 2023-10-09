#pragma once

namespace TF {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Resumen de FormVictory
    /// </summary>
    public ref class FormVictory : public System::Windows::Forms::Form
    {
    public:
        FormVictory(void)
        {
            InitializeComponent();
            //
            //TODO: agregar código de constructor aquí
            //
        }

    protected:
        ~FormVictory()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ btnMainMenu;
    private: System::Windows::Forms::PictureBox^ pbWinner;
    private: System::Windows::Forms::PictureBox^ pictureBox1;



    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormVictory::typeid));
            this->btnMainMenu = (gcnew System::Windows::Forms::Button());
            this->pbWinner = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWinner))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // btnMainMenu
            // 
            this->btnMainMenu->BackColor = System::Drawing::Color::Red;
            this->btnMainMenu->FlatAppearance->BorderSize = 0;
            this->btnMainMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnMainMenu->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnMainMenu->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->btnMainMenu->Location = System::Drawing::Point(563, 357);
            this->btnMainMenu->Name = L"btnMainMenu";
            this->btnMainMenu->Size = System::Drawing::Size(143, 46);
            this->btnMainMenu->TabIndex = 0;
            this->btnMainMenu->Text = L"Salir";
            this->btnMainMenu->UseVisualStyleBackColor = false;
            this->btnMainMenu->Click += gcnew System::EventHandler(this, &FormVictory::btnMainMenu_Click);
            // 
            // pbWinner
            // 
            this->pbWinner->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbWinner.Image")));
            this->pbWinner->Location = System::Drawing::Point(-2, -4);
            this->pbWinner->Name = L"pbWinner";
            this->pbWinner->Size = System::Drawing::Size(742, 470);
            this->pbWinner->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbWinner->TabIndex = 1;
            this->pbWinner->TabStop = false;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(68, 75);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(179, 166);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 2;
            this->pictureBox1->TabStop = false;
            // 
            // FormVictory
            // 
            this->ClientSize = System::Drawing::Size(736, 461);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->btnMainMenu);
            this->Controls->Add(this->pbWinner);
            this->Name = L"FormVictory";
            this->Text = L"Victory";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWinner))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }

#pragma endregion
    private: System::Void btnMainMenu_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
    };
}
