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
void Image::showHist()const {
	String windowName;
	float temp;
	vector<int>hist(256);
	for (int i = 0; i < this->_histogram.getCols(); i++) {
		hist[i] = this->_histogram[0][i];
		cout << this->_histogram[0][i];
		cout <<  " index: " << i << endl;
	}

	Mat3b image;
	drawHist(hist, image);
	imshow("Histogram", image);
	waitKey(0);
	destroyWindow(windowName);
}
void Image:: drawHist(const vector<int>& data, Mat3b& dst, int binSize , int height )const
{
	int max_value = *max_element(data.begin(), data.end());
	int rows = 0;
	int cols = 0;
	if (height == 0) {
		rows = max_value + 10;
	}
	else {
		rows = max(max_value + 10, height);
	}

	cols = data.size() * binSize;

	dst = Mat3b(rows, cols, Vec3b(0, 0, 0));

	for (int i = 0; i < data.size(); ++i)
	{
		int h = rows - data[i];
		rectangle(dst, Point(i * binSize, h), Point((i + 1) * binSize - 1, rows), (i % 2) ? Scalar(0, 100, 255) : Scalar(0, 0, 255),cv::FILLED);
	}

}

