#include <math.h>

class Point{
  public:
    friend class PointFactory;
    double GetX() {return _x;}
    double GetY() {return _y;}
  private:
    double _x, _y;
    
    Point(double x, double y): _x(x), _y(y) {}
};

class PointFactory{
  public:
    static Point NewPolar(double r, double theta) {
        return Point(r * cos(theta), r * sin(theta));
    }

    static Point newCartesian(double x, double y) {
        return Point(x, y);
    }
};