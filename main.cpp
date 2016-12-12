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

using namespace std;
using namespace cv;

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

	Mat histH;

	calcHist(&H, 1, 0, Mat(), histH, 1, &histSize, &histRange, uniform, accumulate);


	system("Pause");

	return 0;
}

