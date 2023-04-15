#include "Image.h"


Image::Image(const string path) {
	Mat  load_image = imread(path,IMREAD_GRAYSCALE);
	if (!load_image.data)
	{
		throw ErrorObject(LOAD_FAILED_NUM, LOAD_FAILED, LINK1);

	}
	Mat new_image;
	load_image.convertTo(new_image, CV_64F);
	MyMatrix gray(new_image.rows, new_image.cols);
	for (int i = 0; i < new_image.rows; i++) {

		for (int j = 0; j < new_image.cols; j++) {
			gray[i][j] = new_image.at<double>(i, j);

		}
	}
	this->_gmat = gray;
	this->_histogram=this->calHist();
	this->setPath(path);
}
Image:: Image(int rows, int cols, string path) {
	this->setGmat(rows, cols);
	this->setPath(path);
	this->setHist();
}
Image ::Image(const MyMatrix& other, string path) {
	this->setGmat(other);
	this->setPath(path);
	
}

void Image::setGmat(int rows,int cols) {
	this->_gmat.setMatrix(rows, cols);
}
void Image::setGmat(const MyMatrix& other) {
	this->_gmat = other;
	//this->calHist();
}
void Image:: set_out_Path(string type,string input) {
	int pos = input.find('.');
	this->setPath(input.substr(0, pos) +"-"+type+ "." + input.substr(pos + 1));

}
void Image::setHist() {
	if (this->_path == "None") {
		this->_histogram.setMatrix(1, 256);
	}
	this->_histogram = this->calHist();
}

MyMatrix Image::calHist() const{

MyMatrix res_hist(1, 256);
int temp;
for (int i = 0; i < this->_gmat.getRows(); i++) {
	for (int j = 0; j < this->_gmat.getCols(); j++) {
		temp = int(this->_gmat[i][j]);
		res_hist[0][temp] += 1;
	}
}
return res_hist;
}

void Image::display()const {
	Mat new_image(this->_gmat.getRows(), this->_gmat.getCols(), CV_64F);
	String windowName;
	for (int i = 0; i < this->_gmat.getRows(); i++) {
		for (int j = 0; j < this->_gmat.getCols(); j++)
		{
			new_image.at<double>(i, j) = this->_gmat[i][j];
		}

	}
	new_image.convertTo(new_image, CV_8U);

	windowName = this->_path;
	namedWindow(windowName);
	imshow(windowName, new_image);
	waitKey(0);
	destroyWindow(windowName);
}
void Image::save()const {
	Mat new_image=this->getGmat().getCV_mat();
	new_image.convertTo(new_image, CV_32F);
	String windowName= this->_path;;
	namedWindow(windowName);
	if (this->getPath() != "None") {
		imwrite(this->getPath(), new_image);
	}
	else {
		imwrite(this->getPath() + ".png", new_image);
	}
	
	waitKey(0);//wait till user press any key
	destroyWindow(windowName);//close the window and release allocate memory//
	cout << "Image is saved successfully" << endl;

}
void Image::showHist()const {
	double normalize_factor = 100;
	int cols = this->_histogram.getCols();
	String windowName;
	float temp;
	MyMatrix temp_hist = this->_histogram;
	//normalize for better display
	temp_hist.minMax();
	vector<double>hist(256);
	for (int i = 0; i < cols; i++) {
		hist[i] = temp_hist[0][i];
	}

	Mat3b image;
	drawHist(hist, image);
	imshow("Histogram", image);
	waitKey(0);
	destroyWindow(windowName);
}
void Image::drawHist(const vector<double>& data, Mat3b& dst, int binSize, int height)const
{
	int max_value = *max_element(data.begin(), data.end());
	int rows = 0;
	int cols = 0;
	if (height == 0) {
		rows = max_value + 10;
	}
	else {
		rows = max(max_value + 10, height);
	}

	cols = data.size() * binSize;

	dst = Mat3b(rows, cols, Vec3b(0, 0, 0));

	for (int i = 0; i < data.size(); ++i)
	{
		int h = rows - data[i];
		rectangle(dst, Point(i * binSize, h), Point((i + 1) * binSize - 1, rows), (i % 2) ? Scalar(0, 100, 255) : Scalar(0, 0, 255), cv::FILLED);
	}

}

