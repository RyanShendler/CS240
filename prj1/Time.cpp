#include <stdlib.h>
#include <string>
#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m):hour(h), min(m) {}

Time::Time(){}

string Time::get_Time(){
	return to_string(hour) + ":" + to_string(min);
}

void Time::print_Time(){
	cout << to_string(hour) + ":" + to_string(min) + " ";
}
