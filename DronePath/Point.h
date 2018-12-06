#pragma once

#include <string>

class Point {
private:
    double m_latitude;
    double m_longitude;
    std::string m_name;

public:
    Point(double latitude, double longitude, std::string name);
    Point(double latitude, double longitude);

    void set(double latitude, double longitude, std::string name);

    double getLatitude() const;
    double getLongitude() const;
    std::string getName() const;

    void Print();
};