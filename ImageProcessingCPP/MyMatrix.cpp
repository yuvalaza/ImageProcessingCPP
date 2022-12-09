#include "MyMatrix.h"
void MyMatrix::setMatrix(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->_matrix = new double* [this->getRows()];
	for (int i = 0; i < this->getRows(); i++)
	{
		this->_matrix[i] = new double[this->getCols()];
		for (int j = 0; j < this->getCols(); j++)
		{
			this->_matrix[i][j] = 0;
		}

	}
}

//default cons initialize 3x3 with 0
MyMatrix::MyMatrix()
{
	this->setMatrix();
	
}
MyMatrix::~MyMatrix()
{
	if (this->_matrix != NULL) {
		for (int i = 0; i < this->getRows(); i++)
		{
			delete[]this->_matrix[i];
		}
		delete[]this->_matrix;
	}

}
 //Copy constructor
MyMatrix::MyMatrix(const MyMatrix& other) {
	this->_n = other.getRows();
	this->_m =other.getCols();
	this->_matrix = new double* [this->getRows()];
	for (int i = 0; i < this->getRows(); i++)
	{
		this->_matrix[i] = new double[this->getCols()];
		for (int j = 0; j < this->getCols(); j++)
		{
			this->_matrix[i][j] = other._matrix[i][j];
		}

	}
}
//Construct mXn matrix
MyMatrix::MyMatrix(int n,int m) {
	this->setMatrix(n, m);

}
MyMatrix MyMatrix::T()const {
	MyMatrix transpose_mat(this->getCols(), this->getRows());
	for (int i = 0; i < transpose_mat.getRows(); i++)
	{
		for (int j = 0;  transpose_mat.getCols(); j++)
		{
			transpose_mat[i][j] = this->_matrix[j][i];
		}

	}
	return transpose_mat;
}

MyMatrix MyMatrix::mul(const MyMatrix& other)const {
	if (this->getCols() != other.getRows()) {
		throw ErrorObject(INVALID_MUL_NUM, INVALID_MUL, LINK1);
	}
	double res = 0;
	MyMatrix new_mat(this->getRows(), other.getCols());
	for (int i = 0; i < this->getRows(); i++)
	{

		for (int j = 0; j < other.getCols(); j++)
		{
			for (int k = 0; k < other.getRows(); k++)
			{

				res += this->_matrix[i][k] * other._matrix[k][j];

			}
			new_mat[i][j] = res;
			res = 0;
		}

	}
	return new_mat;
	
}







MyMatrix& MyMatrix::operator=(const MyMatrix& other) {
	if (this->_matrix != NULL) {
		for (int i = 0; i < this->getRows(); i++)
		{
			delete[]this->_matrix[i];
		}
		delete[]this->_matrix;
		this->_n = other.getRows();
		this->_m = other.getCols();
		this->_matrix = new double* [this->getRows()];
		for (int i = 0; i < this->getRows(); i++)
		{
			this->_matrix[i] = new double[this->getCols()];
			for (int j = 0; j < this->getCols(); j++)
			{
				this->_matrix[i][j] = other._matrix[i][j];
			}

		}
	}
	return *this;
}

bool MyMatrix:: operator==(const MyMatrix& other) const {
	if (this->getRows() == other.getRows() && this->getCols() == other.getCols())
	{
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < this->getCols(); j++)
			{
				if (this->_matrix[i][j] != other._matrix[i][j]) {
					return false;
				}
				
			}

		}
		return true;
	}
	return false;

}
istream& operator>>(istream& in, MyMatrix& other){
	int rows;
	int cols;
	cout << "Enter number of rows:" << endl;
	in >> rows;
	cout << "Enter number of cols:" << endl;
	in >> cols;
	MyMatrix temp(rows, cols);
	for (int i = 0; i <rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Enter the element at: [" << i << "," << j << "]" << endl;
			in >> temp._matrix[i][j];
		}
		cout << endl;
	}
	other = temp;
	return in;
}

MyMatrix MyMatrix:: operator+(const MyMatrix& other) const {
	double res = 0;
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
		throw ErrorObject(INVALID_SIZE_NUM, INVALID_SIZE, LINK1);
	}
	MyMatrix new_mat(this->getRows(), this->getCols());
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			res = this->_matrix[i][j] + other._matrix[i][j];
			new_mat[i][j] = res;

		}

	}
	return new_mat;
}

MyMatrix MyMatrix:: operator-(const MyMatrix& other) const {
	double res = 0;
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
		throw ErrorObject(INVALID_SIZE_NUM, INVALID_SIZE, LINK1);
	}
	MyMatrix new_mat(this->getRows(), this->getCols());
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			res = this->_matrix[i][j] - other._matrix[i][j];
			new_mat[i][j] = res;

		}

	}
	return new_mat;

	}

 MyMatrix:: operator double() const {
	 double sum = 0;
	 for (int i = 0; i < this->getRows(); i++)
	 {
		 for (int j = 0; j < this->getCols(); j++)
		 {
			 sum += this->_matrix[i][j];

		 }

	 }
	 return sum;
}
 MyMatrix MyMatrix:: operator*(const MyMatrix& other) const {
	 if (this->getCols() != other.getCols() || this->getRows() != other.getRows()) {
		 throw ErrorObject(INVALID_MUL_NUM, INVALID_INMUL, LINK1);
	 }
	 MyMatrix result(this->getRows(), this->getCols());
	 for (int i = 0; i < this->getRows(); i++)
	 {
		 for (int j = 0; j < this->getCols(); j++)
		 {
			 result[i][j] = this->_matrix[i][j] * other._matrix[i][j];
		 }

	 }
	 return result;
	
}
 

	 

 
 MyMatrix MyMatrix:: operator*(double num) const {
	 double res = 0;
	 MyMatrix new_mat(this->getRows(), this->getCols());
	 for (int i = 0; i < this->getRows(); i++)
	 {
		 for (int j = 0; j < this->getCols(); j++)
		 {
			 res = this->_matrix[i][j]*num;
			 new_mat[i][j] = res;

		 }

	 }
	 return new_mat;
 }
 MyMatrix MyMatrix:: operator*(int num) const {
	 double res = 0;
	 MyMatrix new_mat(this->getRows(), this->getCols());
	 for (int i = 0; i < this->getRows(); i++)
	 {
		 for (int j = 0; j < this->getCols(); j++)
		 {
			 res = this->_matrix[i][j] * num;
			 new_mat[i][j] = res;

		 }

	 }
	 return new_mat;
 }