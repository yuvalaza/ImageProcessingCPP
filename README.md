# ImageProcessingCPP
# Introduction
Welcome to my CPP project, which focuses on implementing various image processing algorithms from scratch such as filtering, edge detection, corner detection, SIFT detector, relevant mathematical functions and more. In addition I implemented my own matrix class that include many arithmetic and mathematical functions as well as suitable operators.

## :ledger: Table Of Content

- [About](#beginner-about)
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
At this project I implemented every algorithm from scratch, In order to do that I built the “MyMatrix” class. By providing a flexible and efficient matrix data structure, the class simplifies the process of implementing complex algorithms that require matrix operations.
Here is a summary of the methods provided by the MyMatrix class:

| Property   | Description                                       |
| ---------- | ------------------------------------------------- |
| `_matrix`  | A pointer to a 2D array of `double` values that represents the matrix data. |
| `_n`       | An integer that represents the number of rows in the matrix. |
| `_m`       | An integer that represents the number of columns in the matrix. |


| Method                            | Description                                                                     |
| --------------------------------- | -----------------------------------------------------------------------------   |
| `MyMatrix()`                      | Default constructor. Initializes an zero values 3x3 matrix.                      |
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


## :zap: Usage
Write about how to use this project.

###  :electric_plug: Installation
- Steps on how to install this project, to use it.
- Be very detailed here, For example, if you have tools which run on different operating systems, write installation steps for all of them.

```
$ git clone https://github.com/yuvalaza/ImageProcessingCPP.git
```

###  :package: Commands
- Commands to start the project.
- 
### Theory And Algorithm's Description
-Few examples

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
