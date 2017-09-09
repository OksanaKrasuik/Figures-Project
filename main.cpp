//////////////////////////////////////////////////////////
// Project for creating and working with geometric figures
//////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <locale.h>
#include "HelperFunc.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rect.h"
#include "Square.h"
#include "Figure.h"
//#include "NodeList.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

const int LEN_NAME = 40;
char nameBuffer[LEN_NAME+1];
	  
void Test();

int main(){
    setlocale(LC_ALL, "rus");

    Menu menu;
    Action action; // what to do
    FigureID figureID; // with what obj
    
    do {
		    	switch (action) {
		    		  case ADD:
				    		  menu.AddNewFigure();
				    		  break;
				    	 case DEL:
				    		  menu.DelFigure();
				    		  break;
				    	 case MOVE: case TURN: case SCALE: 
				    		  menu.WorkWithObj(action);
				    		  break;
				    	 case SHOW:
				    		  menu.ShowAll();
				    		  break;				    	    
		    	} 
		}
		while ((action = menu.SelectAction()) != EXIT);
    //system("cls");
    cout << "\n\t\t\tНадеюсь, вам понравилось :)\n\t\t\tДосвидания!\n" << endl;             
    getch(); // задержка изображения
    exit(0);
    

	  //Test();
    return 0;
}

/*
void Test() {
	  Point p1, p2(2.3, 4.8), p3, p4(1.2, 3);
	  p3 = p1;
	  p1.ShowPoint();
	 // p1.SetPoint();
	  p1.ShowPoint();
	  p2.ShowPoint();
	  p3.ShowPoint();
	  Point p7(p1);
	  p7.ShowPoint();
	  std::cout << "-------------------------------" << std::endl;
    Triangle tr1(p2, p1, p4);
    tr1.SetName();
	  tr1.Show();
	  std::cout << "Name: " << tr1.GetName() << std::endl;
	  //tr1.ShowSides();
	  std::cout << "-------------------------------" << std::endl;
	  //tr1 += Point(1., 3.4);
	  //tr1.Show();
	  tr1.Move(Point(1., 3.4));
	  tr1.Show();
	  std::cout << "-------------------------------" << std::endl;
	  //tr1 *= 1.1;
	  //tr1.Show();
	  tr1.Scale(1.1);
	  tr1.Show(); 
	  std::cout << "-------------------------------" << std::endl;
	  tr1.ChangeColor(180);
	  tr1.Show();
    std::cout << '\n';
    std::cout << "-------------------------------" << std::endl;
    Circle b1(4., p3);
    b1.Show();
    b1.SetName();
    b1.GetName();
    Rectangle r1(p1, p2, p3, p4);
    r1.Show();
    r1.GetName();
    Square cr1(p1, p2, p3, p4);
    cr1.Show();
    //cr1.SetName();
    //cr1.GetName();
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Figure *: "<< std::endl;
	  Figure* ptr1 = &tr1;
    Triangle tr2(p2, p1, p4);
    Figure* ptr2 = &tr2;
    ptr1->Show();
    //NodeList f;
	 //f.AddFigure(ptr1);
    //f.AddFigure(ptr2);
	 // f.DisplayAll();
	  std::cout << "-------------------------------" << std::endl;
	  //Figure* _f;
	  //Triangle tr;
	  //_f->SetFigure();
	  std::cout << "-------------------------------" << std::endl;
     double x = GetDouble();
	  cout <<  x << endl;
	  cout << "-------------------------------" << endl;
	  //Menu menu1;
	  //menu1.SelectFigure();
    
} */