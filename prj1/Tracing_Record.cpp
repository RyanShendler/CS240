#include <stdlib.h>
#include <string>
#include "Tracing_Record.h"
#include <iostream>

using namespace std;

Tracing_Record::Tracing_Record(string last, string first, int hour, int min, int day, int month, int year, string loc, float t):last_Name(last), first_Name(first), time(hour, min), date(day, month, year), location(loc), temp(t)  {}


Tracing_Record::Tracing_Record(string last, string first, Time ti, Date d, string loc, float t):last_Name(last), first_Name(first), time(ti), date(d), location(loc), temp(t) {}

Tracing_Record::Tracing_Record(){}

void Tracing_Record::print_Record(){
	cout << first_Name + " ";
	cout << last_Name + " ";
	cout << location + " ";
	time.print_Time();
	date.print_Date();
	cout <<  temp;
	cout << "\n";
}
