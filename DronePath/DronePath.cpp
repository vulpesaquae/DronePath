#include <iostream>
#include "Point.h"
#include "PointList.h"

int main() {
	// example from exam
	PointList* pWayPoints = new PointList();
	Point* points[] = {
		new Point(48.803242, 9.221968, std::string("707372 Stuttgart, Kreuzenacher Strasse 47")),
		new Point(48.811465, 9.229727, std::string("707374 Stuttgart, Gnesener Strasse 69")),
		new Point(48.801934, 9.235032, std::string("707372 Stuttgart, Ruhrstrasse 50")),
		new Point(48.803242, 9.221968, std::string("707372 Stuttgart, Kreuzenacher Strasse 47"))
	};
	for (Point* p : points) {
		pWayPoints->Add(*p);
	}

	std::cout << "Distance: " << pWayPoints->GetDistance() << std::endl;
	std::cout << "Expected: " << "3.17608" << std::endl << std::endl;


	// Point::Set
	Point* pNamed = new Point(48, 9);
	pNamed->Set(40.1, 9.1);
	Point* pUnnamed = new Point(48, 9, "HI");
	pUnnamed->Set(40.2, 9.2);

	// PointList::operator=
	PointList* pAssigned = new PointList();
	*pAssigned = *pWayPoints;
	pAssigned->Add(*pNamed);
	pNamed = nullptr;

	// PointList CopyConstructor
	PointList* pConstructed = new PointList(*pWayPoints);
	pConstructed->Add(*pUnnamed);
	pUnnamed = nullptr;

	// Comparison
	pWayPoints->Print();   // 4 Points
	pAssigned->Print();    // 4 Points plus HI
	pConstructed->Print(); // 4 Points plus HO


	// cleanup
	pWayPoints->~PointList();
	pWayPoints = nullptr;
	pAssigned->~PointList();
	pAssigned = nullptr;
	pConstructed->~PointList();
	pConstructed = nullptr;


	return 0;
}