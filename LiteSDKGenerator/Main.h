#pragma once
#define ManagedStr(x) (gcnew String((x).c_str()))
#define NativeStr(x) (managedStrToNative(x))
namespace LiteSDKGenerator {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			Application::EnableVisualStyles();
			InitializeComponent();
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnDumpSDK;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textBox3;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::TextBox^ textBox4;
	public: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnTest;
	private: System::Windows::Forms::Button^ btnGName;
	public: System::Windows::Forms::TextBox^ textBox5;
	public: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Button^ btnAutoUpdate;
	private: System::Windows::Forms::CheckBox^ cbSDK;
	private: System::Windows::Forms::CheckBox^ cbAll;
	private: System::Windows::Forms::CheckBox^ cbGObj;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnDumpSDK = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->btnGName = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->btnAutoUpdate = (gcnew System::Windows::Forms::Button());
			this->cbSDK = (gcnew System::Windows::Forms::CheckBox());
			this->cbAll = (gcnew System::Windows::Forms::CheckBox());
			this->cbGObj = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// btnDumpSDK
			// 
			this->btnDumpSDK->Location = System::Drawing::Point(221, 205);
			this->btnDumpSDK->Name = L"btnDumpSDK";
			this->btnDumpSDK->Size = System::Drawing::Size(98, 23);
			this->btnDumpSDK->TabIndex = 0;
			this->btnDumpSDK->Text = L"Start Dump";
			this->btnDumpSDK->UseVisualStyleBackColor = true;
			this->btnDumpSDK->Click += gcnew System::EventHandler(this, &Main::btnDumpSDK_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Process:";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(15, 234);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(304, 24);
			this->progressBar1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(65, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(65, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Module:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(65, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"PID:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(65, 84);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Base:";
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(13, 136);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(98, 23);
			this->btnTest->TabIndex = 12;
			this->btnTest->Text = L"UObject Test";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Main::btnTest_Click);
			// 
			// btnGName
			// 
			this->btnGName->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnGName->Location = System::Drawing::Point(117, 136);
			this->btnGName->Name = L"btnGName";
			this->btnGName->Size = System::Drawing::Size(98, 23);
			this->btnGName->TabIndex = 13;
			this->btnGName->Text = L"Find GName";
			this->btnGName->UseVisualStyleBackColor = true;
			this->btnGName->Click += gcnew System::EventHandler(this, &Main::btnFindGName_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(65, 110);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Handle:";
			// 
			// btnAutoUpdate
			// 
			this->btnAutoUpdate->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnAutoUpdate->Location = System::Drawing::Point(221, 136);
			this->btnAutoUpdate->Name = L"btnAutoUpdate";
			this->btnAutoUpdate->Size = System::Drawing::Size(98, 23);
			this->btnAutoUpdate->TabIndex = 17;
			this->btnAutoUpdate->Text = L"Auto Update";
			this->btnAutoUpdate->UseVisualStyleBackColor = true;
			this->btnAutoUpdate->Click += gcnew System::EventHandler(this, &Main::btnAutoUpdate_Click);
			// 
			// cbSDK
			// 
			this->cbSDK->AutoSize = true;
			this->cbSDK->Checked = true;
			this->cbSDK->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbSDK->Location = System::Drawing::Point(15, 165);
			this->cbSDK->Name = L"cbSDK";
			this->cbSDK->Size = System::Drawing::Size(48, 17);
			this->cbSDK->TabIndex = 18;
			this->cbSDK->Text = L"SDK";
			this->cbSDK->UseVisualStyleBackColor = true;
			// 
			// cbAll
			// 
			this->cbAll->AutoSize = true;
			this->cbAll->Checked = true;
			this->cbAll->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbAll->Location = System::Drawing::Point(15, 188);
			this->cbAll->Name = L"cbAll";
			this->cbAll->Size = System::Drawing::Size(96, 17);
			this->cbAll->TabIndex = 19;
			this->cbAll->Text = L"SDK in one file";
			this->cbAll->UseVisualStyleBackColor = true;
			// 
			// cbGObj
			// 
			this->cbGObj->AutoSize = true;
			this->cbGObj->Checked = true;
			this->cbGObj->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbGObj->Location = System::Drawing::Point(15, 211);
			this->cbGObj->Name = L"cbGObj";
			this->cbGObj->Size = System::Drawing::Size(90, 17);
			this->cbGObj->TabIndex = 20;
			this->cbGObj->Text = L"GlobalObects";
			this->cbGObj->UseVisualStyleBackColor = true;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 267);
			this->Controls->Add(this->cbGObj);
			this->Controls->Add(this->cbAll);
			this->Controls->Add(this->cbSDK);
			this->Controls->Add(this->btnAutoUpdate);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnGName);
			this->Controls->Add(this->btnTest);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnDumpSDK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnDumpSDK_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnFindGName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnAutoUpdate_Click(System::Object^ sender, System::EventArgs^ e);
};
}
