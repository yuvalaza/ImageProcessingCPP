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
MyMatrix::MyMatrix(const Mat& other) {
	int rows = other.rows;
	int cols = other.cols;
	this->_matrix = new double* [rows];
	for (int i = 0; i < rows; i++) {
		this->_matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			this->_matrix[i][j] = other.at<double>(i, j);
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
		for (int j = 0;j<transpose_mat.getCols(); j++)
		{
			transpose_mat[i][j] = this->_matrix[j][i];
		}

	}
	return transpose_mat;
}
double MyMatrix ::max()const {
	int rows = this->getRows();
	int cols = this->getCols();
	double max = this->_matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (this->_matrix[i][j] > max)
			{
				max = this->_matrix[i][j];
			}
		}
	}
	return max;


}
double MyMatrix::min()const {
	int rows = this->getRows();
	int cols = this->getCols();
	double min = this->_matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (this->_matrix[i][j] < min)
			{
				min = this->_matrix[i][j];
			}
		}
	}
	return min;
}
MyMatrix MyMatrix:: localMax(int window_Size)const {
	if (window_Size > this->getRows() || window_Size > this->getCols()) {
		throw ErrorObject(INVALID_WINDOW_SIZE_NUM, INVALID_WINDOW_SIZE, LINK1);
	}
	//saving the max location
	int pointX = 0, pointY = 0;
	double max = 0;
	double global_max = 0;
	int rows = this->getRows();
	int cols = this->getCols();
	MyMatrix res(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i + window_Size <= rows) {
				for (int m = i; m < i + window_Size; m++) {
					if (j + window_Size <= cols) {
						for (int k = j; k < j + window_Size; k++) {
							if (this->_matrix[m][k] > max) {
								max = this->_matrix[m][k];
								pointX = m;
								pointY = k;
							}
							if (max > global_max) {
								global_max = max;
							}
						}
					}
				}
				
				
			}
			if (max != 0) {
				res[pointX][pointY] = max;
				//In order to deal with the overlap and get the real local max
				clean_localMax(res, max, window_Size, i, j,rows,cols);
				max = 0;
			}
		}
	}
	cout << global_max << endl;
	return res;
}
void MyMatrix:: clean_localMax(MyMatrix& res, double max, int window_Size, int indexX, int indexY,int rows,int cols)const {
	if (indexX + window_Size <= rows && indexY + window_Size <= cols) {
		for (int n = indexX; n < indexX + window_Size; n++) {

			for (int t = indexY; t < indexY + window_Size; t++) {
				if (res[n][t] < max && res[n][t] != 0) {
					res[n][t] = 0;
				}
			}
		}
	}
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

void MyMatrix::sort() {
	for (int i = 0; i < this->getRows(); i++) {
		mergeSort(this->_matrix[i],0,(this->getCols()-1));
	}

}
void MyMatrix:: mergeSort(double* arr,int first, int last) {
	if (first >= last) {
		return;
	}
	int mid = first + ((last - first) / 2);
	mergeSort(arr, first, mid);
	mergeSort(arr, mid + 1, last);
	merge(arr, first, mid, last);
}
void MyMatrix::merge(double* arr, int const left, int const mid, int const right) {
	
	double* larr = new double[mid - left + 1];
	double* rarr = new double[right - mid];
	int larr_index = 0;
	int rarr_index = 0;
	int marr_index = left;

	for (int i = 0; i < mid - left + 1; i++) {
		larr[i] = arr[left+i];
	}
	for (int i = 0; i <right-mid; i++) {
		rarr[i] = arr[mid + i+1];
	}
	while ((larr_index < mid - left + 1) && (rarr_index < right - mid)) {
		if (larr[larr_index] <= rarr[rarr_index]) {
			arr[marr_index] = larr[larr_index];
			larr_index++;
		}
		else {
			arr[marr_index] = rarr[rarr_index];
			rarr_index++;
		}
		marr_index++;
	}
	
	while (larr_index < mid-left+1) {
		arr[marr_index] = larr[larr_index];
		marr_index++;
		larr_index++;
	}
	while (rarr_index < right-mid) {
		arr[marr_index] = rarr[rarr_index];
		marr_index++;
		rarr_index++;
	}
	delete[]larr;
	delete[]rarr;
}
MyMatrix MyMatrix::abs()const {
	int rows = this->getRows();
	int cols = this->getCols();
	MyMatrix res(*this);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (res[i][j] < 0) {
				res[i][j] = (-1) * res[i][j];
			}
		}
	}
	return res;

}
MyMatrix MyMatrix::integ()const {
	int rows = this->getRows();
	int cols = this->getCols();
	MyMatrix res(*this);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i > 0 && j > 0) {
				res[i][j] = res[i][j] + res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
			}
			else {
				if (i > 0) {
					res[i][j] = res[i][j] + res[i - 1][j];
				}
				else {
					if (j == 0) {
						res[i][j] = res[i][j];
					}
					else {
						res[i][j] = res[i][j] + res[i][j - 1];
					}
				}
			}
		}
	}
	return res;

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
 void MyMatrix::cvNorm() {
	int rows = this->getRows();
	int cols = this->getCols();
	Mat new_image(rows, cols, CV_64F);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
			{
				new_image.at<double>(i, j) = this->_matrix[i][j];
			}

		}
		new_image.convertTo(new_image, CV_8U);
		new_image.convertTo(new_image, CV_64F);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
			{
				this->_matrix[i][j] = new_image.at<double>(i, j);
			}

	}
 }
 Mat MyMatrix::getCV_mat() {
	 int rows = this->getRows();
	 int cols = this->getCols();
	 Mat new_mat(rows, cols, CV_64F);
	 for (int i = 0; i < rows; i++) {
		 for (int j = 0; j < cols; j++)
		 {
			 new_mat.at<double>(i, j) = this->_matrix[i][j];
		 }

	 }
	 return new_mat;
 }
 
	
 