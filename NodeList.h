// list for saving adresses of all created figures
// based on linklist

#ifndef NODELIST_H
#define NODELIST_H

#include "Figure.h"
#include "Point.h"

//template <class Type>
struct node {
	  //Type* ptrFigure; // obj
	  Figure* ptrFigure; // obj
	  node* next; // pntr to the next obj
}; 

//template <class Type>    
class NodeList {
	  //node<Type>* first; // starting
	  //node<Type>* last;
	  node* first; // starting
	  node* last;
	  int count; // length of the list
	  
	  public:
	     NodeList() { 
            first = last = NULL; 
            count = 0;
            //std::cout << "Constructor for NodeList" << std::endl;
        }
        
		   ~NodeList() {
			     //std::cout << "Destructor for NodeList:" << std::endl;
			     //node<Type>* 
			     node* current = first;
	          while(current) {
	  	            //node<Type>* 
	  	            node* temp = current;
		  	          current = current->next;	          
		  	          delete temp;
		  	          //std::cout<< "Deleted pointer of Nodelist\n";
	          } 
			 } 
			 
			 int GetCount()	{ return count; }		 
			 node* GetFirst()	{ return first; }	
			 node* GetLast()	{ return last; }	 	 
			 
			 void AddFigure(Figure*);
			 void DelFigure(int);
			 void DisplayAll();
};

//extern NodeList objList;

//template <class Type>
//void NodeList<Type>::AddFigure(Type* _f) {
void NodeList::AddFigure(Figure* _f) {
	  //node<Type>* 
	  node* newNode = new node; //<Type>;
	  newNode->ptrFigure = _f;
	  newNode->next = NULL;
	  count++;
	  // first element
	  if (first == NULL) 
			  first = last = newNode;
			else {
				last->next = newNode;
				last = newNode;
		}
}

void NodeList::DelFigure(int pos) {
	  node *prev;
	  node *after;
	  int ind = 1;
	  node* del = first;
	  
	  while (ind < pos) {
	  	    if (ind+1 == pos) {
			  	    prev = del; // before
			  	    del = del->next; // current
			  	    after = del->next; // next
			  	    prev->next = after; // delete pntrs
			  	    if (first->next == del)
			  	        first->next = after;
			  	} 
			  	else {
			  		  del = del->next;
			  	}
			  	ind++;
	  } 	  
	  if (pos == 1) // head
	      first = first->next;
	  else if (pos == count) { // tail
	      last = prev;
	  } 
	  delete del;
	  count--;
}

//template <class Type>
void NodeList::DisplayAll() {
	  node* current = first;
	  int _count = 0;
	  while(current && _count < count) {
         std::cout<< "Фигура " << _count+1 << "\n";
         std::cout<< "-------------------------\n"; 
		  	  current->ptrFigure->Show();
		  	  current = current->next;
		  	  _count++;
		  	  std::cout<< "\n";
	  }
	  //std::cout << "length = " << count << std::endl;
}

NodeList objList; // global object

#endif