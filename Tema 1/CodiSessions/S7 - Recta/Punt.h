#ifndef PUNT_H
#define PUNT_H

#include <iostream>
using namespace std;

class Punt
{
    public:
		Punt() {}
		~Punt() {}
        Punt(float x, float y): m_x(x), m_y(y) {}
		Punt(const Punt& pt) { m_x = pt.m_x; m_y = pt.m_y; }
        float getX() const { return m_x; }
        void setX(const float x) { m_x = x; }
        float getY() const { return m_y; }
        void setY(const float y) { m_y = y; }
    private:
        float m_x;
        float m_y;
};

#endif // PUNT_H
