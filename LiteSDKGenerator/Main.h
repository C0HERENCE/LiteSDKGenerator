#pragma once

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
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnDumpSDK;
	protected:

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textBox3;
	private:

	public:
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::TextBox^ textBox4;
	private:

	public:
	public: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnDumpSDKOld;
	private: System::Windows::Forms::Button^ btnDumpGObject;
	public:

	public:

	private: System::Windows::Forms::Button^ btnTest;
	private: System::Windows::Forms::Button^ btnGName;


	public: System::Windows::Forms::TextBox^ textBox5;
	private:
	public: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Button^ btnUpdate;

	private:
	public:
	private:
	public:

	public:
	private:
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			this->btnDumpSDKOld = (gcnew System::Windows::Forms::Button());
			this->btnDumpGObject = (gcnew System::Windows::Forms::Button());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->btnGName = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnDumpSDK
			// 
			this->btnDumpSDK->Location = System::Drawing::Point(15, 194);
			this->btnDumpSDK->Name = L"btnDumpSDK";
			this->btnDumpSDK->Size = System::Drawing::Size(75, 23);
			this->btnDumpSDK->TabIndex = 0;
			this->btnDumpSDK->Text = L"SDK";
			this->btnDumpSDK->UseVisualStyleBackColor = true;
			this->btnDumpSDK->Click += gcnew System::EventHandler(this, &Main::btnDumpSDK_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Process:";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(15, 223);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(257, 24);
			this->progressBar1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(65, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(65, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Module:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(65, 87);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"PID:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(65, 113);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Base:";
			// 
			// btnDumpSDKOld
			// 
			this->btnDumpSDKOld->Location = System::Drawing::Point(96, 194);
			this->btnDumpSDKOld->Name = L"btnDumpSDKOld";
			this->btnDumpSDKOld->Size = System::Drawing::Size(89, 23);
			this->btnDumpSDKOld->TabIndex = 10;
			this->btnDumpSDKOld->Text = L"SDK One File";
			this->btnDumpSDKOld->UseVisualStyleBackColor = true;
			this->btnDumpSDKOld->Click += gcnew System::EventHandler(this, &Main::btnDumpSdkOneFile_Click);
			// 
			// btnDumpGObject
			// 
			this->btnDumpGObject->Location = System::Drawing::Point(197, 194);
			this->btnDumpGObject->Name = L"btnDumpGObject";
			this->btnDumpGObject->Size = System::Drawing::Size(75, 23);
			this->btnDumpGObject->TabIndex = 11;
			this->btnDumpGObject->Text = L"GObjects";
			this->btnDumpGObject->UseVisualStyleBackColor = true;
			this->btnDumpGObject->Click += gcnew System::EventHandler(this, &Main::btnDumpTxt_Click);
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(121, 165);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(75, 23);
			this->btnTest->TabIndex = 12;
			this->btnTest->Text = L"Test";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Main::btnTest_Click);
			// 
			// btnGName
			// 
			this->btnGName->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnGName->Location = System::Drawing::Point(12, 6);
			this->btnGName->Name = L"btnGName";
			this->btnGName->Size = System::Drawing::Size(78, 23);
			this->btnGName->TabIndex = 13;
			this->btnGName->Text = L"Find GName";
			this->btnGName->UseVisualStyleBackColor = true;
			this->btnGName->Click += gcnew System::EventHandler(this, &Main::btnFindGName_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(65, 139);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 142);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Handle:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(15, 165);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 16;
			// 
			// btnUpdate
			// 
			this->btnUpdate->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnUpdate->Location = System::Drawing::Point(96, 6);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(78, 23);
			this->btnUpdate->TabIndex = 17;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Main::btnUpdate_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 256);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnGName);
			this->Controls->Add(this->btnTest);
			this->Controls->Add(this->btnDumpGObject);
			this->Controls->Add(this->btnDumpSDKOld);
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
	private: System::Void btnDumpSdkOneFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDumpTxt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnFindGName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
};
}