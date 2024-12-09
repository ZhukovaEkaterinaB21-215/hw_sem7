#include "pixel.h"
#include "draw_line.h"
#include "task2.h"

int N(Point p0, Point p1, Point p2, Point p3)
{
    double dist1 = abs(p0.x - 2 * p1.x + p2.x) + abs(p0.y - 2 * p1.y + p2.y);
    double dist2 = abs(p1.x - 2 * p2.x + p3.x) + abs(p1.y - 2 * p2.y + p3.y);
    double H = max(dist1, dist2);
    int n = 1 + static_cast<int>(ceil(sqrt(3 * H)));
    return n;
}

Point B_spline(Point p0, Point p1, Point p2, Point p3, double t)
{
    Point p = pow(1 - t, 3) * p0 / 6 + (3 * pow(t, 3) - 6 * pow(t, 2) + 4) * p1 / 6 + (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) * p2 / 6 + pow(t, 3) * p3 / 6;
    return p;
}

void Curve(Mat& image, vector <Point>& vertex, string color)
{ 
    if (vertex.size() < 4)
    {
        cout << "Not enough points to plot a B - spline curve" << endl;
        return;

    }
    Point start = vertex[0];
    Point end = vertex[vertex.size()-1];
    vertex.insert(vertex.begin(), start);
    vertex.insert(vertex.begin(), start);
    vertex.push_back(end);
    vertex.push_back(end);

    string color_point = "#C0C0C0";

    for (int i = 0; i < vertex.size() - 1; i++)
    {
        drawLine(image, vertex[i], vertex[i + 1], color_point);
    }

    
    for (int j = 0; j < vertex.size() - 3; j++)
    {
        int n = N(vertex[j], vertex[j + 1], vertex[j + 2], vertex[j + 3]);

        for (int i = 1; i <= n; i++)
        {
            drawLine(image, B_spline(vertex[j], vertex[j + 1], vertex[j + 2], vertex[j + 3], static_cast<double>(i - 1) / n), B_spline(vertex[j], vertex[j + 1], vertex[j + 2], vertex[j + 3], static_cast<double>(i) / n), color);
        }   
    }
    
}


