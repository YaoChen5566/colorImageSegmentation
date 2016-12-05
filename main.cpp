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

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/undirected_graph.hpp>

using namespace std;
using namespace cv;
using namespace boost;

//void undirectedGraph();

int main()
{
	clock_t start = clock(); // compare start
	Mat input = imread("man.jpg");

	vector<Mat> channels;
	split(input, channels);

	Mat B = channels[0];
	Mat G = channels[1];
	Mat R = channels[2];

	cout <<"width: "<<input.cols<<", height: "<<input.rows<<endl;;
	//vector< vector<int> > edgeMatrix(input.cols*input.rows, vector<int>(input.cols*input.rows)); //edgeMatrix[2][1]
	
	Mat edgeMatrixMat = Mat::zeros(input.cols*input.rows, input.cols*input.rows, CV_32FC1);
	
	//for(int i = 0 ; i < input.cols*input.rows ; i++)
	//	for(int j = 0 ; j < input.cols*input.rows ; j++)
	//		edgeMatrix[i][j] = 0;
	//	

	for(int i = 1 ; i < input.cols-1 ; i++)
	{
		for(int j = 1 ; j < input.rows-1 ; j++)
		{
			//x-1
			edgeMatrixMat.at<double>(j*input.cols+i, j*input.cols+i-1) = sqrt(pow(B.at<float>(j, i)-B.at<float>(j, i-1), 2) + pow(G.at<float>(j, i)-G.at<float>(j, i-1), 2) + pow(R.at<float>(j, i)-R.at<float>(j, i-1), 2));
			edgeMatrixMat.at<double>(j*input.cols+i-1, j*input.cols+i) = sqrt(pow(B.at<float>(j, i)-B.at<float>(j, i-1), 2) + pow(G.at<float>(j, i)-G.at<float>(j, i-1), 2) + pow(R.at<float>(j, i)-R.at<float>(j, i-1), 2));
			//x-w
			edgeMatrixMat.at<double>(j*input.cols+i, j*input.cols+i-input.cols) = sqrt(pow(B.at<float>(j-1, i)-B.at<float>(j-1, i), 2)+pow(G.at<float>(j-1, i)-G.at<float>(j-1, i), 2)+pow(R.at<float>(j-1, i)-R.at<float>(j-1, i), 2));
			edgeMatrixMat.at<double>(j*input.cols+i-input.cols, j*input.cols+i) = sqrt(pow(B.at<float>(j-1, i)-B.at<float>(j-1, i), 2)+pow(G.at<float>(j-1, i)-G.at<float>(j-1, i), 2)+pow(R.at<float>(j-1, i)-R.at<float>(j-1, i), 2));
			//x+1
			edgeMatrixMat.at<double>(j*input.cols+i, j*input.cols+i+1) = sqrt(pow(B.at<float>(j, i)-B.at<float>(j, i+1), 2) + pow(G.at<float>(j, i)-G.at<float>(j, i+1), 2) + pow(R.at<float>(j, i)-R.at<float>(j, i+1), 2));
			edgeMatrixMat.at<double>(j*input.cols+i+1, j*input.cols+i) = sqrt(pow(B.at<float>(j, i)-B.at<float>(j, i+1), 2) + pow(G.at<float>(j, i)-G.at<float>(j, i+1), 2) + pow(R.at<float>(j, i)-R.at<float>(j, i+1), 2));
			//x+w
			edgeMatrixMat.at<double>(j*input.cols+i, j*input.cols+i+input.cols) = sqrt(pow(B.at<float>(j+1, i)-B.at<float>(j+1, i), 2)+pow(G.at<float>(j+1, i)-G.at<float>(j+1, i), 2)+pow(R.at<float>(j+1, i)-R.at<float>(j+1, i), 2));
			edgeMatrixMat.at<double>(j*input.cols+i+input.cols, j*input.cols+i) = sqrt(pow(B.at<float>(j+1, i)-B.at<float>(j+1, i), 2)+pow(G.at<float>(j+1, i)-G.at<float>(j+1, i), 2)+pow(R.at<float>(j+1, i)-R.at<float>(j+1, i), 2));
		}
	}

	cout <<"edge done"<<endl;
	
	clock_t finish = clock(); // compare finish

	cout << "time: " << finish-start<<endl;
	//typedef boost::undirected_graph<> Graph;
	//Graph inputGraph;

	//for(int i = 0 ; i < input.cols ; i++)
	//{
	//	for(int j = 0 ; j < input.rows ; j++)
	//	{
	//		inputGraph.add_vertex();
	//	}
	//}

	//for(int i = 0 ; i < input.cols ; i++)
	//{
	//	for(int j = 0 ; j < input.rows ; j++)
	//	{
	//		inputGraph.add_edge(1,2,10);
	//	}
	//}


	
	//undirectedGraph();
	system("Pause");

	return 0;
}

//void undirectedGraph()
//{
//	typedef boost::undirected_graph<> Graph;
//
//	Graph g;
//
//	for(int i = 0 ; i < 10 ; i++)
//	{
//		g.add_vertex();
//	}
//}