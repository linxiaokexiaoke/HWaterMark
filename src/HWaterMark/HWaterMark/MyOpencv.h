#pragma once

#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <string>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <list>

using namespace std;
using namespace cv;
#define ROW_SAMPLE (100)


class MyOpencv
{
public:
	MyOpencv();
	~MyOpencv();

public:
	void Mydft(Mat &mImage);
	void transformImageWithText(Mat image,
		String watermarkText,
		Point point,
		double fontSize,
		Scalar scalar);
	void idft();

public:
	Mat myFourier;
	Mat myResult;
	Mat mymImage;
};

