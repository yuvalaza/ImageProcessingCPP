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

	
public:
	MyMatrix calHist()const;
	Image(const string file_name);
	Image(int rows, int cols,string path="None");
	void setPath(string path ) { this->_path = path; }
	void setGmat(int rows, int cols);
	void setHist();
	MyMatrix getHist()const { return this->_histogram; }
	MyMatrix getGmat()const { return this->_gmat; }
	string getPath()const { return this->_path; }
	void display()const;
	int getHistPercentile(const int p)const; //returns the p'th percentile in the histogram
	void showHist()const;
	void drawHist(const vector<double>& data, Mat3b& dst, int binSize = 3, int height = 0)const;
	Image ContrastStretch()const;
	Image equalize()const;
	Image median(const int size = 3)const;

};
