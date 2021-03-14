#ifndef PUNT_H
#define PUNT_H

#include <iostream>
using namespace std;

class Punt
{
    public:
        float getX() const { return m_x; }
        void setX(const float x) { m_x = x; }
        float getY() const { return m_y; }
        void setY(const float y) { m_y = y; }
        void llegeix();
        void mostra();
        float distancia(Punt& p);
    private:
        float m_x;
        float m_y;
};

#endif // PUNT_H
