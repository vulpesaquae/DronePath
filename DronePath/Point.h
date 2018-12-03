#pragma once
#include <iostream>

class Point
{
private:
    double m_latitude;
    double m_longitude;
    std::string m_name;
public:
    Point(double latitude, double longitude, std::string name = "");

    void Set(double latitude, double longitude, std::string name = "");

    double Latitude();
    double Longitude();
    std::string Name();
};