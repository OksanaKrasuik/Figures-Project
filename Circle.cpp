#include <iostream>
#include <cmath>
#include "Circle.h"
#include "HelperFunc.h"

using namespace std;

Circle::Circle(char _color) {
	  ID = CIRCLE;
	  name = new char[40];
    SetName();
	  //cout << "Created Circle is " << name << endl;
	  cout << "\nЦентр круга" << endl;
	  center.SetPoint();
	  cout << "\nРадиус" << endl;
	  cout << "Введите желаемый радиус: ";
	  radius = GetDouble();
}

Circle::Circle(double _radius, Point& _center, char _color) { 
        radius = _radius;
        center = _center;         
        name = new char[40];     	      
	      //cout << "Constructor for " << name << endl;
	  }
	  
Circle::~Circle() {
	  //cout << "Destructor for " << name << endl;
	  if (name)
		    delete name;
}

void Circle::SetName() {
	  //char temp[40];
	  cout<<"\nВведите имя фигуры: "; 
	//  cin.getline(temp, 40);
    cin >> name;
    /*int nameLen = length(temp);
	  name = new char[nameLen+1];	
    strCopy(name, temp); */
    //delete []temp;
} 

char* Circle::GetName() { return name; }	
int Circle::GetID() { return ID; }

void Circle::ChangeColor(char newColor) {
	  color = newColor;
	  //cout << color;
}

void Circle:: Turn() {
		 Circle::Show();
}

void Circle::Scale() {
	  cout << "\nВо сколько раз увеличить (уменьшить) фигуру?\n";
	  double coeff = GetDouble();
	  if (coeff > 1)
			  cout << "\nФигура до равномерного увеличения:\n" << endl;
	  else if (coeff < 1)
			  cout << "\nФигура до равномерного уменьшения:\n" << endl;
	  else 
			  cout << "\nФигура останется неизменной\n" << endl;
	  Circle::Show();
	  
	  radius *= coeff;
	  
	  cout << "\nФигура после:\n" << endl; 
	  Circle::Show();
} 

void Circle::Move() {
	  cout << "\nКуда будем двигать фигуру?\n";
	  Point moveP;
	  moveP.SetPoint();
	  cout << "\nФигура до смещения:\n" << endl;
	  Circle::Show();
	  center = moveP;
	  cout << "\nФигура после:\n" << endl; 
	  Circle::Show();
}

void Circle::Show() {
	  cout << setw(30) << setiosflags(ios::left|ios::fixed|ios::showpoint);
	  cout << "Тип: окружность\n";
	  cout << "Имя: " << name << endl;
	  cout << "Координаты центра: "; center.ShowPoint();
	  cout << "Радиус = " << setprecision(2) << radius << endl;
    cout << "Цвет: " << color;
	  cout << endl;
}

ostream& operator << (ostream& out, Circle& cr) {}