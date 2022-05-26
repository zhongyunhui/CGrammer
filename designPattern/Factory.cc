#include <iostream>

#include "Factory.h"

using namespace std;



int main() {
    Point carte = PointFactory::newCartesian(3.0, 5.1);
    Point polar = PointFactory::NewPolar(10, 1.67);
    cout << "carte x:" << carte.GetX() << " y:" << carte.GetY() << endl;
    cout << "polar x:" << polar.GetX() << " y:" << polar.GetY() << endl;
    return 0;
}