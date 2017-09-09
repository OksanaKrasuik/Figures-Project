#include <cmath>
#include "Triangle.h"
#include "HelperFunc.h"

using namespace std;

Triangle::Triangle(char _color) {	   
     ID = TRIANGLE;
     name = new char[40];
	   SetName();
     //cout << "\nCreated Triangle is " << name << endl;
	   cout << "\nВершина треугольника" << endl;
	   up.SetPoint();
	   cout << "\nПравый угол" << endl;
	   right.SetPoint();
	   cout << "\nЛевый угол" << endl;
	   left.SetPoint();
	   Triangle::SetSides();
}

Triangle::Triangle(Point &_up, Point &_right, Point &_left, char _color)
    { 
        name = new char[40];
        up = _up;
        right = _right;
        left = _left;
	      
	      //cout << "Constructor for " << name << endl;
	  }

Triangle::~Triangle() {
	  //cout << "Destructor for " << name << endl;
	  if (name)
		    delete name;
}

void Triangle::SetName() {
	  cout<<"\nВведите имя фигуры: "; 
	  cin >> name;
} 

char* Triangle::GetName() {
	  return name;
}	    

int Triangle::GetID() { return ID; }

void Triangle::SetSides() {
	  a = Figure::GetSide(up, right);
	  b = Figure::GetSide(right, left);
	  c = Figure::GetSide(left, up);	   
}

bool Triangle::isNotValid() {
	  // если одна из сторон больше суммы 2х других, то
	  // треугольник недействителен
	  //cout << a << b << c;
	  return ((a > b + c) || (b > a + c) || (c > a + b));			  
}

void Triangle::ChangeColor(char newColor) {
	  color = newColor;
}

void Triangle::Turn() {
	  cout << "\nНа какой угол повернуть фигур (в градусах)?\n";
	  int angle = GetDouble();
	  cout << "\nФигура до поворота:\n" << endl;
	  Triangle::Show();
	  
	  up.SetX(up.GetX()*cos(angle) - up.GetX()*sin(angle));
	  up.SetY(up.GetY()*sin(angle) + up.GetY()*cos(angle));
	  right.SetX(right.GetX()*cos(angle) - right.GetX()*sin(angle));
	  right.SetY(right.GetY()*sin(angle) + right.GetY()*cos(angle));
	  left.SetX(left.GetX()*cos(angle) - left.GetX()*sin(angle));
	  left.SetY(left.GetY()*sin(angle) + left.GetY()*cos(angle));
	  
	  cout << "\nФигура после:\n" << endl; 
	  Triangle::Show();
}

void Triangle::Scale() {
	  cout << "\nВо сколько раз увеличить (уменьшить) фигуру?\n";
	  double coeff = GetDouble();
	  if (coeff > 1)
			  cout << "\nФигура до равномерного увеличения:\n" << endl;
	  else if (coeff < 1)
			  cout << "\nФигура до равномерного уменьшения:\n" << endl;
	  else 
			  cout << "\nФигура останется неизменной\n" << endl;
	  Triangle::Show();
	  
	  up*=coeff;
	  right *= coeff;
	  left *= coeff;
	  
	  cout << "\nФигура после:\n" << endl; 
	  Triangle::Show();
} 

void Triangle::Move() {
	  cout << "\nКуда будем двигать фигуру?\n";
	  Point moveP;
	  moveP.SetPoint();
	  cout << "\nФигура до смещения:\n" << endl;
	  Triangle::Show();
	  Point diff = moveP - up; // distance btw points
	  up = moveP; 
	  right += diff;
	  left += diff;
	  cout << "\nФигура после:\n" << endl; 
	  Triangle::Show();
}

ostream& operator << (ostream& out, Triangle& tr) {
	  out << setw(30) << setiosflags(ios::left|ios::showpoint);
	  out << "Тип: треугольник\n";
	  out << "Имя: " << tr.name << endl;
	  out << "Координаты вершины: "; tr.up.ShowPoint();
	  out << "           правого угла: "; tr.right.ShowPoint();
	  out << "           левого угла: "; tr.left.ShowPoint();
	  out << "Цвет: " << tr.color << endl;
	  out << "Стороны:\n";
	  out << "    a = " << setprecision(2) << tr.a << endl;
	  out << "    b = " << setprecision(2) << tr.b << endl;
	  out << "    c = " << setprecision(2) << tr.c << endl;
	  
	  return out;
}

void Triangle::Show() {
	  cout << setw(30) << setiosflags(ios::left|ios::fixed|ios::showpoint);
	  cout << "Тип: треугольник\n";
	  cout << "Имя: " << name << endl;
	  cout << "Координаты вершины:      "; up.ShowPoint();
	  cout << "           правого угла: "; right.ShowPoint();
	  cout << "           левого угла:  "; left.ShowPoint();
	  cout << "Цвет: " << color << endl;
	  cout << "Стороны:\n";
	  cout << "    a = " << setprecision(2) << a << endl;
	  cout << "    b = " << setprecision(2) << b << endl;
	  cout << "    c = " << setprecision(2) << c << endl;
}