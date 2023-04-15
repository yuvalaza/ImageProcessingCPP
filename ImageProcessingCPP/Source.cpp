
#include "Image.h"
using namespace std;

void main() 
{
	//Some Examples:

	try {
		/*Image imag("Image2.png");
		imag.display();
		imag.showHist();
		Image imag_con = imag.ContrastStretch();
		imag_con.showHist();
		imag_con.display();*/
		
		//Image imag3(imag.getGmat().getRows(), imag.getGmat().getCols());

		//Image imag2 = imag.median(3);

		/*Image imag2 = imag.corners(3);
		imag2.display();
		imag2.save();*/

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

	}

