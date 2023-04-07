# ImageProcessingCPP
# Introduction
Welcome to my CPP project, which focuses on implementing various image processing algorithms from scratch such as filtering, edge detection, corner detection, SIFT detector, relevant mathematical functions and more. In addition I implemented my own matrix class that include many arithmetic and mathematical functions as well as suitable operators.






## :ledger: Table Of Content

- [About](#beginner-about)
    - [MyMatrix class overview]()
    - [Image class overview]()
- [Usage](#zap-usage)
  - [Installation](#electric_plug-installation)
  - [Commands](#package-commands)
  - [Theory And Algorithm's Description]()
  - [Examples]()
- [Development](#wrench-development)
  - [Developmen Environment](#nut_and_bolt-development-environment)
  - [File Structure](#file_folder-file-structure)
- [FAQ](#question-faq)
- [Resources](#page_facing_up-resources)
- [Credit/Acknowledgment](#star2-creditacknowledgment)
- [License](#lock-license)

##  :beginner: About
###  MyMatrix class overview
At this project I implemented every algorithm from scratch, In order to do that I built the “MyMatrix” class. By providing a flexible and efficient matrix data structure, the class simplifies the process of implementing complex algorithms that require matrix operations.
Here is a summary of the methods provided by the MyMatrix class:

| Property   | Description                                       |
| ---------- | ------------------------------------------------- |
| `_matrix`  | A pointer to a 2D array of `double` values that represents the matrix data. |
| `_n`       | An integer that represents the number of rows in the matrix. |
| `_m`       | An integer that represents the number of columns in the matrix. |


| Method                            | Description                                                                     |
| --------------------------------- | -----------------------------------------------------------------------------   |
| `MyMatrix()`                      | Default constructor. Initializes zeros values 3x3 matrix.                      |
| `MyMatrix(int n, int m)`          | Constructs a zero values matrix of size `n x m`.                                            |
| `MyMatrix(const MyMatrix& other)` | Copy constructor. Creates a new matrix that is a copy of `other`.               |
| `MyMatrix(const Mat& other)`      | Creates a new matrix that is a copy of the given `cv::Mat` object.              |
| `~MyMatrix()`                     | Destructor. Deletes dynamically allocated memory.                               |
| `setMatrix(int n = 3, int m = 3)` | Sets zero values matrix of size `n x m` . Default is 3x3.                                    |
| `getRows() const`                 | Returns the number of rows in the matrix.                                       |
| `getCols() const`                 | Returns the number of columns in the matrix.                                    |
| `max() const`                     | Returns the maximum value in the matrix.                                        |
| `min() const`                     | Returns the minimum value in the matrix.                                        |
| `mul(const MyMatrix& other) const`| Returns the matrix product of `this` and `other`.                               |
| `T() const`                       | Returns the transpose of the matrix.                                            |
| `abs() const`                     | Returns a new matrix with the absolute values of each element.                  |
| `integ() const`                   | Returns a new matrix where each element is the cumulative sum of the elements above and to the left of it. |
| `localMax(int window_Size = 3) const` | Returns a new matrix with local maxima in every window by the window size.                |
| `clean_localMax(MyMatrix& res,double max, int window_Size,int indexX, int indexY, int rows, int cols) const` | Private helper function to clean local maxima. |
| `sort()`                          | Sorts every row of the matrix in ascending order.                                            |
| `cvNorm()`                        | Normalizes the matrix so that its sum of squares is equal to 1.                |
| `getCV_mat()`                     | Returns the matrix as a `cv::Mat` object.                                       |
| `operator=(const MyMatrix& other)`| Assignment operator. Copies the matrix from `other` to `this`.                 |
| `operator==(const MyMatrix& other) const` | Equality operator. Returns `true` if `this` is equal to `other`.          |
| `operator+(const MyMatrix& other) const` | Addition operator. Returns the sum of `this` and `other`.                |
| `operator-(const MyMatrix& other) const` | Subtraction operator. Returns the difference of `this` and `other`.       |
| `operator double() const`         | Conversion operator. Returns the sum of the matrix as a `double`.  |
| `operator*(const MyMatrix& other) const` | Matrix multiplication operator. Returns the matrix of the element-wise multiplication of `this` and `other`. |
| `operator*(double num) const`    | Scalar multiplication operator. Returns the product of `this` and `num`.     |
| `operator*(int num) const`       | Scalar multiplication operator. Returns the product of `this` and `num`.     |
| `friend ostream& operator<<(ostream& out, const MyMatrix& other)`  | Overloads the `<<` operator  for getting easy output of `MyMatrix` objects. |
| `double*& operator [](const int& index) const`  | Overloads the `[]` operator to allow easy access to elements in a `MyMatrix` object. |
| `friend istream& operator>>(istream& in, MyMatrix& other)` | Overloads the `>>` operator to allow inserting input values to `MyMatrix` objects. |

### Image class overview
 This class can be used to perform various image processing tasks or as a foundation for building more advanced image processing algorithms.

| Property    | Description                                          |
| ----------- | ---------------------------------------------------- |
| `_histogram` | A `MyMatrix` object representing the image histogram. |
| `_path`     | A string representing the path to the image file.    |
| `_gmat`     | A `MyMatrix` object representing the image matrix.   |


| Method                                      | Description                                                       |
| ------------------------------------------- | ----------------------------------------------------------------- |
| `calHist()const`                             | Calculates and returns the histogram of the image                |
| `Image(const string file_name)`              | Constructor that reads an image from a file                       |
| `Image(int rows, int cols,string path="None")` | Constructor that creates an image with specified rows and columns |
| `Image(const MyMatrix& other, string path = "None")` | Constructor that creates an image from a matrix                   |
| `setPath(string path)`                       | Sets the path of the image                                        |
| `setGmat(int rows, int cols)`                | Sets zero values matrix of the image with specified rows and columns      |
| `setGmat(const MyMatrix& other)`             | Sets the matrix of the image from a matrix                         |
| `setHist()`                                  | Calculates and sets the histogram of the image                    |
| `scale()`                                    | Scales the image by MinMax Norm                                       |
| `getRows()const`                             | Returns the number of rows in the image                            |
| `getCols()const`                             | Returns the number of columns in the image                         |
| `getHist()const`                             | Returns the histogram of the image                                 |
| `getGmat()const`                             | Returns the matrix of the image                                    |
| `getPath()const`                             | Returns the path of the image                                      |
| `display()const`                             | Displays the image                                                |
| `getHistPercentile(const int p)const`        | Returns the p-th percentile in the histogram                       |
| `showHist()const`                            | Displays the histogram of the image                                |
| `drawHist(const vector<double>& data, Mat3b& dst, int binSize = 3, int height = 0)const` | Draws the histogram of the image |
| `ContrastStretch()const`                     | Applies contrast stretching to the image                            |
| `equalize()const`                            | Applies histogram equalization to the image                         |
| `median(const int size = 3)const`            | Applies median filtering to the image with specified kernel size  |
| `gausBlur(const int size = 3, double const sigma = 0.477)const` | Applies Gaussian blur to the image with specified kernel size and sigma |
| `edgeDetect(const string& type,int size=3,double sigma=0.5)const` | Detects edges in the image using the specified method-SobelX/SobelY/Sobel/Laplac |
| `corners(int size, double threshold_value= 5.1 * (pow(10, 7)))` | Finds corners in the image using the specified method |
| `sift(double s=1.2, int gausSize = 15, double sigma = 1,int setSize=10, int window_Size=100)` | Applies SIFT feature extraction to the image |
| `drawCirc(MyMatrix* maxSet,int setSize,int thickness,double radius, int factor=1.2)const` | Draws circles around the detected features in the image |


## :zap: Usage
This project really easy to use, in the following sections i will describe how to start use it, i will give various examples and some theory explanations.

###  :electric_plug: Installation
-In oreder to use this project you just have to clone it:
```
$ git clone https://github.com/yuvalaza/ImageProcessingCPP.git
```
In addition, in this project I used OpenCV for loading, displaying and saving images.
If you didn’t install OpenCV yet , you can follow this guide:
[OpenCV Installation Guide](https://www.tutorialspoint.com/how-to-install-opencv-for-cplusplus-in-windows)


###  :package: Commands
- Commands to start the project.
- 
### Theory And Algorithm's Description
At this section I will describe few algorithms that I implemented in this project. 
- **2D Convolution**</br>
    The 2D convolution of two discrete functions f(x,y) and g(x,y) is defined as:</br>
        $(f \ast g)[n,m] = \sum\limits_{k=-\infty}^{\infty}\sum\limits_{l=-\infty}^{\infty}f[k,l] \cdot g[n-k,m-l]$</br>
- **Discrete Gradient $\nabla$ Operator**</br>
    Finite difference approximations:</br>
        $\frac{\partial I}{\partial x}\approx\frac{1}{2 \epsilon} \left( (I_{i+1,j+1} - I_{i,j+1}) + (I_{i+1,j} - I_{i,j}) \right)$</br>
        $\frac{\partial I}{\partial y}\approx\frac{1}{2 \epsilon} \left( (I_{i+1,j+1} - I_{i+1,j}) + (I_{i,j+1} - I_{i,j}) \right)$</br>
    This operator can be implemented as Convolution. 
    Over the last few decades  , a variety of gradient operators have been proposed like: Roberts Operator, Pewitt, and the one I used in this project, Sobel.</br></br>
- **Discrete Laplacian $\nabla^2$ Operator:**</br>
    Finite difference approximations:</br>
        $\frac{\partial^2 I}{\partial x^2}\approx\frac{1}{ \epsilon^2} \( (I_{i-1,j} -2 I_{i,j} + I_{i+1,j} )$</br>
        $\frac{\partial^2 I}{\partial y^2}\approx\frac{1}{ \epsilon^2} \( (I_{i,j-1} -2 I_{i,j} + I_{i,j+1} )$</br>
        and we get that:</br>
        $\nabla^2 I\approx\frac{\partial^2 I}{\partial x^2}+\frac{\partial^2 I}{\partial y^2}$</br>
    As well As the Gradient Operator, the Laplacian Operator can be implemented as Convolution .</br></br>



### Examples
-Few examples

##  :wrench: Development
If you want other people to contribute to this project, this is the section, make sure you always add this.

### :notebook: Pre-Requisites
List all the pre-requisites the system needs to develop this project.
- A tool
- B tool

###  :nut_and_bolt: Development Environment
Write about setting up the working environment for your project.
- How to download the project...
- How to install dependencies...


###  :file_folder: File Structure
Add a file structure here with the basic details about files, below is an example.

```
.
├── assets
│   ├── css
│   │   ├── index-ui.css
│   │   └── rate-ui.css
│   ├── images
│   │   ├── icons
│   │   │   ├── shrink-button.png
│   │   │   └── umbrella.png
│   │   ├── logo_144.png
│   │   └── Untitled-1.psd
│   └── javascript
│       ├── index.js
│       └── rate.js
├── CNAME
├── index.html
├── rate.html
└── README.md
```

| No | File Name | Details 
|----|------------|-------|
| 1  | index | Entry point




### :exclamation: Guideline
coding guidelines or other things you want people to follow should follow.


## :question: FAQ
You can optionally add a FAQ section about the project.

##  :page_facing_up: Resources
Add important resources here

## :star2: Credit/Acknowledgment
Credit the authors here.

##  :lock: License
Add a license here, or a link to it.
