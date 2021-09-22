#include <stdlib.h>
#include <string>
#include "Tracing_Record.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Tracing_Record::Tracing_Record(string last, string first, int hour, int min, int day, int month, int year, string loc, float t):last_Name(last), first_Name(first), time(hour, min), date(day, month, year), location(loc), temp(t)  {}


Tracing_Record::Tracing_Record(string last, string first, Time ti, Date d, string loc, float t):last_Name(last), first_Name(first), time(ti), date(d), location(loc), temp(t) {}

Tracing_Record::Tracing_Record(){}

void Tracing_Record::set_FirstName(string first){
	first_Name = first;
}

void Tracing_Record::set_LastName(string last){
	last_Name = last;
}

void Tracing_Record::set_Location(string loc){
	location = loc;
}

void Tracing_Record::set_Time(Time ti){
	time = ti;
}

void Tracing_Record::set_Date(Date d){
	date = d;
}

void Tracing_Record::set_Temperature(float t){
	temp = t;
}

Tracing_Record& Tracing_Record::operator=(const Tracing_Record& source){
	if(this != &source){
		last_Name = source.last_Name;
		first_Name = source.first_Name;
		time = source.time;
		date = source.date;
		location = source.location;
		temp = source.temp;
	}
	return *this;
}

void Tracing_Record::print_Record(){
	cout << first_Name + " ";
	cout << last_Name + " ";
	cout << location + " ";
	cout << time << " ";
	cout << date << " ";
	cout <<  temp;
	cout << "\n";
}

string Tracing_Record::getRecordString(){
	return first_Name + " " + last_Name + " " + location + " " + time.get_Time() + " " + date.get_Date() + " " + to_string(temp);
}

ostream& operator<<(ostream &out, const Tracing_Record &record){
	out << record.first_Name << " " << record.last_Name << " " << record.location << " " << record.time << " " << record.date << " " << record.temp;
	return out;
}

istream& operator>>(istream &in, Tracing_Record &record){
	string recordString;
	string parts[6];
	string part;
	int index = 0;
	in >> recordString;
	if(!recordString.empty()){
		cout << "recordString: " << recordString << "\n";
		istringstream ss(recordString);
		while(getline(ss, part, ' ')){
			parts[index] = part;
			index++;
		}

		/*float t = stof(parts[5]);
		Time ti(parts[3]);
		Date da(parts[4]);
		record.first_Name = parts[0];
		record.last_Name = parts[1];
		record.location = parts[2];
		record.time = ti;
		record.date = da;
		record.temp = t;*/
	}
	return in;
}
