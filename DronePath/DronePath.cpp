#include <iostream>
#include "Point.h"
#include "PointList.h"

int main() {
    PointList* pWayPoints = new PointList();

    pWayPoints->add(*(new Point(48.803242, 9.221968, std::string("707372 Stuttgart, Kreuzenacher Strasse 47"))));
    pWayPoints->add(*(new Point(48.811465, 9.229727, std::string("707374 Stuttgart, Gnesener Strasse 69"))));
    pWayPoints->add(*(new Point(48.801934, 9.235032, std::string("707372 Stuttgart, Ruhrstrasse 50"))));
    pWayPoints->add(*(new Point(48.803242, 9.221968, std::string("707372 Stuttgart, Kreuzenacher Strasse 47"))));

    std::cout << "Distance: " << pWayPoints->getDistance() << std::endl;

    PointList* pWayMorePoints = new PointList();
    *pWayMorePoints = *pWayPoints;
    pWayPoints->add(*(new Point(48, 9)));
    std::cout << "Distance: " << pWayPoints->getDistance() << std::endl;
    std::cout << "Distance: " << pWayMorePoints->getDistance() << std::endl;

    return 0;
}