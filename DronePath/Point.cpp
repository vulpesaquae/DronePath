#include "Point.h"
#include <iostream>
#include <utility>

Point::Point(double latitude, double longitude, std::string name)
    : m_latitude(latitude),
    m_longitude(longitude),
    m_name(std::move(name))
{
}

Point::Point(double latitude, double longitude)
    : m_latitude(latitude),
    m_longitude(longitude),
    m_name("unnamed")
{
}

double Point::getLatitude() const
{
    return m_latitude;
}

double Point::getLongitude() const
{
    return m_longitude;
}

std::string Point::getName() const
{
    return m_name;
}

void Point::Print()
{
    std::cout << m_name << " | Lat: " << m_latitude << " | Long: " << m_longitude << std::endl;
}

void Point::set(double latitude, double longitude, std::string name = "")
{
    if (name != "")
    {
        m_name = name;
    }
    m_latitude = latitude;
    m_longitude = longitude;
}