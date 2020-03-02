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

static list<Mat> planes;
static Mat mImage;
//static Mat mResult;
static Mat myFourier;


Mat myResult;
#if 0
void test_knn()
{
	Mat img = imread("G:\Program Files (x86)\opencv\sources\data/digits.png");
	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY);
	int b = 20;
	int m = gray.rows / b;   //原图为1000*2000
	int n = gray.cols / b;   //裁剪为5000个20*20的小图块
	Mat data,labels;   //特征矩阵
	for (int i = 0; i < n; i++)
	{
		int offsetCol = i*b; //列上的偏移量
		for (int j = 0; j < m; j++)
		{
			int offsetRow = j*b;  //行上的偏移量
			//截取20*20的小块
			Mat tmp;
			gray(Range(offsetRow, offsetRow + b), Range(offsetCol, offsetCol + b)).copyTo(tmp);
			data.push_back(tmp.reshape(0,1));  //序列化后放入特征矩阵
			labels.push_back((int)j / 5);  //对应的标注
		}

	}
	data.convertTo(data, CV_32F); //uchar型转换为cv_32f
	int samplesNum = data.rows;
	int trainNum = 3000;
	Mat trainData, trainLabels;
	trainData = data(Range(0, trainNum), Range::all());   //前3000个样本为训练数据
	trainLabels = labels(Range(0, trainNum), Range::all());

	//使用KNN算法
	int K = 5;
	Ptr<TrainData> tData = TrainData::create(trainData, ROW_SAMPLE, trainLabels);
	Ptr<KNearest> model = KNearest::create();
	model->setDefaultK(K);
	model->setIsClassifier(true);
	model->train(tData);

	//预测分类
	double train_hr = 0, test_hr = 0;
	Mat response;
	// compute prediction error on train and test data
	for (int i = 0; i < samplesNum; i++)
	{
		Mat sample = data.row(i);
		float r = model->predict(sample);   //对所有行进行预测
		//预测结果与原结果相比，相等为1，不等为0
		r = std::abs(r - labels.at<int>(i)) <= FLT_EPSILON ? 1.f : 0.f;          

		if (i < trainNum)
			train_hr += r;  //累积正确数
		else
			test_hr += r;
	}

	test_hr /= samplesNum - trainNum;
	train_hr = trainNum > 0 ? train_hr / trainNum : 1.;

	printf("accuracy: train = %.1f%%, test = %.1f%%\n",
		train_hr*100., test_hr*100.);
	waitKey(0);
	

	::system("pause");
}


void test_getpolar(){


	std::string image_name="model_src_img.jpg";
	cv::Mat image;
	image=cv::imread(image_name,CV_LOAD_IMAGE_COLOR);
	cv::Mat image1=image.clone();
	if(!image.data)
	{
		printf("no image data!\n");
		::system("pause");
	}
	std::vector<cv::Point2f> point_list;
	point_list.push_back(cv::Point2f(680,547));
	point_list.push_back(cv::Point2f(713,495));
	point_list.push_back(cv::Point2f(757,453));
	point_list.push_back(cv::Point2f(873,416));
	point_list.push_back(cv::Point2f(987,448));
	point_list.push_back(cv::Point2f(1069,542));

	cv::RotatedRect rotate_rect=FOpenCV::GetEllipse(point_list);
	cv::Point2f center=rotate_rect.center;
	FOpenCV::DrawEllipse(image,rotate_rect);
	FOpenCV::DrawLine(image,center,cv::Point2f(680,547));
	FOpenCV::DrawLine(image,center,cv::Point2f(1069,542));
	FOpenCV::DrawPoint(image,center);


	cv::Mat polar_image;
	double polar_d1;
	double polar_d2;
	double dis_pointer_start_ellipse;
	double dis_pointer_end_ellipse;
	bool ret=FOpenCV::GetPolar(image1,rotate_rect,cv::Point2f(864,604),2,cv::Point2f(770,439),1,polar_image,polar_d1,polar_d2,dis_pointer_start_ellipse,dis_pointer_end_ellipse);

	cv::imshow("test opencv",image);
	cv::imshow("polar image",polar_image);
	cv::waitKey(-1);
	return 0;

}
#endif






void test_readrawimage(){


	FILE *fp = fopen("1.raw","rb");
	


	unsigned char *buffer=new unsigned char[522240];
	if(fp!=NULL){
		std::cout<<"open success"<<std::endl;
		int ret=fread(buffer, 1, 522240, fp);

		cv::Mat image=cv::Mat(272,640,CV_8UC3);
		memcpy(image.data,buffer,522240);


		cv::imshow("image",image);
		cv::waitKey(-1);

		fclose(fp);
	}
	else{

		std::cout<<"open failure"<<std::endl;

	}


	::system("pause");
	
	delete [] buffer;

}

