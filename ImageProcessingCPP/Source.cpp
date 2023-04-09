
#include "Image.h"
using namespace std;

void main() 
{
	//cout << setGaus(15,2.38) << endl;
	/*Image imag9("image2.png");
	(imag9).display();
	(imag9.gausBlur(15, 5)).display();*/
	//cout << getHaar("DoubleH", 6,0.5) << endl;
	/*Image imag3("image2.png");
	imag3.display();
	imag3.gausBlur(1,7).display();
	*/
	

	try {
		//Image imag3("image2.png");
		//Image imagC(imag3.sift());
		//imagC.display();
		/*MyMatrix mat3 = setSobel(3);
		cout << mat3 << endl;
		*/
		//MyMatrix mat3(3, 3,rep);
		//cin >> mat3;
		//Image imag4(conv(imag3.getGmat(), mat3));
		//Image imag6(imag3.gausBlur(15,2.5));
		//imag6.display();
		//Image imag4 = imag3.edgeDetect("sobelX", 3);
		//imag4.display();
		//imag4.display();
		//Image imag7(imag3.corners(3));
		//Image imag9(imag3.edgeDetect("sobelM"));
		//imag9.display();
		//imag9.save();

		Image imag("image2.png");
		//Image imag3(imag.getGmat().getRows(), imag.getGmat().getCols());
		//Image imag2 = imag.median(3);
		//Image imag2 = imag.corners(5);
		/*Image imagX = imag.edgeDetect("sobelX");
		imagX.display();
		imagX.save();
		
		Image imagY = imag.edgeDetect("sobelY");
		imagY.display();
		imagY.save();

		Image imagM = imag.edgeDetect("sobelM");
		imagM.display();
		imagM.save();
		*/
		/*Image imagL = imag.edgeDetect("laplac");
		imagL.display();
		imagL.save();*/

		/*Image image_med = imag.median();
		image_med.display();
		image_med.save();*/
		
		/*Image image_cont = imag.ContrastStretch();
		image_cont.display();
		image_cont.save();*/
		
		
		//imag3 = imag.equalize();

		//imag.showHist();
		//imag2.showHist();
		//imag3.showHist();

		
		//imag2.display();
		//imag3.display();
	}
	
	catch (ErrorObject& e) {
		e.printError();

	}


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

