#include <stdlib.h>
#include <string>
#include "Date.h"
#include <iostream>
#include <algorithm>

using namespace std;

Date::Date(int d, int m, int y):day(d), month(m), year(y) {}

Date::Date(){}

Date::Date(const string & dateString){
	//dateString.erase(remove(dateString.begin(), dateString.end(), ' '), dateString.end());
	if(dateString.size() != 10){
		throw 2;
	} else if((dateString.substr(2, 1).compare("/") != 0) || (dateString.substr(5, 1).compare("/") != 0)){
		throw 2;
	} else{
		day = stoi(dateString.substr(0, 2));
		month = stoi(dateString.substr(3,2));
		year = stoi(dateString.substr(6, 4));
	}
}

Date& Date::operator=(const Date& source){
	if(this != &source){
		day = source.day;
		month = source.month;
		year = source.year;
	}
	return *this;
}

string Date::get_Date(){
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year); 
}

void Date::print_Date(){
	cout << to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " ";
}

istream& operator>>(istream &in, Date &date){
	string dateString;
	in >> dateString;
	dateString.erase(remove(dateString.begin(), dateString.end(), ' '), dateString.end());
	if(dateString.size() != 10){
		throw 2;
	}else if((dateString.substr(2, 1).compare("/") != 0) || (dateString.substr(5, 1).compare("/") != 0)){
		throw 2;
	} else {
		date.day = stoi(dateString.substr(0, 2));
		date.month = stoi(dateString.substr(3, 2));
		date.year = stoi(dateString.substr(6, 4));
	}
	return in;
}

ostream& operator<<(ostream &out, const Date &date){
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
