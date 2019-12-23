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

	public: System::Windows::Forms::ProgressBar^ progressBar1;







	private: System::Windows::Forms::Button^ btnTest;
	private: System::Windows::Forms::Button^ btnGName;



	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Button^ btnAutoUpdate;
	private: System::Windows::Forms::CheckBox^ cbSDK;
	private: System::Windows::Forms::CheckBox^ cbAll;
	private: System::Windows::Forms::CheckBox^ cbGObj;
	private: System::Windows::Forms::Button^ btnNamesDump;
	public: System::Windows::Forms::RichTextBox^ LogBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnUpdateUseful;

	public:
	private:

	private:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnDumpSDK = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->btnGName = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->btnAutoUpdate = (gcnew System::Windows::Forms::Button());
			this->cbSDK = (gcnew System::Windows::Forms::CheckBox());
			this->cbAll = (gcnew System::Windows::Forms::CheckBox());
			this->cbGObj = (gcnew System::Windows::Forms::CheckBox());
			this->btnNamesDump = (gcnew System::Windows::Forms::Button());
			this->LogBox = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnUpdateUseful = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnDumpSDK
			// 
			this->btnDumpSDK->Location = System::Drawing::Point(127, 44);
			this->btnDumpSDK->Margin = System::Windows::Forms::Padding(4);
			this->btnDumpSDK->Name = L"btnDumpSDK";
			this->btnDumpSDK->Size = System::Drawing::Size(115, 32);
			this->btnDumpSDK->TabIndex = 0;
			this->btnDumpSDK->Text = L"Export SDK";
			this->btnDumpSDK->UseVisualStyleBackColor = true;
			this->btnDumpSDK->Click += gcnew System::EventHandler(this, &Main::btnDumpSDK_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->Location = System::Drawing::Point(12, 644);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(667, 33);
			this->progressBar1->TabIndex = 2;
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(4, 4);
			this->btnTest->Margin = System::Windows::Forms::Padding(4);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(115, 32);
			this->btnTest->TabIndex = 12;
			this->btnTest->Text = L"UObject Test";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Main::btnTest_Click);
			// 
			// btnGName
			// 
			this->btnGName->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnGName->Location = System::Drawing::Point(129, 4);
			this->btnGName->Margin = System::Windows::Forms::Padding(4);
			this->btnGName->Name = L"btnGName";
			this->btnGName->Size = System::Drawing::Size(115, 32);
			this->btnGName->TabIndex = 13;
			this->btnGName->Text = L"Find GName";
			this->btnGName->UseVisualStyleBackColor = true;
			this->btnGName->Click += gcnew System::EventHandler(this, &Main::btnFindGName_Click);
			// 
			// btnAutoUpdate
			// 
			this->btnAutoUpdate->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnAutoUpdate->Location = System::Drawing::Point(252, 4);
			this->btnAutoUpdate->Margin = System::Windows::Forms::Padding(4);
			this->btnAutoUpdate->Name = L"btnAutoUpdate";
			this->btnAutoUpdate->Size = System::Drawing::Size(115, 32);
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
			this->cbSDK->Location = System::Drawing::Point(250, 54);
			this->cbSDK->Margin = System::Windows::Forms::Padding(4);
			this->cbSDK->Name = L"cbSDK";
			this->cbSDK->Size = System::Drawing::Size(52, 22);
			this->cbSDK->TabIndex = 18;
			this->cbSDK->Text = L"SDK";
			this->cbSDK->UseVisualStyleBackColor = true;
			// 
			// cbAll
			// 
			this->cbAll->AutoSize = true;
			this->cbAll->Checked = true;
			this->cbAll->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbAll->Location = System::Drawing::Point(302, 54);
			this->cbAll->Margin = System::Windows::Forms::Padding(4);
			this->cbAll->Name = L"cbAll";
			this->cbAll->Size = System::Drawing::Size(113, 22);
			this->cbAll->TabIndex = 19;
			this->cbAll->Text = L"SDK in one file";
			this->cbAll->UseVisualStyleBackColor = true;
			// 
			// cbGObj
			// 
			this->cbGObj->AutoSize = true;
			this->cbGObj->Checked = true;
			this->cbGObj->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbGObj->Location = System::Drawing::Point(414, 54);
			this->cbGObj->Margin = System::Windows::Forms::Padding(4);
			this->cbGObj->Name = L"cbGObj";
			this->cbGObj->Size = System::Drawing::Size(103, 22);
			this->cbGObj->TabIndex = 20;
			this->cbGObj->Text = L"GlobalObects";
			this->cbGObj->UseVisualStyleBackColor = true;
			// 
			// btnNamesDump
			// 
			this->btnNamesDump->Location = System::Drawing::Point(4, 44);
			this->btnNamesDump->Margin = System::Windows::Forms::Padding(4);
			this->btnNamesDump->Name = L"btnNamesDump";
			this->btnNamesDump->Size = System::Drawing::Size(115, 32);
			this->btnNamesDump->TabIndex = 21;
			this->btnNamesDump->Text = L"Export Names";
			this->btnNamesDump->UseVisualStyleBackColor = true;
			this->btnNamesDump->Click += gcnew System::EventHandler(this, &Main::btnNamesDump_Click);
			// 
			// LogBox
			// 
			this->LogBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LogBox->Font = (gcnew System::Drawing::Font(L"PingFang SC0", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LogBox->Location = System::Drawing::Point(12, 98);
			this->LogBox->Name = L"LogBox";
			this->LogBox->ReadOnly = true;
			this->LogBox->Size = System::Drawing::Size(667, 534);
			this->LogBox->TabIndex = 22;
			this->LogBox->Text = L"";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->btnUpdateUseful);
			this->panel1->Controls->Add(this->btnTest);
			this->panel1->Controls->Add(this->btnDumpSDK);
			this->panel1->Controls->Add(this->btnNamesDump);
			this->panel1->Controls->Add(this->btnGName);
			this->panel1->Controls->Add(this->cbGObj);
			this->panel1->Controls->Add(this->btnAutoUpdate);
			this->panel1->Controls->Add(this->cbAll);
			this->panel1->Controls->Add(this->cbSDK);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(667, 80);
			this->panel1->TabIndex = 23;
			// 
			// btnUpdateUseful
			// 
			this->btnUpdateUseful->Location = System::Drawing::Point(525, 47);
			this->btnUpdateUseful->Margin = System::Windows::Forms::Padding(4);
			this->btnUpdateUseful->Name = L"btnUpdateUseful";
			this->btnUpdateUseful->Size = System::Drawing::Size(135, 32);
			this->btnUpdateUseful->TabIndex = 22;
			this->btnUpdateUseful->Text = L"Export Useful";
			this->btnUpdateUseful->UseVisualStyleBackColor = true;
			this->btnUpdateUseful->Click += gcnew System::EventHandler(this, &Main::btnUpdateUseful_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 689);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->LogBox);
			this->Controls->Add(this->progressBar1);
			this->Font = (gcnew System::Drawing::Font(L"PingFang SC0", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Main";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Lite SDK Generator - COHENRENCE";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnDumpSDK_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnFindGName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnAutoUpdate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnNamesDump_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnUpdateUseful_Click(System::Object^ sender, System::EventArgs^ e);
};
}
