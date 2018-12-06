#include "PointList.h"
#include "Calculator.h"

#include <algorithm>

PointList::PointList()
{

}

PointList::PointList(PointList& orig) {
    for (int i = 0; i < orig.points.size(); i++)
    {
        points.push_back(new Point(orig.points.at(i)->getLatitude(), orig.points.at(i)->getLongitude(), orig.points.at(i)->getName()));
    }
}

void PointList::add(Point &arg) {
    // Erstelle flache Kopie von 'arg' und füge sie in 'pointList' ein,
    // damit die Lebenszeit des Objekts unabhängig ist.
    auto* pNewPoint = new Point(arg);
    points.push_back(pNewPoint);
}

double PointList::getDistance() {
    double distance = 0.0;

    for (int i = 0; i < points.size() - 1; ++i) {
        distance += Calculator::getInstance()->Distance(*points.at(i), *points.at(i + 1));
    }

    return distance;
}

void PointList::print() {
    // Print every point in pointList using the print() method of class Point
    std::cout << "PointList (" << points.size() << " Points):" << std::endl;
    for (auto &i : points) {
        i->Print();
    }
}

PointList& PointList::operator=(PointList& orig)
{
    std::for_each(orig.points.begin(), orig.points.end(), [this](Point* p) { (*this).add(*p); });
    return *this;
}
