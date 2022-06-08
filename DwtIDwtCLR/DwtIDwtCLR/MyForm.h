#pragma once
#include <cmath>

namespace DwtIDwtCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Drawing::Design;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ OpenFile_btn;
	private: System::Windows::Forms::Button^ DWT_btn;

	private: System::Windows::Forms::Button^ IDWT_btn;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;


	private:
		//定義影像類別(點陣圖(.bmp)，無壓縮，資訊較多)
		Bitmap^ ori_image, ^ comp_image;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->OpenFile_btn = (gcnew System::Windows::Forms::Button());
			this->DWT_btn = (gcnew System::Windows::Forms::Button());
			this->IDWT_btn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// OpenFile_btn
			// 
			this->OpenFile_btn->Location = System::Drawing::Point(28, 29);
			this->OpenFile_btn->Name = L"OpenFile_btn";
			this->OpenFile_btn->Size = System::Drawing::Size(75, 23);
			this->OpenFile_btn->TabIndex = 0;
			this->OpenFile_btn->Text = L"open";
			this->OpenFile_btn->UseVisualStyleBackColor = true;
			this->OpenFile_btn->Click += gcnew System::EventHandler(this, &MyForm::OpenFile_btn_Click);
			// 
			// DWT_btn
			// 
			this->DWT_btn->Location = System::Drawing::Point(571, 29);
			this->DWT_btn->Name = L"DWT_btn";
			this->DWT_btn->Size = System::Drawing::Size(103, 23);
			this->DWT_btn->TabIndex = 1;
			this->DWT_btn->Text = L"DWT";
			this->DWT_btn->UseVisualStyleBackColor = true;
			this->DWT_btn->Click += gcnew System::EventHandler(this, &MyForm::DWT_btn_Click);
			// 
			// IDWT_btn
			// 
			this->IDWT_btn->Location = System::Drawing::Point(1121, 29);
			this->IDWT_btn->Name = L"IDWT_btn";
			this->IDWT_btn->Size = System::Drawing::Size(103, 23);
			this->IDWT_btn->TabIndex = 2;
			this->IDWT_btn->Text = L"IDWT";
			this->IDWT_btn->UseVisualStyleBackColor = true;
			this->IDWT_btn->Click += gcnew System::EventHandler(this, &MyForm::IDWT_btn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(28, 69);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 512);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(571, 69);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(512, 512);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(1121, 69);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(512, 512);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1675, 671);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->IDWT_btn);
			this->Controls->Add(this->DWT_btn);
			this->Controls->Add(this->OpenFile_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void OpenFile_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->FileName = "";
		ofd->Filter = "All Files(*.*)|*.*";
		ofd->FilterIndex = 1;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK && ofd->FileName != "") {
			// read lena img
			Bitmap^ buff = gcnew Bitmap(ofd->FileName);

			ori_image = gcnew Bitmap(buff->Width, buff->Height, buff->PixelFormat);

			// Lock Memory
			BitmapData^ bd_ori = ori_image->LockBits(Rectangle(0, 0, ori_image->Width, ori_image->Height), ImageLockMode::ReadWrite, ori_image->PixelFormat);
			BitmapData^ bd_buff = buff->LockBits(Rectangle(0, 0, buff->Width, buff->Height), ImageLockMode::ReadWrite, buff->PixelFormat);

			int ori_byteskip = bd_ori->Stride - bd_ori->Width * 3;
			int buff_byteskip = bd_buff->Stride - bd_buff->Width * 3;

			Byte* ori_ptr = (Byte*)((void*)bd_ori->Scan0);
			Byte* buff_ptr = (Byte*)((void*)bd_buff->Scan0);

			// rgb to gray
			for (int y = 0; y < bd_ori->Height; y++) {
				for (int x = 0; x < bd_ori->Width; x++) {
					int B = (int)buff_ptr[0];
					int G = (int)buff_ptr[1];
					int R = (int)buff_ptr[2];

					int gray = (R + G + B) / 3;

					ori_ptr[0] = gray;
					ori_ptr[1] = gray;
					ori_ptr[2] = gray;

					ori_ptr += 3;
					buff_ptr += 3;
				}

				ori_ptr += ori_byteskip;
				buff_ptr += buff_byteskip;
			}


			// Unlock Memory
			ori_image->UnlockBits(bd_ori);
			buff->UnlockBits(bd_buff);
			pictureBox1->Image = ori_image;
		}
	}

	private: System::Void DWT_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ori_image == nullptr) {
			return;
		}
		comp_image = gcnew Bitmap(ori_image->Width, ori_image->Height, ori_image->PixelFormat);
		// Lock Memory
		BitmapData^ bd_ori = ori_image->LockBits(Rectangle(0, 0, ori_image->Width, ori_image->Height), ImageLockMode::ReadWrite, ori_image->PixelFormat);
		BitmapData^ bd_comp = comp_image->LockBits(Rectangle(0, 0, comp_image->Width, comp_image->Height), ImageLockMode::ReadWrite, comp_image->PixelFormat);

		int ori_byteskip = bd_ori->Stride - bd_ori->Width * 3;
		int comp_byteskip = bd_comp->Stride - bd_comp->Width * 3;

		Byte* ori_ptr = (Byte*)((void*)bd_ori->Scan0);
		Byte* comp_ptr = (Byte*)((void*)bd_comp->Scan0);

		int freq = 3; // the freq of compression

		int** img = new int* [ori_image->Height];
		int** buff = new int* [ori_image->Height];
		for (int i = 0; i < ori_image->Height; i++) {
			img[i] = new int[ori_image->Width];
			buff[i] = new int[ori_image->Width];
		}

		for (int y = 0; y < bd_ori->Height; y++) {
			for (int x = 0; x < bd_ori->Width; x++) {
				img[y][x] = (int)ori_ptr[0];
				ori_ptr += 3;
			}
			ori_ptr += ori_byteskip;
		}


		for (int n = 1; n <= freq; n++) {
			int height = (int)bd_ori->Height / n;
			int width = (int)bd_ori->Width / n;

			// row
			for (int scany = 0; scany < height; scany++) {
				for (int scanx = 0; scanx < width; scanx += 2) {
					int gray1 = img[scany][scanx];
					int gray2 = img[scany][scanx + 1];

					buff[scany][(int)(scanx / 2)] = round((float)(gray1 + gray2) / 2);
					buff[scany][(int)(scanx / 2) + (int)(width / 2)] = round((float)(gray1 - gray2) / 2);
				}
			}

			// column
			for (int scany = 0; scany < height; scany += 2) {
				for (int scanx = 0; scanx < width; scanx++) {
					int gray1 = buff[scany][scanx];
					int gray2 = buff[scany + 1][scanx];

					int avg = round((float)(gray1 + gray2) / 2);

					img[(int)(scany / 2)][scanx] = round((float)(gray1 + gray2) / 2);
					img[(int)(scany / 2) + (int)(height / 2)][scanx] = round((float)(gray1 - gray2) / 2);
				}
			}
		}

		for (int y = 0; y < bd_comp->Height; y++) {
			for (int x = 0; x < bd_comp->Width; x++) {

				int gray = img[y][x];

				//if (gray < 0) gray = 0;
				//if (gray > 255) gray = 255;

				comp_ptr[0] = gray;
				comp_ptr[1] = gray;
				comp_ptr[2] = gray;

				comp_ptr += 3;
			}
			comp_ptr += comp_byteskip;
		}

		// free memory
		for (int i = 0; i < ori_image->Height; i++) {
			delete img[i];
			delete buff[i];
		}

		// Unlock Memory
		ori_image->UnlockBits(bd_ori);
		comp_image->UnlockBits(bd_comp);
		pictureBox2->Image = comp_image;
	}

	private: System::Void IDWT_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comp_image == nullptr) {
			return;
		}

		Bitmap^ output = gcnew Bitmap(comp_image->Width, comp_image->Height, comp_image->PixelFormat);
		// Lock Memory
		BitmapData^ bd_comp = comp_image->LockBits(Rectangle(0, 0, comp_image->Width, comp_image->Height), ImageLockMode::ReadWrite, comp_image->PixelFormat);
		BitmapData^ bd_output = output->LockBits(Rectangle(0, 0, output->Width, output->Height), ImageLockMode::ReadWrite, output->PixelFormat);

		int comp_byteskip = bd_comp->Stride - bd_comp->Width * 3;
		int output_byteskip = bd_output->Stride - bd_output->Width * 3;

		Byte* comp_ptr = (Byte*)((void*)bd_comp->Scan0);
		Byte* output_ptr = (Byte*)((void*)bd_output->Scan0);

		int freq = 3; // the freq of compression

		int** img = new int* [ori_image->Height];
		int** buff = new int* [ori_image->Height];
		for (int i = 0; i < ori_image->Height; i++) {
			img[i] = new int[ori_image->Width];
			buff[i] = new int[ori_image->Width];
		}

		for (int y = 0; y < bd_comp->Height; y++) {
			for (int x = 0; x < bd_comp->Width; x++) {
				img[y][x] = (int)comp_ptr[0];
				comp_ptr += 3;
			}
			comp_ptr += comp_byteskip;
		}


		for (int n = freq; n >= 1; n--) {
			int height = (int)bd_comp->Height / n;
			int width = (int)bd_comp->Width / n;

			// column
			for (int scany = 0; scany < height; scany += 2) {
				for (int scanx = 0; scanx < width; scanx++) {
					int gray1 = img[(int)(scany / 2)][scanx];
					int gray2 = img[(int)(scany / 2) + (int)(height / 2)][scanx];

					buff[scany][scanx] = gray1 + gray2;
					buff[scany + 1][scanx] = gray1 - gray2;
				}
			}

			// row
			for (int scany = 0; scany < height; scany ++) {
				for (int scanx = 0; scanx < width; scanx += 2) {
					int gray1 = buff[scany][(int)(scanx / 2)];
					int gray2 = buff[scany][(int)(scanx / 2) + (int)(width / 2)];

					img[scany][scanx] = gray1 + gray2;
					img[scany][scanx + 1] = gray1 - gray2;
				}
			}
		}

		for (int y = 0; y < bd_output->Height; y++) {
			for (int x = 0; x < bd_output->Width; x++) {

				int gray = img[y][x];

				//if (gray < 0) gray = 0;
				//if (gray > 255) gray = 255;

				output_ptr[0] = gray;
				output_ptr[1] = gray;
				output_ptr[2] = gray;

				output_ptr += 3;
			}
			output_ptr += output_byteskip;
		}

		// free memory
		for (int i = 0; i < ori_image->Height; i++) {
			delete img[i];
			delete buff[i];
		}

		// Unlock Memory
		comp_image->UnlockBits(bd_comp);
		output->UnlockBits(bd_output);
		pictureBox3->Image = output;
	}

	private: float ceil_float2(float f) {
		if ((float)(round)(f * 10) / 10 == -0) return 0; // avoid "-0"
		else return (float)(round)(f * 10) / 10;
	}

	private: void DWT(float** img, int org_ratio, int ratio) {

		float** buff = new float* [org_ratio];
		for (int i = 0; i < org_ratio; i++) {
			buff[i] = new float[org_ratio];
		}

		int height = ratio;
		int width = ratio;

		// copy 
		for (int scany = 0; scany < height; scany++) {
			for (int scanx = 0; scanx < width; scanx++) {
				buff[scany][scanx] = img[scany][scanx];
			}
		}

		// row
		for (int scany = 0; scany < height; scany++) {
			for (int scanx = 0; scanx < width; scanx += 2) {
				float gray1 = ceil_float2((float)img[scany][scanx]);
				float gray2 = ceil_float2((float)img[scany][scanx + 1]);

				float avg = ceil_float2(((float)gray1 + (float)gray2) / 2);

				buff[scany][(int)(scanx / 2)] = ceil_float2((float)avg);
				buff[scany][(int)(scanx / 2) + (int)(width / 2)] = ceil_float2((float)avg - (float)gray2);
			}
		}

		// col
		for (int scany = 0; scany < height; scany += 2) {
			for (int scanx = 0; scanx < width; scanx++) {
				float gray1 = ceil_float2((float)buff[scany][scanx]);
				float gray2 = ceil_float2((float)buff[scany + 1][scanx]);

				float avg = ceil_float2(((float)gray1 + (float)gray2) / 2);

				img[(int)(scany / 2)][scanx] = ceil_float2((float)avg);
				img[(int)(scany / 2) + (int)(height / 2)][scanx] = ceil_float2((float)avg - (float)gray2);
			}
		}

		for (int i = 0; i < org_ratio; i++) {
			delete buff[i];
		}

	}

	private: void IDWT(float** img, int org_ratio, int ratio) {

		float** buff = new float* [org_ratio];
		for (int i = 0; i < org_ratio; i++) {
			buff[i] = new float[org_ratio];
		}

		int height = ratio;
		int width = ratio;

		// copy 
		for (int scany = 0; scany < height; scany++) {
			for (int scanx = 0; scanx < width; scanx++) {
				buff[scany][scanx] = img[scany][scanx];
			}
		}

		// col
		for (int scany = 0; scany < height; scany += 2) {
			for (int scanx = 0; scanx < width; scanx++) {
				float gray1 = (float)img[(int)(scany / 2)][scanx];
				float gray2 = (float)img[(int)(scany / 2) + (int)(height / 2)][scanx]; // avg

				buff[scany][scanx] = ceil_float2((float)gray1 + (float)gray2);
				buff[scany + 1][scanx] = ceil_float2((float)gray1 - (float)gray2);
			}
		}

		// row
		for (int scany = 0; scany < height; scany++) {
			for (int scanx = 0; scanx < width; scanx += 2) {
				float gray1 = (float)buff[scany][(int)(scanx / 2)];
				float gray2 = (float)buff[scany][(int)(scanx / 2) + (int)(width / 2)];

				img[scany][scanx] = ceil_float2((float)gray1 + (float)gray2);
				img[scany][scanx + 1] = ceil_float2((float)gray1 - (float)gray2);
			}
		}

		for (int i = 0; i < org_ratio; i++) {
			delete buff[i];
		}
	}
	};
}
