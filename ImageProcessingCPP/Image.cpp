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
	this->_histogram=this->calHist();
	this->_path = path;
}
Image:: Image(int rows, int cols, string path) {
	this->setGmat(rows, cols);
	this->setHist(1, 256);
	this->setPath(path);
}

void Image::setGmat(int rows,int cols) {
	this->_gmat.setMatrix(rows, cols);
}

void Image::setHist(int rows, int cols) {
	this->_histogram.setMatrix(rows, cols);
}

MyMatrix Image::calHist() {
MyMatrix res_hist(1, 256);

int temp;
for (int i = 0; i < this->_gmat.getRows(); i++) {
	for (int j = 0; j < this->_gmat.getCols(); j++) {
		temp = this->_gmat[i][j];
		res_hist[0][temp] += 1;
	}
}
//normalize_factor = double(temp_hist); //normalization by the histogram's sum
return res_hist;
}

void Image::display()const {
	Mat new_image(this->_gmat.getRows(), this->_gmat.getCols(), CV_64F);
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
	double normalize_factor = 100;
	String windowName;
	float temp;
	vector<double>hist(256);
	for (int i = 0; i < this->_histogram.getCols(); i++) {
		hist[i] = this->_histogram[0][i];
		hist[i] = hist[i] * (1 / normalize_factor);
	}



	Mat3b image;
	drawHist(hist, image);
	imshow("Histogram", image);
	waitKey(0);
	destroyWindow(windowName);
}
void Image::drawHist(const vector<double>& data, Mat3b& dst, int binSize, int height)const
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
		rectangle(dst, Point(i * binSize, h), Point((i + 1) * binSize - 1, rows), (i % 2) ? Scalar(0, 100, 255) : Scalar(0, 0, 255), cv::FILLED);
	}

}

int Image::getHistPercentile(const int p)const {
	double num_of_pix = this->_gmat.getRows() * this->_gmat.getCols();
	double sum = 0;
	double percentile = (double(p) / 100) * (num_of_pix);
	for (int i = 0; i < this->_histogram.getCols(); i++) {
		if (sum > percentile) {
			return i;
		}
		sum += this->_histogram[0][i];
	}
}

Image Image::ContrastStretch() {
	int rows = this->getGmat().getRows();
	int cols = this->getGmat().getCols();
	Image contrast(rows, cols);
	int max = this->getHistPercentile(95);
	int min = this->getHistPercentile(5);
	int low = 0;
	int high = 255;
	double factor = double(high - low) / double(max - min);
	cout << max << endl;
	cout << min << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if ((this->_gmat[i][j] - min) <= 0)
			{
				this->_gmat[i][j]= 0;
			}
			contrast._gmat[i][j] = (((this->_gmat[i][j]) - min) * (factor)) + low;
			if (contrast._gmat[i][j] > 255) {
				contrast._gmat[i][j] = 255;
			}
		}
		
	}
	contrast._histogram = contrast.calHist();
	contrast.setPath(this->getPath() + "-ContrastStretch");
	return contrast;

}