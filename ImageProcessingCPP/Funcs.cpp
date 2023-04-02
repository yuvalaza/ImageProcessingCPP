#include "Funcs.h"



MyMatrix initMask(string type,int size) {
	if (type!="laplac" && type!="sobelY" && type!="sobelX" ) {
		throw ErrorObject(UNDEFINED_MASK_TYPE_NUM, UNDEFINED_MASK_TYPE, LINK1);
	}
	MyMatrix mask(size, size);
	if (type.substr(0,5)=="sobel") {
		mask=setSobel(type,size);
		return mask;
	}
	if (type == "laplac") {
		mask = setLaplac(size);
		return mask;
	}

	
}
MyMatrix setLaplac(int size) {
	MyMatrix mask(size, size);
	if (size == 3) {
		mask = laplac3();

	}
	else {
		mask = laplac5();
	}
	return mask;
}
MyMatrix laplac3() {
	MyMatrix lap3(3, 3);
	double rep3[3][3] = { {-1,-1,-1},{-1,8-1},{-1,-1,-1} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			lap3[i][j] = rep3[i][j];

		}
	}
	return lap3;
}

MyMatrix laplac5() {
	MyMatrix lap5(5, 5);
	double rep5[5][5] = { {0,0,-1,0,0},{0,-1,-2,-1,0},{-1,-2,16,-2,-1},{0,-1,-2,-1,0},{0,0,-1,0,0}};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			lap5[i][j] = rep5[i][j];

		}
	}
	return lap5;
}

MyMatrix setSobel(string type,int size) {
	MyMatrix sob(size,size);
	if (size == 3) {
		sob = Sobel3();
	}
	else {
		sob = Sobel5();
	}
	
//SobelY=(-1)*(sobelX^T)
	if(type[5]=='Y'){
		sob = ((sob.T())*(-1));
		return sob;
	}
	else {
		if (type[5] == 'X') {
			return sob;
		}
	}
	
	
	
	return sob;
}
MyMatrix Sobel3( ) {
	MyMatrix sob3(3, 3);
	double rep3[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sob3[i][j] = rep3[i][j];

		}
	}
	return sob3;
}
MyMatrix Sobel5() {
	MyMatrix sob5(5,5);
	double rep5[5][5] = { {-1,-2,0,2,1},{-2,-3,0,3,2},{-3,-5,0,5,3},{-2,-3,0,3,2},{-1,-2,0,2,1} };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sob5[i][j] = rep5[i][j];

		}
	}
	return sob5;
}
MyMatrix SobelMag(MyMatrix input,int size) {
	int rows= input.getRows();
	int cols = input.getCols();
	MyMatrix res(rows, cols);
	MyMatrix X = initMask("sobelX", size);
	MyMatrix Y = initMask("sobelY", size);
	MyMatrix dx(conv(input, X));
	MyMatrix dy(conv(input, Y));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			res[i][j] = sqrt((pow(dx[i][j], 2)) + (pow(dx[i][j], 2)));
		}
	}
	return res;
}


MyMatrix setGaus(int size, double sigma) {
	MyMatrix kernel(size, size);
	int k = (size - 1) / 2;
	int m = (size - 1) / 2;
	double factor = 1 / (2 * M_PI * pow(sigma, 2));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			kernel[i][j] = factor * exp((-0.5) * ((pow(i-k, 2) + pow(j-m, 2)) / pow(sigma, 2)));
			cout << kernel[i][j] << endl;
		}
	}
	return kernel;
}

MyMatrix conv(const MyMatrix& matA, const MyMatrix& filter) {
	int in_rows = matA.getRows();
	int in_cols = matA.getCols();
	int h_rows = filter.getRows();
	int h_cols = filter.getCols();
	double sum = 0;
	MyMatrix res(in_rows, in_cols);

	for (int i = 0; i < in_rows; i++) {
		for (int j = 0; j < in_cols; j++) {

			for (int n = 0; n < h_rows; n++) {
				if (i - n >= 0) {
					for (int m = 0; m < h_cols; m++) {
						if (j - m >= 0) {
							sum += matA[i - n][j - m] * filter[h_rows-1-n][h_cols-1-m];
						}
					}
				}
			}
			if (sum > 255) {
				res[i][j] = 255;
			}
			else {
				res[i][j] = sum;
			}
			
			sum = 0;
		}
	}

	return res;
}

MyMatrix getHaar(string type, int width,double W_L_ratio) {
	int length = width * W_L_ratio;
	if (type == "Vert") {
		return setVertHaar(width, length);
	}
	if (type == "Horiz") {
		return setHorizHaar(width, length);
	}
	if (type == "Diag") {
		return setDiagHaar(width, length);
	}
	if (type == "DoubleV") {
		return setDoubVertHaar(width, length);
	}
	if (type == "DoubleH") {
		return setDoubHoizHaar(width, length);
	}

}
static MyMatrix setVertHaar(int width,int length) {
	MyMatrix res(length, width);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (j <width / 2) {
				res[i][j] = 1;
			}
			else {
				res[i][j] = -1;
			}
		}
	}
	return res;
}
static MyMatrix setHorizHaar(int width, int length) {
	MyMatrix res(length, width);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i < length / 2) {
				res[i][j] = 1;
			}
			else {
				res[i][j] = -1;
			}
		}
	}
	return res;
}

static MyMatrix setDiagHaar(int width, int length) {
	MyMatrix res(length, width);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if ((i < length / 2 && j<width/2) || (i >= length / 2 && j >= width / 2)) {
				res[i][j] = 1;
			}
			else {
				res[i][j] = -1;
			}
		}
	}
	return res;
}

static MyMatrix setDoubHoizHaar(int width, int length) {
	MyMatrix res(length, width);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i <length /3  || i>=2*(length/3)) {
				res[i][j] = 1;
			}
			else {
				res[i][j] = -1;
			}
		}
	}
	return res;

}
static MyMatrix setDoubVertHaar(int width, int length) {
	MyMatrix res(length, width);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (j< width / 3 || j >= 2 * (width / 3)) {
				res[i][j] = 1;
			}
			else {
				res[i][j] = -1;
			}
		}
	}
	return res;
}
MyMatrix calcHaar(const MyMatrix& input,string type, int width, double W_L_ratio) {
	int rows = input.getRows();
	int cols = input.getCols();
	MyMatrix res(rows, cols);
	MyMatrix H(getHaar(type, width, W_L_ratio));
	MyMatrix integral(input.integ());


	return res;
}