
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