#pragma once
#include<iostream>
#include<string>
using namespace std;


#define INVALID_SIZE "For Add/Sub the matrices has to be in the same Size "
#define INVALID_SIZE_NUM 1
#define INVALID_MUL " For matrix multiplication, Matrix A has to be m x n and matrix and B has to be n x p matrix"
#define INVALID_MUL_NUM 2
#define INVALID_INMUL " For elementWise multiplication, both matrices have to be with the same size"
#define INVALID_INMUL_NUM 3



#define LINK1 "www.stackoverflow.com"
#define LINK2 "www.myerrors.com"


class ErrorObject
{
private:
	string _errorDesc;
	int _errorNumber;
	string _errorLink;
public:
	ErrorObject(int en = 0, string ed = "generic error", string el = "www.stackoverflow.com") :_errorNumber(en), _errorDesc(ed), _errorLink(el) {}
	void printError() const {
		cout << "********************* ERROR DETAILS **************************" << endl;
		cout << "Error number : " << this->_errorNumber << endl;
		cout << "Error description : " << this->_errorDesc << endl;
		cout << "More details at : " << this->_errorLink << endl;
		cout << "************************* ERROR **************************" << endl;
	}

};

