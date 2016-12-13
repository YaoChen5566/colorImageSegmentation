#include <opencv\cv.h>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <errno.h>
#include <random>

using namespace std;
using namespace cv;


int N;
Mat histH = Mat::zeros(181, 1, CV_32FC1);

int factorial(int a);


double r(int a, int b);
double p(int a, int b, int L);
double B(int n, int k, double p);
double H(int a, int b);

int main()
{
	clock_t start = clock(); // compare start
	Mat input = imread("duck.jpg");

	Mat inputHSV;

	cvtColor(input, inputHSV, CV_BGR2HSV);

	vector<Mat> channels;
	split(inputHSV, channels);


	
	Mat H = channels[0];
	Mat S = channels[1];
	Mat V = channels[2];

	int histSize = 181;

	float range[] = {0, 181};
	const float* histRange = {range};

	bool uniform = true;
	bool accumulate = false;

	
	calcHist(&H, 1, 0, Mat(), histH, 1, &histSize, &histRange, uniform, accumulate);

	N = sum(histH)[0];
	cout << N;
	//cout << r(3, 4, histH);
	//cout << p(1, 10, 180);
	cout << factorial(3);
	system("Pause");

	return 0;
}

double r(int a, int b)
{
	int p = 0;
	
	for(int i = a ; i <= b ; i++)
		p += histH.at<float>(i+1, 0);

	return p/sum(histH)[0];
}

double p(int a, int b, int L)
{
	return double((b-a+1))/double(L);
}

double B(int n, int k, double p)
{
	double result = 0;

	for(int j = k ;j <= n ; j++)
		result += double(factorial(n)/(factorial(j)*factorial(n-j)) * pow(p, j) * pow(1-p, n-j));
	
	return result;
}

//double H(int a, int b)
//{
//
//}

int factorial(int a)
{
	int result = 1;
	for(int i = 1 ; i <= a ; i++)
		result *= i;

	return result;
}