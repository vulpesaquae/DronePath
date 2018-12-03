#include "Point.h"

Point::Point(double latitude, double longitude, std::string name)
{
    m_latitude = latitude;
    m_longitude = longitude;
    m_name = name;
}

void Point::Set(double latitude, double longitude, std::string name)
{
    m_latitude = latitude;
    m_longitude = longitude;
    if (!name.compare(""))
    {
        m_name = name;
    }
}

double Point::Latitude()
{
    return m_latitude;
}

double Point::Longitude()
{
    return m_longitude;
}

std::string Point::Name()
{
    return m_name;
}
