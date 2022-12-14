#include "MyMatrix.h"
#include "Image.h"



void main() 
{

	Image imag("image3.jpeg");
	imag.showHist();


	int play = 1;
	int num;
	while (play) {
		MyMatrix res;
			cout << "************************* New Calculation **************************" << endl;
			cout << "Enter matrix A:" << endl;
			MyMatrix matA;
			cin >> matA;
			cout << "Enter matrix B:" << endl;
			MyMatrix matB;
			cin >> matB;
			cout << "Matrix A is:" << endl;
			cout << matA << endl;
			cout << "The sum of Matrix A is:" << endl;
			cout << double(matA) << endl;
			cout << "Matrix B is:" << endl;
			cout << matB << endl;
			cout << "The sum of Matrix B is:" << endl;
			cout << double(matB) << endl;
			cout << "************************* Results **************************" << endl;
			try {
				cout << "Addition result:" << endl;
				res = matA + matB;
				cout << res << endl;
			}
			catch (ErrorObject& e) {
				e.printError();

			}
			try{
				cout << "************************* ******* **************************" << endl;
				cout << "Subtraction result:" << endl;
				res = matA - matB;
				cout << res << endl;
			}
			catch (ErrorObject& e) {
				e.printError();

			}
			try {
				cout << "************************* ******* **************************" << endl;
				cout << "Multiple result:" << endl;
				res = matA * matB;
				cout << res << endl;
				res = matA.mul(matB);
				cout << res << endl;
				cout << "*************************************************************" << endl;
			}
			catch (ErrorObject& e) {
				e.printError();

			}
			cout << "Enter a number :" << endl;
			cin >> num;
			cout << "The result of multiplication matrix A with : " << num << " is: " << endl;
			cout << matA*num << endl;
			cout << "*************************************************************" << endl;
			cout << "For new calculation enter 1, for exit 0:" << endl;
			cin >> play;
		}

		
	}

