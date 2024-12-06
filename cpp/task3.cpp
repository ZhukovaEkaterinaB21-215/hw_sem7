#include "task3.h"

void MinMaxLoc(Mat& image, double& minVal, double& maxVal)
{
    minVal = 255;
    maxVal = 0;

    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            uchar pixelValue = image.at<uchar>(y, x);
            if (pixelValue < minVal)
            {
                minVal = pixelValue;
            }
            if (pixelValue > maxVal)
            {
                maxVal = pixelValue;
            }
        }
    }
}

void automaticContrast(Mat& image, Mat& newImage, double minVal, double maxVal)
{
    if (image.type() != CV_8U)
    {
        cout << "Error: Input image must be 8-bit" << endl;
        return;
    }

    newImage = Mat::zeros(image.size(), image.type());
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            newImage.at<uchar>(y, x) = saturate_cast<uchar>((image.at<uchar>(y, x) - minVal) * 255.0 / (maxVal - minVal));
        }
    }
}

void sigmoidBrightness(Mat& image, Mat& newImage)
{
    double value = 255;
    if (image.type() != CV_8U)
    {
        cout << "Error: Input image must be 8-bit" << endl;
        return;
    }

    newImage = Mat::zeros(image.size(), image.type());
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {

            double sigmoidValue = pow(image.at<uchar>(y, x)/value, 2) * value/ (pow(image.at<uchar>(y, x) / value, 2) + pow(1 - image.at<uchar>(y, x) / value, 2));
            newImage.at<uchar>(y, x) = static_cast<uchar>(sigmoidValue);
        }
    }
}