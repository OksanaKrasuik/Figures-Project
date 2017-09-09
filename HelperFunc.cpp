#include <iostream>
#include "HelperFunc.h"

using std::cout;
using std::endl;
using std::cin;

int length(char* str) {
	  int str_len = 0;
		while (*str) {
    	 	str_len++;
    	 	str++;
	  }
	  return str_len;
} 

void strCopy(char* buffer, const char* source) {
		while(*source) {
			  *buffer = *source;
			  source++;
			  buffer++;
		}
		*buffer = '\0';
} 

double GetDouble() {
	  double d_num = 0;
	  while(true) {
			  	//cout << "Введите вещественное число: " << endl;
			  	cin >> d_num;
			  	if ((d_num) || (d_num == 0)) break; // true value
			  	else {
			  		  cout << "Ошибка!!! Попробуйте еще раз!" << endl;
			  		  //cin.ignore();
			  		  cin.clear(); 
			  		  while (cin.get() != '\n') {} 
			  	}
	  }
	  	return d_num;
}

bool CompareStr(const char* source, const char* str) {
	  while (*source) {
			  	if (*source == *str) {
			  	    source++;
			  	    str++; 	
			  	}
			  	else 
					  	return false;
	  }
	  return (*str == 0);
}