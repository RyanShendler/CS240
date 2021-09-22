#include <stdlib.h>
#include <string>
#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int d, int m, int y):day(d), month(m), year(y) {}

Date::Date(){}

string Date::get_Date(){
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year); 
}

void Date::print_Date(){
	cout << to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " ";
}