int Image::getHistPercentile(const int p)const {
	double num_of_pix = this->_gmat.getRows() * this->_gmat.getCols();
	double sum = 0;
	double percentile = (double(p) / 100) * (num_of_pix);
	for (int i = 0; i < this->_histogram.getCols(); i++) {
		if (sum > percentile) {
			return i;
		}
		sum += this->_histogram[0][i];
	}
}

Image Image::ContrastStretch()const {
	int rows = this->getGmat().getRows();
	int cols = this->getGmat().getCols();
	Image contrast(rows, cols);
	int max = this->getHistPercentile(95);
	int min = this->getHistPercentile(5);
	int low = 0;
	int high = 255;
	double factor = double(high - low) / double(max - min);
	cout << max << endl;
	cout << min << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			contrast._gmat[i][j] = (((this->_gmat[i][j]) - min) * (factor)) + low;
			if (contrast._gmat[i][j] > 255) {
				contrast._gmat[i][j] = 255;
			}
			if (contrast._gmat[i][j] <=0) {
				contrast._gmat[i][j] = 0;
			}
		}
		
	}
	contrast._histogram = contrast.calHist();
	contrast.set_out_Path("Constrast_Stretch",this->getPath());
	return contrast;

}

Image Image::equalize()const {
	int rows = this->getGmat().getRows();
	int cols = this->getGmat().getCols();
	int max = (this->getHist().getCols()) - 1;
	Image equal(rows, cols);
	MyMatrix pdf = (this->getHist()) * (1 / double(rows * cols));
	MyMatrix cdf(1, cols);
	cdf[0][0] = pdf[0][0];
	for (int i = 1; i < cols; i++) {
		cdf[0][i] = cdf[0][i - 1] + pdf[0][i];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			equal._gmat[i][j] = (cdf[0][int(this->_gmat[i][j])] )* max;
		}
	}
	cout << (cdf[0][int(this->_gmat[0][408])]) << endl;
	cout << equal._gmat[0][408] << endl;
	equal._histogram = equal.calHist();
	equal.set_out_Path("Equalize", this->getPath());
	return equal;


}

Image Image::median(const int size)const {
	int factor = size / 2;
	int median,pos;
	int index = 0;
	int rows = this->getGmat().getRows();
	int cols = this->getGmat().getCols();
	Image med(rows, cols);
	int arrSize = pow(size, 2);
	MyMatrix temp(1,arrSize);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			for (int k = i - factor; k <= i + factor; k++) {
				if (k >= 0 && k<rows)
				{
					for (int m = j - factor; m <= j + factor; m++) {
						if (m >= 0 && m<cols)
						{
							temp[0][index] = this->_gmat[k][m];
							index++;
						}

					}
				}
				
			}
			index = 0;
			//cout << temp << endl;
			temp.sort();
			//cout << temp << endl;
			if (size % 2 == 0) {
				median = (temp[0][arrSize / 2] + temp[0][(arrSize / 2) + 1]) / 2;
				
			}
			else {
				median = temp[0][(arrSize - 1) / 2];
				//cout << median << endl;
			}
			med._gmat[i][j] = median;

		}
		
	}
	med.set_out_Path("Median_filter", this->getPath());
	return med;
}

Image Image:: gausBlur(const int size, double const sigma)const {
	MyMatrix kernel = setGaus(size,sigma);
	Image res(conv(this->getGmat(), kernel));
	return res;

}


Image Image::edgeDetect(const string& type, int size, double sigma)const {
	//for set the new image path
	if (size != 3 && size != 5) {
		throw ErrorObject(INVALID_MASK_SIZE_NUM, INVALID_MASK_SIZE, LINK1);
	}
	if (type == "sobelM") {
		Image resM(SobelMag(this->getGmat(), size));
		resM.set_out_Path("sobelM", this->getPath());
		return resM;

	}
	if (type == "canny") {
		Image resC(SobelMag(conv(this->getGmat(),setGaus(size, sigma)),size));
		resC.set_out_Path("canny", this->getPath());
		return resC;

	}
	MyMatrix mask = initMask(type,size);
	Image res(conv(this->getGmat(), mask));
	res.set_out_Path(type, this->getPath());
	return res;
}

