#ifndef MENU_H
#define MENU_H

typedef enum { ADD=1, DEL, TURN, SCALE, MOVE, SHOW, EXIT} Action;

class Menu {
		public:
			Menu();			
			void AddNewFigure();
			void DelFigure();
			void ShowAll() const;
			void MoveObj();
			
			void ShowList() const;
			bool IfNotEmpty() const;
			void WorkWithObj(Action&);
			void FindByName(Action&);
			void FindByID(Action&);
			void AllFigures(Action&);
						
			Action SelectAction();
			int SelectIDFigure();
			int SelectItem(int);
};

#endif