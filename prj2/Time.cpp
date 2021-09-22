#include <stdlib.h>
#include <string>
#include "Time.h"
#include <iostream>
#include <algorithm>

using namespace std;

Time::Time(int h, int m):hour(h), min(m) {}

Time::Time(){}

Time::Time(const string & timeString){
	//timeString.erase(remove(timeString.begin(), timeString.end(), ' '), timeString.end());
	if(timeString.size() != 5){
		throw 1;
	} else if(timeString.substr(2, 1).compare(":") != 0){
		throw 1;
	} else {
		hour = stoi(timeString.substr(0,2));
		min = stoi(timeString.substr(3,2));
	}
}

Time& Time::operator=(const Time& source){
	if(this != &source){
		hour = source.hour;
		min = source.min;
	}
	return *this;
}

string Time::get_Time(){
	return to_string(hour) + ":" + to_string(min);
}

void Time::print_Time(){
	cout << to_string(hour) + ":" + to_string(min) + " ";
}

istream& operator>>(istream &in, Time &time){
	string timeString;
	in >> timeString;
	timeString.erase(remove(timeString.begin(), timeString.end(), ' '), timeString.end());
	if(timeString.size() != 5){
		throw 1;
	} else if(timeString.substr(2, 1).compare(":") != 0){
		throw 1;
	} else{
		time.hour = stoi(timeString.substr(0, 2));
		time.min = stoi(timeString.substr(3, 2));
	}
	return in;
}

ostream& operator<<(ostream &out, const Time &time){
	out << time.hour << ":" << time.min;
	return out;
}
