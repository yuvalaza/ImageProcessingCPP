#include "Image.h"

Image::Image(const string file_name) {
	Mat  img2 = imread(file_name,IMREAD_GRAYSCALE);
	Mat new_image;
	img2.convertTo(new_image, CV_32FC1);
	MyMatrix gray(new_image.rows, new_image.cols);
	for (int i = 0; i < new_image.rows; i++) {

		for (int j = 0; j < new_image.cols; j++) {
			gray[i][j] = new_image.at<float>(i, j);


		}
	}
	this->_gmat = gray;
	this->setHist();
}

void Image::setHist() {
	MyMatrix temp_hist(1, 256);
	for (int i = 0; i < this->_gmat.getRows(); i++) {
		for (int j = 0; j < this->_gmat.getCols(); j++) {
			int temp = this->_gmat[i][j];
			temp_hist[0][temp]+=1;
		}
	}

	this->_histogram = temp_hist;
}