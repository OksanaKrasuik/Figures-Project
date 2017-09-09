#include <iostream>
#include <cmath>
#include "HelperFunc.h"
#include "Rect.h"

using namespace std;

Rectangle:: Rectangle(char _color) {
	   ID = RECTANGLE;
	   name = new char[40];
	   SetName();
     //cout << "Created Rectangle is " << name << endl;
	   cout << "\nЛевый верхний угол" << endl;
	   up_l.SetPoint();
	   cout << "\nПравый верхний угол" << endl;
	   up_r.SetPoint();
	   cout << "\nПравый нижний угол" << endl;
	   down_r.SetPoint();
	   cout << "\nЛевый нижний угол" << endl;
	   down_l.SetPoint();
	   Rectangle::SetSides();
}

Rectangle::Rectangle(Point& _up_l, Point& _up_r, Point& _down_l, Point& _down_r, char _color)
    { 
        name = new char[40];
        up_l = _up_l;
        up_r = _up_r;
        down_l = _down_l;
        down_r = _down_r;

	     // cout << "Constructor for " << name << endl;
	  }

Rectangle::~Rectangle() {
	  //cout << "Destructor for " << name << endl;
	  if (name)
		    delete name;
}

void Rectangle::SetName() {
	  cout<<"\nВведите имя фигуры: "; 
	  cin >> name;
} 

char* Rectangle::GetName() {
	  return name;
}	    

int Rectangle::GetID() { return ID; }

void Rectangle::SetSides() {
	  a = Figure::GetSide(up_l, up_r);
	  b = Figure::GetSide(up_r, down_r);
	  c = Figure::GetSide(down_r, down_l);
	  d = Figure::GetSide(down_l, up_l); 	   
}

bool Rectangle::isNotValid() {
	  // действительный: диагонали равны, углы прямые
	  double ac = Figure::GetSide(up_l, down_r);
	  double bd = Figure::GetSide(up_r, down_l);
	  if ((ac == bd) && (a == c) && (b == d)) { // диагонали и стороны равны 
	  	    // проверка углов по теор. Пифагора
		    return ((ac == sqrt(a*a + b*b)) && (bd == sqrt(c*c + d*d)));
	  }
	  else return false;
}

void Rectangle::ChangeColor(char newColor) {
	  color = newColor;
	  //cout << color;
}

void Rectangle::Turn() {
	  cout << "\nНа какой угол повернуть фигуру (в градусах)?\n";
	  int angle = GetDouble();
	  cout << "\nФигура до поворота:\n" << endl;
	  Rectangle::Show();
	  
	  up_l.SetX(up_l.GetX()*cos(angle) - up_l.GetX()*sin(angle));
	  up_l.SetY(up_l.GetY()*sin(angle) + up_l.GetY()*cos(angle));
	  up_r.SetX(up_r.GetX()*cos(angle) - up_r.GetX()*sin(angle));
	  up_r.SetY(up_r.GetY()*sin(angle) + up_r.GetY()*cos(angle));
	  down_l.SetX(down_l.GetX()*cos(angle) - down_l.GetX()*sin(angle));
	  down_l.SetY(down_l.GetY()*sin(angle) + down_l.GetY()*cos(angle));
	  down_r.SetX(down_r.GetX()*cos(angle) - down_r.GetX()*sin(angle));
	  down_r.SetY(down_r.GetY()*sin(angle) + down_r.GetY()*cos(angle));
	  
	  cout << "\nФигура после:\n" << endl; 
	  Rectangle::Show();
}

void Rectangle::Scale() {
	  cout << "\nВо сколько раз увеличить (уменьшить) фигуру?\n";
	  double coeff = GetDouble();
	  if (coeff > 1)
			  cout << "\nФигура до равномерного увеличения:\n" << endl;
	  else if (coeff < 1)
			  cout << "\nФигура до равномерного уменьшения:\n" << endl;
	  else 
			  cout << "\nФигура останется неизменной\n" << endl;
	  Rectangle::Show();
	  
	  up_l *= coeff;
	  up_r *= coeff;
	  down_r *= coeff;
	  down_l *= coeff; 
	  
	  cout << "\nФигура после:\n" << endl; 
	  Rectangle::Show();
} 

void Rectangle::Move() {
	  cout << "\nКуда будем двигать фигуру?\n";
	  Point moveP;
	  moveP.SetPoint();
	  cout << "\nФигура до смещения:\n" << endl;
	  Rectangle::Show();
	  Point diff = moveP - up_l; // distance btw points
	  up_l = moveP; 
	  up_r += diff;
	  down_r += diff;
	  down_l += diff;
	  cout << "\nФигура после:\n" << endl; 
	  Rectangle::Show();
}

void Rectangle::Show() {
	  cout << setw(30) << setiosflags(ios::left|ios::fixed|ios::showpoint);
	  cout << "Тип: прямоугольник\n";
	  cout << "Имя: " << name << endl;
	  cout << "Координаты левого верхнего угла: "; up_l.ShowPoint();
	  cout << "          правого верхнего угла: "; up_r.ShowPoint();
	  cout << "          правого нижнего угла:  "; down_l.ShowPoint();
	  cout << "          левого нижнего угла:   "; down_r.ShowPoint();
	  
	  cout << "Стороны:" << endl;
	  cout << "    a = " << setprecision(2) << a << endl;
	  cout << "    b = " << setprecision(2) << b << endl;
	  cout << "    c = " << setprecision(2) << c << endl;
	  cout << "    d = " << setprecision(2) << d << endl;
    cout << "Цвет: " << color;
	  cout << endl;
}

ostream& operator << (ostream& out, Rectangle& rt);