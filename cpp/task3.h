#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void OneNinetyNinePercentile(Mat& image, double& one_percentile, double& ninety_nine_percentile);
void sigmoidBrightnessAndAutomaticContrast(Mat& image, Mat& newImage, double one_percentile, double ninety_nine_percentile);