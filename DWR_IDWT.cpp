#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

float ceil_float2(float f) {
	if ((float)(round)(f * 10) / 10 == -0 || ((float)(round)(f * 10) > 0 && (float)(round)(f * 10) < 0.000001)) return 0; // avoid "-0" and "x.xxxxxe-20"
	else return (float)(round)(f * 10) / 10;
}

template <typename T>
void show_img(T** img, int ratio, int space = 6) {
	int height = ratio;
	int width = ratio;
	for (int scany = 0; scany < height; scany++) {
		for (int scanx = 0; scanx < width; scanx++) {
			cout << setw(space) << img[scany][scanx] << "\t";
		}
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------------------" << endl << endl;
}

void DWT(float** img, int org_ratio, int ratio) {

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

	show_img(buff, org_ratio);

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

	show_img(img, org_ratio);

	for (int i = 0; i < org_ratio; i++) {
		delete buff[i];
	}

}

void IDWT(float** img, int org_ratio, int ratio) {

	float** buff = new float* [org_ratio];
	for (int i = 0; i < org_ratio; i++) {
		buff[i] = new float[org_ratio];
	}

	int height = ratio;
	int width = ratio;

	// copy 
	for (int scany = 0; scany < height; scany ++) {
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

	show_img(buff, org_ratio);

	// row
	for (int scany = 0; scany < height; scany++) {
		for (int scanx = 0; scanx < width; scanx += 2) {
			float gray1 = (float)buff[scany][(int)(scanx / 2)];
			float gray2 = (float)buff[scany][(int)(scanx / 2) + (int)(width / 2)];

			img[scany][scanx] = ceil_float2((float)gray1 + (float)gray2);
			img[scany][scanx + 1] = ceil_float2((float)gray1 - (float)gray2);
		}
	}

	show_img(img, org_ratio);

	for (int i = 0; i < org_ratio; i++) {
		delete buff[i];
	}
}

void DWT_IDWT(int** img_in, int ratio) {

	float** img = new float* [ratio];
	for (int i = 0; i < ratio; i++) {
		img[i] = new float[ratio];
		for (int j = 0; j < ratio; j++) {
			img[i][j] = ceil_float2(img_in[i][j]);
		}
	}

	cout << "==> DWT<==" << endl;
	float n = (float)ratio;
	while (n >= 2) {
		DWT(img, ratio, int(n));
		n /= 2;
	}

	// Quantification
	for (int i = 0; i < ratio; i++) {
		for (int j = 0; j < ratio; j++) {
			img[i][j] = round(img[i][j]);
		}
	}
	cout << "==> FINISH DWT & Quantification <==" << endl;
	show_img(img, ratio);

	cout << "==> IDWT <==" << endl;
	n = 2;
	while (n <= ratio) {
		IDWT(img, ratio, (int)n);
		n *= 2;
	}

	cout << "==> FINISH IDWT <==" << endl;
	show_img(img, ratio);

	for (int i = 0; i < ratio; i++) {
		for (int j = 0; j < ratio; j++) {
			img_in[i][j] = round(img[i][j]);
		}
	}

	for (int i = 0; i < ratio; i++) {
		delete img[i];
	}
}


int main() {
	// modify your img
	int input[8][8] = {
		{20, 24, 20, 22, 24, 28, 24, 22},
		{20, 22, 18, 22, 20, 26, 10, 22},
		{18, 20, 18, 18, 18, 10, 12, 19},
		{18, 16, 14, 16, 14, 16, 18, 18},
		{14, 12, 10, 18, 16, 14, 16, 16},
		{12, 18, 12, 10, 16, 16, 16, 16},
		{12, 18, 16, 16, 16, 10, 16, 16},
		{ 8,  8,  8,  8,  8,  8, 16, 16},
	};

	int ratio = 8;

	int** img = new int* [ratio];
	for (int i = 0; i < ratio; i++) {
		img[i] = new int[ratio];
		for (int j = 0; j < ratio; j++) {
			img[i][j] = input[i][j];
		}
	}

	cout << "==> ORIGINAL IMG <==" << endl;
	show_img(img, ratio, 2);

	int buff_ratio = ratio;
	DWT_IDWT(img, ratio);
}