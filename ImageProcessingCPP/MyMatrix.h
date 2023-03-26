#pragma once
#include "ErrorObject.h"
#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>

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
	MyMatrix(int n,int m);
	MyMatrix();
	~MyMatrix();
	MyMatrix(const MyMatrix& other);
	void setMatrix(int n = 3, int m = 3);
	int getRows()const { return this->_n; }
	int getCols()const { return this->_m; }
	double max()const;
	double min()const;
	MyMatrix mul(const MyMatrix& other)const;
	MyMatrix T()const;
	MyMatrix abs()const;
	void sort();


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