void test_yuv2rgb(){

	cv::Mat yuvimg;
	FILE *fp = fopen("1.yuv","rb");
	unsigned char *buffer=new unsigned char[1920*1080*3/2];
	int ret=fread(buffer, 1, 1920*1080*3/2, fp);
	yuvimg.create(1080 * 3/2, 1920, CV_8UC1);
	memcpy(yuvimg.data, buffer, 1920*1080*3/2);

	cv::Mat rgbimg=cv::Mat(1080,1920,CV_8UC3);
	cv::cvtColor(yuvimg, rgbimg, CV_YUV2BGR_I420);
	delete [] buffer;
	buffer=NULL;
	fclose(fp);
	fp=NULL;
	cv::imshow("image",rgbimg);
	cv::waitKey(-1);
}


void test_jpg2bbggrr(int argc,char **argv){
	printf("usage:jpg2bbggrr x.jpg x.bgr width height\n");
	if(argc<5){
		printf("too few parameters \n");
		return;
	}
	printf("argv:%s,%s,%s,%s,%s\n",argv[0],argv[1],argv[2],argv[3],argv[5]);

	const char *filename = argv[1];
	const char *outname = argv[2];
	int width=atoi(argv[3]);
	int height=atoi(argv[4]);
	printf("size:%d,%d\n",width,height);
	if(width<0){
		printf("width error\n");
		return;
	}

	if(height<0){
		printf("height error\n");
		return;
	}

	cv::Mat img = cv::imread(filename);
	if (!img.data)
	{
		printf("read image error\n");
		return;
	}

	//缩放
	cv::resize(img, img, cv::Size(width, height));  //224x224
	

	unsigned char *data = (unsigned char*)img.data;
	int step = img.step;
	printf("step: %d, height: %d, width: %d\n",step, img.rows, img.cols);


	FILE *fp = fopen(outname, "wb");
	if(fp!=NULL){

		int h = img.rows;
		int w = img.cols;
		int c = img.channels();

		for (int k = 0; k<c; k++) {
			for (int i = 0; i<h; i++) {
				for (int j = 0; j<w; j++) {
					fwrite(&data[i*step + j*c + k], sizeof(unsigned char), 1, fp);
				}
			}
		}
		fclose(fp);
		fp=NULL;

	}
	else{
		printf("file open error\n");
	}
}

void Mydft()
{
	//Mat mImage = imread("G:/GitHub/HWaterMark/src/test_opencv/test_opencv/Debug/hdJPG.jpg", 0);
	mImage = imread("G:/GitHub/HWaterMark/src/test_opencv/test_opencv/Debug/hdJPG.jpg", 0);
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

	//傅里叶变换
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
	//destroyAllWindows();
	
}

void transformImageWithText(Mat image, 
	String watermarkText, 
	Point point, 
	double fontSize, 
	Scalar scalar)
{
	int myfontface = 1;
	// optimize the dimension of the loaded image
	//Mat padded = this.optimizeImageDim(image);
	//Mat padded = mImage;
	//padded.convertTo(padded, CV_32F);
	//dft(mImage, mImage);
	putText(myResult, watermarkText,point, myfontface, fontSize,scalar,2);
	flip(myResult, myResult, -1);
	putText(myResult, watermarkText, point, myfontface, fontSize, scalar, 2);
	flip(myResult, myResult, -1);

	namedWindow("DFT", WINDOW_NORMAL);
	imshow("DFT", myResult);
	waitKey();
	//destroyAllWindows();
}

void idft()
{
	Mat image;
	dft(myFourier, image, DFT_INVERSE + DFT_REAL_OUTPUT + DFT_SCALE);

	//裁剪傅里叶逆变换
	image = image(Rect(0, 0, mImage.cols, mImage.rows));
	image.convertTo(image, CV_8UC1);

	namedWindow("逆变换图", WINDOW_AUTOSIZE);
	imshow("逆变换图", image);
	waitKey();
	
}

int main(int argc,char **argv)
{
	cv::Point mypoint;
	mypoint.x = 200;
	mypoint.y = 200;

	Scalar myscalar;
	myscalar = (150, 150, 150);

	Mydft();

	

	transformImageWithText(myResult, "watermark",mypoint, FONT_HERSHEY_DUPLEX,myscalar);

	idft();
	//antitransformImage();
	destroyAllWindows();

	//test_detectface();
	//test_readrawimage();
	//test_yuv2rgb();
//	test_jpg2bbggrr(argc,argv);

	system("pause");
	return 0;


}


