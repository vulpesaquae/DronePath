#pragma once

#include <iostream>
#include <vector>
#include "Point.h"

class PointList {
private:
    std::vector<Point*> points;

public:
    PointList();
    PointList(PointList& orig);

    void add(Point& arg);

    double getDistance();

    void print();

    PointList& operator=(PointList& orig);
};