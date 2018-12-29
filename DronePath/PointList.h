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
	~PointList();

	void Add(Point& arg);

	double GetDistance();

	void Print();

	PointList& operator=(PointList& orig);
};