#include <iostream>
#include <iomanip>
#include "HelperFunc.h"
#include "Point.h"

using namespace std;

//Point::Point(): x(0), y(0) { cout << "Constructor of points" << endl; };

Point::Point(double _x, double _y): x(_x), y(_y) 
{
    //cout << "Constructor of points " << x << " " << y << endl;
};

Point::Point(const Point &obj) {
    x = obj.x;
    y = obj.y;
	  //cout << "Copy constructor" << endl;
}

void Point::SetPoint() {
	  cout << "Введите координату точки X: ";
	  x = GetDouble();
	  cout << "Введите координату точки Y: ";
	  y = GetDouble();
}

void Point::SetX(double _x) { x = _x; }
void Point::SetY(double _y) { y = _y; }
		    
double Point::GetX() { return x; }
double Point::GetY() { return y; }
		    
void Point::ShowPoint() const{
	  cout << "(x = " << setprecision(1) << x;
	  cout << ", y = " << setprecision(1) << y << ");" << endl;
}

Point& Point::operator=(const Point &point) {
	  //cout << "Copy constructor 2" << endl;
	  if(this == &point)
        return *this;
    else {
        x = point.x;
        y = point.y;
        return *this;      
    }  
}

Point operator-(const Point &p, const Point &p1) {
	  double _x = p.x-p1.x;
	  double _y = p.y-p1.y;
	  return Point(_x, _y);
}

void Point::operator+=(const Point &p) {
	  x += p.x;
	  y += p.y;
}

void Point::operator*=(const double coeff) {
	  x *= coeff;
	  y *= coeff;
} 