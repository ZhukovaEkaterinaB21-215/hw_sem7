#pragma once

int N(Point p0, Point p1, Point p2, Point p3);
Point B_spline(Point p0, Point p1, Point p2, Point p3, double t);
void Curve(Mat& image, vector <Point>& vertex, string color);
