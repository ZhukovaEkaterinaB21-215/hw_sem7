#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void MinMaxLoc(Mat& image, double& minVal, double& maxVal);
void automaticContrast(Mat& image, Mat& newImage, double minVal, double maxVal);
void sigmoidBrightness(Mat& image, Mat& newImage);