#pragma once
#include "MyMatrix.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<algorithm>
using namespace cv;


class Image
{
private:
	MyMatrix _gmat;
	MyMatrix _histogram;
	string _path;

	void setHist();
public:
	Image(const string file_name);
	MyMatrix getHist()const { return this->_histogram; }
	MyMatrix getGmat()const { return this->_gmat; }
	string getPath()const { return this->_path; }
	void display()const;
	void showHist()const;
	void drawHist(const vector<int>& data, Mat3b& dst, int binSize = 3, int height = 0)const;


};
