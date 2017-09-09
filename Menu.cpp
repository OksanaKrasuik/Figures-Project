#include <iostream>
#include <cstdlib>
#include "HelperFunc.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rect.h"
#include "Square.h"
#include "Figure.h"
#include "NodeList.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

Menu::Menu() { 
		//cout << "Node List is created" << endl;
}

int Menu::SelectIDFigure() {
    int nItem = 5, choice = 0;
    do {
        cout << "\n1 - Треугольник  \t2 - Квадрат\n";
        cout << "3 - Прямоугольник\t4 - Окружность\n";
        cout << "\t5 - Выход в главное меню\n";
        
        choice = SelectItem(nItem);
		} while(!choice);
		return choice;
}

void Menu::AddNewFigure() {
	  Figure* _f = 0;	  
	  cout << "\nС какой фигурой будем работать?\n";
	  switch(SelectIDFigure()) {
			  	 case 1: 
					  	 _f = new Triangle;
					  	  if (_f->isNotValid()) {
	   	            cout << "Ошибка!!! Недействительный треугольник!\n";
			            cout << "Попробуйте еще раз" << endl;
			            _f = 0;
	            } 
					  	 break; 
			  	 case 2: 
					  	 _f = new Square;
					  	 if (_f->isNotValid()) {
	   	            cout << "Ошибка!!! Недействительный прямоугольник!\n";
			            cout << "Попробуйте еще раз" << endl;
			            _f = 0;
	            } 
					  	 break;
				 case 3: 
					  	 _f = new Rectangle; 
					  	 if (_f->isNotValid()) {
	   	            cout << "Ошибка!!! Недействительный прямоугольник!\n";
			            cout << "Попробуйте еще раз" << endl;
			            _f = 0;
	            } 
					  	 break;
				 case 4: 
					  	 _f = new Circle;
					  	 break;
				 case 5:
						 break;
				 default:
				      cout << "Ошибка! Не удалось создать фигуру" << endl;
    }	  
    if (_f) {
    	    objList.AddFigure(_f);
			  cout << "\nФигура добавлена" << endl;
		} 	  
} 

void Menu::DelFigure() {
	  int size = objList.GetCount();
	  if (IfNotEmpty()) {
		    cout << "\nУдалить элемент под номером:" << endl;
		    ShowList();
		    int f_choice = SelectItem(size);
		    objList.DelFigure(f_choice);
		}
}

void Menu::ShowAll() const {
	  if (IfNotEmpty())
			  objList.DisplayAll();
}

bool Menu::IfNotEmpty() const {
	  int size = objList.GetCount();
	  if (size == 0) {
			  cout << "\nПустой контейнер. Действие невозможно!\n" << endl;
			  return false;
	  }
	  return true;
}

void Menu::ShowList() const {
	  int size = objList.GetCount();
	  cout << "-----------------------\n" << endl;
		node* current = objList.GetFirst();
	  int _count = 0;
	  while(current && _count < size) {
         cout << "\nФигура " << _count+1 << ": ";
		  	  cout << current->ptrFigure->GetName() << endl;
		  	  current = current->next;
		  	  _count++; 
		}
		cout << endl;
		delete current;
}

void Menu::WorkWithObj(Action &action) {
	  int act_choice;
	  if (IfNotEmpty()) {
        cout << "\n1 - Выбрать фигуру по имени\n";
        cout << "2 - Выбрать группу фигур\n";
        cout << "3 - Выбрать все фигуры\n";
        act_choice = SelectItem(3);
        
			  if (act_choice == 1) 
			      	 Menu::FindByName(action);
			  else if (act_choice == 2) 
			      	 Menu::FindByID(action);
			  else if (act_choice == 3) 
			      	 Menu::AllFigures(action);
			      	 
		}
}

void Menu::FindByName(Action &action) {
	  char* userName = new char[40];
	  bool found = false;
	  cout << "Введите имя фигуры: "; cin >> userName;
		node* current = objList.GetFirst();
	
	  while((current) && (!found)) {
	  	    if (CompareStr(userName, current->ptrFigure->GetName())) {	  
			  	    found = true;
	  	    	     switch (action) {
	  	    	         case MOVE: 
		  	                current->ptrFigure->Move();
		  	                break;
		  	           case TURN:
		  	                current->ptrFigure->Turn();
		  	                break;
		  	           case SCALE:
		  	                current->ptrFigure->Scale(); 
		  	                break;
		  	        }
		  	  }
		  	  else
		  	      current = current->next;
		}	
		if (!found) 
		  	  cout << "Фигура не найдена!!!" << endl;
		delete userName;
}

void Menu::FindByID(Action& action) {
	  FigureID figureID;
	  bool found = false;
	  cout << "Выберите тип фигуры: "; 
	  int type = SelectIDFigure();
	  
		node* current = objList.GetFirst();
	  while(current) {
	  	    if (current->ptrFigure->GetID() == type) {	  
			  	    found = true;
	  	    	     switch (action) {
	  	    	         case MOVE: 
		  	                current->ptrFigure->Move();
		  	                break;
		  	           case TURN:
		  	                current->ptrFigure->Turn();
		  	                break;
		  	           case SCALE:
		  	                current->ptrFigure->Scale(); 
		  	                break;
		  	        }
		  	        cout << "--------------------------\n";
		  	  }
		  	  current = current->next;
		}	
		if (!found) 
		  	  cout << "Фигур такого типа не найдено" << endl;
		  	  
		delete current;
}

void Menu::AllFigures(Action& action) {	  
    Menu::ShowList();
    node* current = objList.GetFirst();
	  while(current) {
	  	    	     switch (action) {
	  	    	         case MOVE: 
		  	                current->ptrFigure->Move();
		  	                break;
		  	           case TURN:
		  	                current->ptrFigure->Turn();
		  	                break;
		  	           case SCALE:
		  	                current->ptrFigure->Scale(); 
		  	                break;
		  	        }
		  	        cout << "--------------------------\n";
		  	  current = current->next;
		}	
}

int Menu::SelectItem(int k) {
	  int item;
	  while(true) {
			  	cin >> item;
			  	if ((item > 0) && (item <= k)) {  // true value 
			  		  //cin.get();
			  		  break;
			  	}
			  	else {
			  		  cout << "Ошибка!!! Неверный ввод!\nПопробуйте еще раз" << endl;
			  		  cin.clear(); 
			  		  while (cin.get() != '\n') {}
			  	}
	  }
	  	return item;
}

Action Menu::SelectAction() {
    cout << "\n/////////////////////////////////////////\n";
    cout << "/////////// ГЛАВНОЕ МЕНЮ ///////////////\n";
    cout << "////////////////////////////////////////\n";
    cout << "\nЧто будем делать с фигурами?\n";
    cout << "\n1 - Добавлять   \t2 - Удалять \n";
    cout << "3 - Поворачивать\t4 - Масштабировать\n";
    cout << "5 - Двигать      \t6 - Выводить информацию\n";
          cout << "\t\t7 - Выход\n";
    
    int choice = SelectItem(7);
    return (Action) (choice);
}