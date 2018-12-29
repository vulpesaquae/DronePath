#include "Point.h"
#include <iostream>
#include <utility>

Point::Point(double latitude, double longitude, std::string name)
	: m_latitude(latitude),
	m_longitude(longitude),
	m_name(std::move(name))
{
}

void Point::Set(double latitude, double longitude, std::string name)
{
	if (!name.empty())
	{
		m_name = name;
	}
	m_latitude = latitude;
	m_longitude = longitude;
}

double Point::GetLatitude() const
{
	return m_latitude;
}

double Point::GetLongitude() const
{
	return m_longitude;
}

std::string Point::GetName() const
{
	return m_name;
}

void Point::Print()
{
	std::cout << "Lat: " << m_latitude << " | Long: " << m_longitude << " | " << m_name << std::endl;
}