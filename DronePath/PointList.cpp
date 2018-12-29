#include "PointList.h"
#include "DistanceCalculator.h"

#include <algorithm>

PointList::PointList() {

}

PointList::PointList(PointList& orig) {
	*this = orig;
}

PointList& PointList::operator=(PointList& orig) {
	std::for_each(orig.points.begin(), orig.points.end(), [this](Point* p) { this->Add(*p); });
	return *this;
}

PointList::~PointList() {
	for (Point* p : points) {
		delete p;
		p = nullptr;
	}
	points.clear();
}

void PointList::Add(Point &arg) {
	Point* pCopy = new Point(arg);
	points.push_back(pCopy);
}

double PointList::GetDistance() {
	if (points.size() < 2)
		return NAN;

	double distance = 0.0;

	for (int i = 0; i < points.size() - 1; ++i) {
		distance += DistanceCalculator::getInstance()->Distance(*points.at(i), *points.at(i + 1));
	}

	return distance;
}

void PointList::Print() {
	std::cout << "PointList - containing " << points.size() << " Point(s):" << std::endl;
	for (Point* p : points) {
		p->Print();
	}
}