Image Image::corners(int size, double threshold_value) {
	double a=0,b=0 ,c=0 ,lamda1=0 ,lamda2=0,R = 0,mean=0;
	int rows = this->getRows();
	int cols = this->getCols();
	Image res(rows, cols);
	Image blur = this->gausBlur(5,0.79);
	MyMatrix dx(conv(blur.getGmat(),setSobel("sobelX")));
	MyMatrix dy(conv(blur.getGmat(), setSobel("sobelY")));
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = i-(size/2); k <= i+(size / 2); k++) {
				if (k >= 0 && k < rows) {

					for (int m = j - (size / 2); m <= j + (size / 2); m++) {
						if (m >= 0 && m<cols) {
							a += pow(dx[k][m], 2);
							b += (dx[k][m]) * (dy[k][m]);
							c += pow(dy[k][m], 2);
						}
					}
				}
			}
			b = b * 2;
			lamda1 = (0.5) * (a + c + sqrt(pow(b, 2) + pow(a - c, 2)));
			lamda2 = (0.5) * (a + c - sqrt(pow(b, 2) + pow(a - c, 2)));
			R = lamda1 * lamda2 - ((0.05) * pow(lamda1 + lamda2, 2));
			//res._gmat[i][j] = R;
			if (R >threshold_value) {
				res._gmat[i][j] = 255;
			}
			else {
				res._gmat[i][j] = 0;
			}
			//cout << R << endl;
			lamda1 = 0;
			lamda2 = 0;
			a = 0;
			b = 0;
			c = 0;
			}
		
		}
	res.set_out_Path("Corners", this->getPath());
	return res;
	}
Image Image:: sift(double s, int gausSize, double sigma,int setSize,int window_Size) {
	int count = 0;
	int rows = this->getGmat().getRows();
	int cols = this->getGmat().getCols();
	MyMatrix temp(rows, cols);
	Image res(this->getRows(), this->getCols());
	MyMatrix* gauSet = new MyMatrix[setSize];
	initGausSet(this->getGmat(),gauSet, s, gausSize, sigma, setSize);
	//postSet is the set of the Difference of Gaussians -(DoG), which equal to Normalized Laplacian of Gaussian-(NLoG)
	MyMatrix* postSet = new MyMatrix[setSize/2];
	MyMatrix* maxSet = new MyMatrix[setSize / 2];
	for (int i = 0; i < (setSize / 2); i++) {
		postSet[i] = gauSet[count + 1] - gauSet[count];
		maxSet[i] = postSet[i].localMax(window_Size);
		count += 2;
	}
	//for test
	res = this->drawCirc(maxSet,setSize/2,2,sigma*20);
	//free memory allocation
	delete[]gauSet;
	delete[]postSet;
	delete[]maxSet;
	return res;
}

Image Image::drawCirc(MyMatrix* maxSet,int setSize, int thickness, double radius,int factor)const {
	double threshold = 0;
	int rows = this->getRows();
	int cols = this->getCols();
	MyMatrix temp(rows, cols);
	Mat res = this->getGmat().getCV_mat();
	Image final_image(rows, cols);
	int count = 1;
	double new_radius = 0;
	Scalar color = Scalar(0);
	res.convertTo(res, CV_8U);
	
	for (int k = 0; k < setSize; k++) {
		temp = maxSet[k];
		threshold = (temp.max())*0.7;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				//cout << temp[i][j] << endl;
				if (temp[i][j]>=threshold) {
					Point center(i, j);
					new_radius = pow(factor, count) * radius;
					circle(res, center, new_radius, color, 1);
				
				}
				
			}
		}
		count =count+ 2;
	}
	//res.convertTo(res, CV_8U);
	
	namedWindow(this->_path);
	imshow(this->_path, res);
	waitKey(0);
	destroyWindow(this->_path);
	
	//MyMatrix final(res);
	//final_image._gmat = final;

	return final_image;
}
