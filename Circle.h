// Circle class

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
//#include <cstring>
#include <iomanip>
#include "Point.h"
#include "Figure.h"

using namespace std;

class Circle: public Figure{
	  double radius;
	  Point center;
	  char color;
	  char* name;
	  FigureID ID;
	  
	  public:
		    // costructors
		    Circle(char _color=219);
		    Circle(double, Point&, char _color=219); // white color
		    ~Circle();
		    
		    // methods
		    void SetName();
		    char* GetName();
		    int GetID();
		    bool isNotValid() {};
		    void ChangeColor(char);
		    
		    void Turn();
		    void Scale();
		    void Move();		    
		    void Show();
		    
		    // out info
		    friend ostream& operator << (ostream&, Circle&);
};

#endif