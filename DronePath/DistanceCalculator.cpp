#define _USE_MATH_DEFINES
#include "DistanceCalculator.h"


DistanceCalculator* DistanceCalculator::m_pTheInstance = nullptr;

double DistanceCalculator::GetRadians(double degree)
{
	return degree * (M_PI / 180.0);
}

double DistanceCalculator::Distance(const Point &from, const Point &to)
{
	double lat1 = GetRadians((from.GetLatitude() + to.GetLatitude()) / 2);
	double dx = 111.3 * cos(lat1) * (from.GetLongitude() - to.GetLongitude());
	double dy = 111.3 * (from.GetLatitude() - to.GetLatitude());

	return sqrt(dx * dx + dy * dy);
}