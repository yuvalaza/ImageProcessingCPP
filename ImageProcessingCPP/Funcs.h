
#include "MyMatrix.h"

MyMatrix setGaus(int size = 3,double sigma = 0.5);
MyMatrix conv (const MyMatrix& matA, const MyMatrix& matB);
MyMatrix initMask(string type,int size=3);
MyMatrix setSobel(string type, int size = 3);
MyMatrix Sobel3();
MyMatrix Sobel5();
MyMatrix SobelMag(MyMatrix input,int size=3);
MyMatrix setLaplac(int size = 3);
MyMatrix laplac3();
MyMatrix laplac5();
MyMatrix getHaar(string type, int width, double W_L_ratio=2);
static MyMatrix setVertHaar(int width, int length);
static MyMatrix setHorizHaar(int width, int length);
static MyMatrix setDiagHaar(int width, int length);
static MyMatrix setDoubHoizHaar(int width, int length);
static MyMatrix setDoubVertHaar(int width, int length);
MyMatrix calcHaar(const MyMatrix& input, string type, int width, double W_L_ratio = 2);
//Initializing a set of Gaussian kernels with sigma=sigma*(s^i) as i is the index of a specific kernel in the set
void initGausSet(const MyMatrix& input,MyMatrix*& set, double s = 1.2, int gausSize = 15, double sigma = 1, int setSize = 10);
