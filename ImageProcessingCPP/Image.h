#pragma once

#include "Funcs.h"




class Image
{
private:
	
	MyMatrix _histogram;
	string _path;

	
public:
	MyMatrix _gmat;
	MyMatrix calHist()const;
	Image(const string file_name);
	Image(int rows, int cols,string path="None");
	Image(const MyMatrix& other, string path = "None");
	void setPath(string path ) { this->_path = path; }
	void set_out_Path(string path,string input);
	void setGmat(int rows, int cols);
	void setGmat(const MyMatrix& other);
	void setHist();
	int getRows()const { return this->_gmat.getRows(); }
	int getCols()const { return this->_gmat.getCols(); }
	MyMatrix getHist()const { return this->_histogram; }
	MyMatrix getGmat()const { return this->_gmat; }
	string getPath()const { return this->_path; }
	void display()const;
	void save()const;
	int getHistPercentile(const int p)const; //returns the p'th percentile in the histogram
	void showHist()const;
	void drawHist(const vector<double>& data, Mat3b& dst, int binSize = 3, int height = 0)const;
	Image ContrastStretch()const;
	Image equalize()const;
	Image median(const int size = 3)const;
	Image gausBlur(const int size = 3, double const sigma = 0.477)const;
	Image edgeDetect(const string& type,int size=3,double sigma=0.5)const;
	Image corners(int size, double threshold_value= 5.1 * (pow(10, 7)));
	Image sift(double s=1.2, int gausSize = 15, double sigma = 1,int setSize=10, int window_Size=100);
	Image drawCirc(MyMatrix* maxSet,int setSize,int thickness,double radius, int factor=1.2)const;
};
