// abstract parent class 

#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
//#include <cstring>
#include <iomanip>
#include <cmath>
#include "Point.h"
#include "Figure.h"
//#include "HelperFunc.h"

using namespace std;

typedef enum { TRIANGLE=1, SQUARE, RECTANGLE, CIRCLE} FigureID;

class Figure {
	  protected:
	      char* name;
		public:
		    virtual ~Figure() {
			 	  //std::cout << "Destructor for figure*" << std::endl;
			 	//  if (name)
			       //  delete name;
	     }
			 			 
			 double GetSide(Point a, Point b) {
			 	  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
			 }
			 		 
	      virtual char* GetName() =0;
	      virtual void SetName() =0; 
	      virtual int GetID() =0;
	      virtual bool isNotValid() =0; 	      
	      virtual void Turn() =0;
	          // x` = X*cos(angle) - Y*sin(angle); (Z=0 coz 2-dim)
	          // y` = X* sin(angle) +Y*cos(angle);	      	  
	              	   
		    virtual void Scale() =0; 
		    	   // [T] = [ coeff 0    ]; [X`] = [X]*[T]
	          //       [ 0     coeff]    		
	      virtual void Move() =0;
	      virtual void Show() =0;
};

#endif