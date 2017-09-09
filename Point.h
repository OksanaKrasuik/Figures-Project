#ifndef POINT_H
#define POINT_H

class Point {
	  public:
		    double x, y;
	  public:	      
	      // constructor
	      //Point();
		    Point(double _x=0, double _y=0);
		    Point(const Point &);
		    ~Point() {};
		    
		    //methods
		    void SetPoint();
		    void SetX(double);
		    void SetY(double);
		    double GetX();
		    double GetY();
		    void ShowPoint() const;
		    
		    // overloading
		    Point& operator=(const Point &);
		    friend Point operator-(const Point &, const Point&);
		    void operator+=(const Point&);
		    void operator*=(const double);
};

#endif 