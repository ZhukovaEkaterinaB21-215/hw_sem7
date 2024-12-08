#include "task3.h"

void OneNinetyNinePercentile(Mat& image, double& one_percentile, double& ninety_nine_percentile)
{
    
    vector<int> points(256, 0);
    for (int y = 0; y < image.rows; y++) 
    {
        for (int x = 0; x < image.cols; x++) 
        {
                points[int(image.at<uchar>(y, x))]++;
        }
    }
    int number_pixels = image.rows * image.cols;

    int i = 0;
    double persent_one = points[0];
    while (persent_one/number_pixels < 0.01 && i < 255)
    {
        i = i + 1;
        persent_one = persent_one + points[i];
        cout << i << "-" << persent_one << endl;
    }
    one_percentile = i;

    int j = 0;
    double persent_ninety_nine = points[0];
    while (persent_ninety_nine / number_pixels < 0.99 && j < 255)
    {
        j = j + 1;
        persent_ninety_nine = persent_ninety_nine + points[i];
    }
    ninety_nine_percentile = j;
}


void sigmoidBrightnessAndAutomaticContrast(Mat& image, Mat& newImage, double one_percentile, double ninety_nine_percentile)
{
    if (image.type() != CV_8U)
    {
        cout << "Error: Input image must be 8-bit" << endl;
        return;
    }
    double value = 255;
    newImage = Mat::zeros(image.size(), image.type());
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            double sigmoidValue = pow(saturate_cast<uchar>((image.at<uchar>(y, x) - one_percentile) * 255.0 / (ninety_nine_percentile - one_percentile)) /value, 2) * value/ (pow(saturate_cast<uchar>((image.at<uchar>(y, x) - one_percentile) * 255.0 / (ninety_nine_percentile - one_percentile)) / value, 2) + pow(1 - saturate_cast<uchar>((image.at<uchar>(y, x) - one_percentile) * 255.0 / (ninety_nine_percentile - one_percentile)) / value, 2));
            newImage.at<uchar>(y, x) = static_cast<uchar>(sigmoidValue);
        }
    }
}