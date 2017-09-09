// Triangle class

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
//#include <cstring>
#include <iomanip>
#include "Point.h"
#include "Figure.h"

using namespace std;

class Triangle: public Figure {	  
	  Point up, right, left;
	  double a, b, c; // sides
	  char color;
	  char* name;
	  FigureID ID;
			  
	  public:
		    // costructors
		    Triangle(char _color=219);
		    Triangle(Point&, Point&, Point&, char _color=219); // white color
		    ~Triangle();
		    
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
		    friend ostream& operator << (ostream&, Triangle&);
};

#endif