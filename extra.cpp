#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "structs.h"

using namespace std;

struct Point2D
{
    float x;
    float y;
};

static bool comparePoints(const Point2D& a, const Point2D& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

static float cross(const Point2D& o, const Point2D& a, const Point2D& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double convexHullPerimeter(Dictionary& dictionary)
{
    if (dictionary.words.size() < 3) {
        cout << "\nNeed at least 3 words to calculate convex hull perimeter." << endl;
        return 0.0;
    }

    vector<Point2D> points;
    for (list<Word>::iterator it = dictionary.words.begin(); it != dictionary.words.end(); ++it) {
        Point2D p;
        p.x = it->coordinates.x;
        p.y = it->coordinates.y;
        points.push_back(p);
    }

    sort(points.begin(), points.end(), comparePoints);

    if (points.size() < 2) return 0.0;

    vector<Point2D> hull;

    for (size_t i = 0; i < points.size(); i++) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    size_t lowerSize = hull.size();
    for (int i = (int)points.size() - 2; i >= 0; i--) {
        while (hull.size() > lowerSize && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();

    if (hull.size() < 3) {
        cout << "\nAll points are collinear, no convex hull." << endl;
        return 0.0;
    }

    double perimeter = 0.0;
    for (size_t i = 0; i < hull.size(); i++) {
        size_t j = (i + 1) % hull.size();
        double dx = hull[i].x - hull[j].x;
        double dy = hull[i].y - hull[j].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }

    cout << "\n=== CONVEX HULL PERIMETER ===" << endl;
    cout << "Points on hull:" << endl;
    for (size_t i = 0; i < hull.size(); i++) {
        cout << "  (" << hull[i].x << ", " << hull[i].y << ")" << endl;
    }
    cout << "Perimeter: " << perimeter << endl;

    return perimeter;
}
