#include "Image.h"

Image::Image(const string path) {
	Mat  load_image = imread(path,IMREAD_GRAYSCALE);
	if (!load_image.data)
	{
		throw ErrorObject(LOAD_FAILED_NUM, LOAD_FAILED, LINK1);

	}
	Mat new_image;
	load_image.convertTo(new_image, CV_64F);
	MyMatrix gray(new_image.rows, new_image.cols);
	for (int i = 0; i < new_image.rows; i++) {

		for (int j = 0; j < new_image.cols; j++) {
			gray[i][j] = new_image.at<double>(i, j);
		


		}
	}
	this->_gmat = gray;
	this->setHist();
	this->_path = path;
}

void Image::setHist() {
	MyMatrix temp_hist(1, 256);
	int temp;
	for (int i = 0; i < this->_gmat.getRows(); i++) {
		for (int j = 0; j < this->_gmat.getCols(); j++) {
			temp = this->_gmat[i][j];
			temp_hist[0][temp]+=1;
		}
	}

	this->_histogram = temp_hist;
}

void Image::display()const{
	Mat new_image(this->_gmat.getRows(),this->_gmat.getCols(),CV_64F);
	String windowName;
	for (int i = 0; i < this->_gmat.getRows(); i++) {
		for (int j = 0; j < this->_gmat.getCols(); j++)
		{
			new_image.at<double>(i, j) = this->_gmat[i][j];
		}

	}
	new_image.convertTo(new_image, CV_8U);

	windowName = this->_path; 
	namedWindow(windowName); 
	imshow(windowName, new_image);
	waitKey(0); 
	destroyWindow(windowName);
}