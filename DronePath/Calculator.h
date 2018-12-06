#pragma once

#include "Point.h"
#include <math.h>
#include <cstdio>

class Calculator {
private:
    static Calculator* m_pTheInstance;
    Calculator() { } /* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
                                // protected, wenn man von der Klasse noch erben möchte
    Calculator(const Calculator&); /* verhindert, dass eine weitere Instanz via
                                                        Kopie-Konstruktor erstellt werden kann */
    ~Calculator() { }

    double getRadians(double Degree);

    class CGuard
    {
    public:
        ~CGuard()
        {
            if (NULL != Calculator::m_pTheInstance)
            {
                delete Calculator::m_pTheInstance;
                Calculator::m_pTheInstance = NULL;
            }
        }
    };

public:
    static Calculator* getInstance() {
        static CGuard g;   // Speicherbereinigung
        if (!m_pTheInstance)
            m_pTheInstance = new Calculator();
        return m_pTheInstance;
    }

    double Distance(const Point &from, const Point &to);
};