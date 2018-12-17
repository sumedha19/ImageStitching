/*
 * Source.cpp
 *
 *  Created on: 18-Dec-2018
 *      Author: sumedha
 */

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Stitcher::Mode mode = Stitcher::PANORAMA;

int main(int argc, char **argv) {
	// Read input images
	Mat src1 = imread("Photos/1.jpg");
	Mat src2 = imread("Photos/2.jpg");
	// Array of images
	vector<Mat> img;

	img.push_back(src1);
	img.push_back(src2);

	// To store final stitched image
	Mat output;

	// Create a Stitcher class object with mode panoroma
	    Ptr<Stitcher> stitcher = Stitcher::create(mode, false);

	//	Command to stitch all the images present in the image array
	Stitcher::Status status = stitcher->stitch(img, output);

	if (status != Stitcher::OK)
	{
		// Check if images could not be stiched
		// status is OK if images are stiched successfully
		cout << "Can't stitch images\n";
		return -1;
	}

	// Store a new image stiched from the given
	//set of images as "result.jpg"
	imwrite("result.jpg", output);

	// Show the result
	imshow("Result", output);

	waitKey(0);

	return 0;
}


