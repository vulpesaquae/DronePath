#pragma once

#include "Point.h"
#include <math.h>
#include <cstdio>

class DistanceCalculator {
private:
	static DistanceCalculator* m_pTheInstance;
	DistanceCalculator() { } // inhibit instantiation from outside the class
	DistanceCalculator(const DistanceCalculator&); // inhibit instantiation by copy constructor
	DistanceCalculator& operator= (const DistanceCalculator&) {}; // inhibit instantiation by assignment operator
	~DistanceCalculator() { }

	class CGuard
	{
	public:
		~CGuard()
		{
			if (DistanceCalculator::m_pTheInstance != nullptr)
			{
				delete DistanceCalculator::m_pTheInstance;
				DistanceCalculator::m_pTheInstance = nullptr;
			}
		}
	};

	double GetRadians(double Degree);

public:
	static DistanceCalculator* getInstance() {
		static CGuard g;   // garbage collection
		if (m_pTheInstance == nullptr)
			m_pTheInstance = new DistanceCalculator();
		return m_pTheInstance;
	}

	double Distance(const Point &from, const Point &to);
};