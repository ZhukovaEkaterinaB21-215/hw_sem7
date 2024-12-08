#include "pixel.h"
#include "draw_line.h"
#include "draw_polygon.h"
#include "task2.h"
#include "task3.h"
#include "task1.h"


int main()
{
    // task 1
    /*
    vector<Point> vertexS_first = { Point(100, 300), Point(100, 100), Point(400, 100), Point(400, 300) };
    vector<Point> vertexC_first = { Point(200, 50), Point(300, 50), Point(300, 400), Point(200, 400) };

    vector <Point> result_first = WeilerAthertonModification(vertexS_first, vertexC_first);
    Mat img_task1_1(512, 512, CV_8UC3, Scalar(255, 255, 255));
    string color_main = "#0000FF";
    string color_basic = "#000000";
    drawPolygon(img_task1_1, vertexS_first, color_basic);
    drawPolygon(img_task1_1, vertexC_first, color_basic);
    drawPolygon(img_task1_1, result_first, color_main);
    imwrite("task1_1.png", img_task1_1);

    vector<Point> vertexS_second = { Point(50, 240), Point(450, 300), Point(100, 420) };
    vector<Point> vertexC_second = { Point(200, 113), Point(300, 113), Point(420, 389), Point(256, 499), Point(150, 350) };

    vector <Point> result_second = WeilerAthertonModification(vertexS_second, vertexC_second);
    Mat img_task1_2(512, 512, CV_8UC3, Scalar(255, 255, 255));

    drawPolygon(img_task1_2, vertexS_second, color_basic);
    drawPolygon(img_task1_2, vertexC_second, color_basic);
    drawPolygon(img_task1_2, result_second, color_main);
    imwrite("task1_2.png", img_task1_2);
    */
    //task2
    /*
    Mat img_task2_6(512, 512, CV_8UC3, Scalar(255, 255, 255));
    vector<Point> vertex_Bsplain_6 = { Point(133, 420), Point(420, 56)};
    string color_task2 = "#1E90FF";

    Curve(img_task2_6, vertex_Bsplain_6, color_task2);
    imwrite("two_point_new.png", img_task2_6);

    Mat img_task2_7(512, 512, CV_8UC3, Scalar(255, 255, 255));
    vector<Point> vertex_Bsplain_7 = {Point(372, 294)};

    Curve(img_task2_7, vertex_Bsplain_7, color_task2);
    imwrite("one_point_new.png", img_task2_7);
    */
    //task3
    
    Mat image = imread("iagoda.png", IMREAD_GRAYSCALE);

    double one_percentile, ninety_nine_percentile;
    OneNinetyNinePercentile(image, one_percentile, ninety_nine_percentile);
    Mat newImage;
    sigmoidBrightnessAndAutomaticContrast(image, newImage, one_percentile, ninety_nine_percentile);
    imwrite("new_iagoda.png", newImage);
    
    waitKey(0);
    return 0;
}