#pragma once

#include <string>

class Point {
private:
	double m_latitude;
	double m_longitude;
	std::string m_name;

public:
	Point(double latitude, double longitude, std::string name = "N/A");

	void Set(double latitude, double longitude, std::string name = std::string());

	double GetLatitude() const;
	double GetLongitude() const;
	std::string GetName() const;

	void Print();
};