// Rectangle class

#ifndef RECT_H
#define RECT_H

#include <iostream>
//#include <cstring>
#include <iomanip>
#include "Point.h"
#include "Figure.h"

using namespace std;

class Rectangle: public Figure {
	  Point up_l, up_r, down_l, down_r;
	  double a, b, c, d; // sides
	  char color;
	  char* name;
	  FigureID ID;
			  
	  public:
		    // costructors
		    Rectangle(char _color=219);
		    Rectangle(Point&, Point&, Point&, Point&, char _color=219); // white color
		    ~Rectangle();
		    
		    // methods
		    void SetName();
		    char* GetName();
		    int GetID();
		    void SetSides();
		    bool isNotValid();
		    void ChangeColor(char);
		   	    
		    void Turn();
		    void Scale();
		    void Move();
		    void Show();
	    
		    // out info
		    friend ostream& operator << (ostream&, Rectangle&);
};

#endif