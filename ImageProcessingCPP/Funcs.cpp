#include "Funcs.h"



MyMatrix initMask(string type,int size) {
	MyMatrix mask(size, size);
	if (type=="sobel") {
		mask=setSobel(type,size);

	}
	return mask;
}
MyMatrix setSobel(string type,int size) {
	if (size != 3 && size != 5) {
		throw ErrorObject(INVALID_SOBER_SIZE_NUM, INVALID_SOBER_SIZE, LINK1);
	}
	MyMatrix sob(size, size);
	double rep[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sob[i][j] = rep[i][j];
			
		}
	}
	return sob;
}
MyMatrix setGaus(double sigma, int size) {
	MyMatrix kernel(size, size);
	int k = (size - 1) / 2;
	int m = (size - 1) / 2;
	double factor = 1 / (2 * M_PI * pow(sigma, 2));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			kernel[i][j] = factor * exp((-0.5) * ((pow(i-k, 2) + pow(j-m, 2)) / pow(sigma, 2)));
			//cout << kernel[i][j] << endl;
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
				if (i - n > 0) {
					for (int m = 0; m < h_cols; m++) {
						if (j - m > 0) {
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

	
