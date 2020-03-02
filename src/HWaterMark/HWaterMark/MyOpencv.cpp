#include "MyOpencv.h"



MyOpencv::MyOpencv()
{
	myFourier = Mat::Mat();
}


MyOpencv::~MyOpencv()
{
}


static list<Mat> planes;
//static Mat mImage;
//static Mat mResult;
//static Mat myFourier;


//Mat myResult;



void MyOpencv::Mydft(Mat &mImage)
{
	//Mat mImage = imread("G:/GitHub/HWaterMark/src/test_opencv/test_opencv/Debug/hdJPG.jpg", 0);
	mImage = imread("G:/GitHub/HWaterMark/src/test_opencv/test_opencv/Debug/hdJPG.jpg", 0);
	mymImage = mImage;
	if (mImage.data == 0)
	{
		cout << "Image reading error" << endl;
		system("pause");
		return;
	}
	namedWindow("The original image", WINDOW_NORMAL);
	imshow("The original image", mImage);

	//Extending image
	int m = getOptimalDFTSize(mImage.rows);
	int n = getOptimalDFTSize(mImage.cols);
	copyMakeBorder(mImage, mImage, 0, m - mImage.rows, 0, n - mImage.cols, BORDER_CONSTANT, Scalar(0));

	//Fourier transform
	Mat mFourier(mImage.rows + m, mImage.cols + n, CV_32FC2, Scalar(0, 0));

	Mat mForFourier[] = { Mat_<float>(mImage), Mat::zeros(mImage.size(), CV_32F) };
	Mat mSrc;
	merge(mForFourier, 2, mSrc);

	//∏µ¿Ô“∂±‰ªª
	dft(mSrc, mFourier);
	myFourier = mFourier.clone();
	//channels[0] is the real part of Fourier transform,channels[1] is the imaginary part of Fourier transform 
	vector<Mat> channels;
	split(mFourier, channels);
	Mat mRe = channels[0];
	Mat mIm = channels[1];

	//Calculate the amplitude
	Mat mAmplitude;
	magnitude(mRe, mIm, mAmplitude);

	//Logarithmic scale
	mAmplitude += Scalar(1);
	log(mAmplitude, mAmplitude);

	//The normalized
	normalize(mAmplitude, mAmplitude, 0, 255, NORM_MINMAX);

	Mat mResult(mImage.rows, mImage.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < mImage.rows; i++)
	{
		uchar* pResult = mResult.ptr<uchar>(i);
		float* pAmplitude = mAmplitude.ptr<float>(i);
		for (int j = 0; j < mImage.cols; j++)
		{
			pResult[j] = (uchar)pAmplitude[j];
		}
	}

	Mat mQuadrant1 = mResult(Rect(mResult.cols / 2, 0, mResult.cols / 2, mResult.rows / 2));
	Mat mQuadrant2 = mResult(Rect(0, 0, mResult.cols / 2, mResult.rows / 2));
	Mat mQuadrant3 = mResult(Rect(0, mResult.rows / 2, mResult.cols / 2, mResult.rows / 2));
	Mat mQuadrant4 = mResult(Rect(mResult.cols / 2, mResult.rows / 2, mResult.cols / 2, mResult.rows / 2));

	Mat mChange1 = mQuadrant1.clone();
	//mQuadrant1 = mQuadrant3.clone();
	//mQuadrant3 = mChange1.clone();
	mQuadrant3.copyTo(mQuadrant1);
	mChange1.copyTo(mQuadrant3);

	Mat mChange2 = mQuadrant2.clone();
	//mQuadrant2 = mQuadrant4.clone();
	//mQuadrant4 = mChange2.clone();
	mQuadrant4.copyTo(mQuadrant2);
	mChange2.copyTo(mQuadrant4);

	namedWindow("The Fourier transform", WINDOW_NORMAL);
	imshow("The Fourier transform", mResult);
	myResult = mResult;
	waitKey();
	destroyAllWindows();

}

void MyOpencv::transformImageWithText(Mat image,
	String watermarkText,
	Point point,
	double fontSize,
	Scalar scalar)
{
	/*
	cv::Point mypoint;
	mypoint.x = 200;
	mypoint.y = 200;

	Scalar myscalar;
	myscalar = (150, 150, 150);
	*/

	int myfontface = 1;
	// optimize the dimension of the loaded image
	//Mat padded = this.optimizeImageDim(image);
	//Mat padded = mImage;
	//padded.convertTo(padded, CV_32F);
	//dft(mImage, mImage);
	putText(myResult, watermarkText, point, myfontface, fontSize, scalar, 2);
	flip(myResult, myResult, -1);
	putText(myResult, watermarkText, point, myfontface, fontSize, scalar, 2);
	flip(myResult, myResult, -1);

	namedWindow("DFT", WINDOW_NORMAL);
	imshow("DFT", myResult);
	waitKey();
	destroyAllWindows();
}

void MyOpencv::idft()
{
	Mat image;
	dft(myFourier, image, DFT_INVERSE + DFT_REAL_OUTPUT + DFT_SCALE);

	//≤√ºÙ∏µ¿Ô“∂ƒÊ±‰ªª
	image = image(Rect(0, 0, mymImage.cols, mymImage.rows));
	image.convertTo(image, CV_8UC1);

	namedWindow("ƒÊ±‰ªªÕº", WINDOW_NORMAL);//WINDOW_NORMAL  WINDOW_AUTOSIZE
	imshow("ƒÊ±‰ªªÕº", image);
	waitKey();
	destroyAllWindows();
}