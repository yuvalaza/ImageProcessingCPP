#pragma once
#include "ErrorObject.h"
#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include<algorithm>
using namespace cv;
using namespace std;

class MyMatrix 
{
private:
	double** _matrix;
	int _n;
	int _m;

	void mergeSort(double* arr,int first,int last);
	void merge(double* arr, int const left, int const mid, int const right);

public:
	MyMatrix();
	MyMatrix(int n, int m);
	MyMatrix(const MyMatrix& other);
	MyMatrix(const Mat& other);
	~MyMatrix();
	void setMatrix(int n = 3, int m = 3);
	int getRows()const { return this->_n; }
	int getCols()const { return this->_m; }
	double max()const;
	double min()const;
	MyMatrix mul(const MyMatrix& other)const;
	MyMatrix T()const;
	MyMatrix abs()const;
	MyMatrix integ()const;
	MyMatrix localMax(int window_Size = 3)const;
	//In order to deal with the overlap and get the real local max matrix;
	void clean_localMax(MyMatrix& res,double max, int window_Size,int indexX, int indexY, int rows, int cols)const;
	void sort();
	void cvNorm();
	Mat getCV_mat();
	



	MyMatrix& operator=(const MyMatrix& other);
	bool operator==(const MyMatrix& other) const;
	MyMatrix operator+(const MyMatrix& other) const;
	MyMatrix operator-(const MyMatrix& other) const;
	operator double() const;
	MyMatrix operator*(const MyMatrix& other) const;
	MyMatrix operator*(double num) const;
	MyMatrix operator*(int num) const;

	friend ostream& operator<<(ostream& out, const MyMatrix& other) {
		if (other._matrix != NULL) {

			for (int i = 0; i < other.getRows(); i++) {
				for (int j = 0; j < other.getCols(); j++) {
					out << other._matrix[i][j];
					

				}
				out << endl;
				

			}
			return out;
		}
		
	}
	

	double*& operator [](const int& index) const
	{	
		if (this->getRows() == 1) {

		}
		return  this->_matrix[index];
	}


	
	friend istream& operator>>(istream& in, MyMatrix& other) ;
	



};
