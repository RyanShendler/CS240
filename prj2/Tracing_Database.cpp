#include <stdlib.h>
#include <string>
#include "Tracing_Database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Tracing_Database::Tracing_Database(){
	database = new Tracing_Record[capacity];
	name = "";
}

Tracing_Database::Tracing_Database(string n){
	database = new Tracing_Record[capacity];
	name = n;
}

Tracing_Database::Tracing_Database(string n, int cap, int records){
	database = new Tracing_Record[cap];
	name = n;
	numRecords = records;
}

Tracing_Database::Tracing_Database(const Tracing_Database &source){
	capacity = source.capacity;
	database = new Tracing_Record[capacity];
	name = source.name;
	numRecords = source.numRecords;
	for(int i = 0; i < numRecords; i++){
		database[i] = source.database[i];
	}
}

Tracing_Database::~Tracing_Database(){
	delete[] database;
}

Tracing_Database& Tracing_Database::operator=(const Tracing_Database& source){
	if (this != &source){
		delete [] database;
		capacity = source.capacity;
		name = source.name;
		numRecords = source.numRecords;
		database = new Tracing_Record[capacity];
		for(int i = 0; i < numRecords; i++){
			database[i] = source.database[i];
		}
	}
	return *this;
}

void Tracing_Database::double_Capacity(){
	Tracing_Record * doubled;
	capacity = 2*capacity;
	doubled = new Tracing_Record[capacity];
	for(int i = 0; i < numRecords; i++){
		doubled[i] = database[i];
	}
	delete[] database;
	database = doubled;
}

void Tracing_Database::add_Record(){
	string last, first, tempString, loc;
	int day, month, year, min, hour;
	float t;
	Date date;
	Time time;

	cout << "\tFirst Name: ";
	getline(cin, first);
	first.erase(remove(first.begin(), first.end(), ' '), first.end());
	cout << "\tLast Name: ";
	getline(cin, last);
	last.erase(remove(last.begin(), last.end(), ' '), last.end());
	cout << "\tLocation: ";
	getline(cin, loc);
	loc.erase(remove(loc.begin(), loc.end(), ' '), loc.end());
	cout << "\tTime [HH:MM]: ";
	cin >> time;
	cout << "\tDate [MM/DD/YYYY]: ";
	cin >> date;
	cout << "\tTemperature: ";
	cin >> t;
	
	Tracing_Record record(last, first, time, date, loc, t);
	if(numRecords == capacity){
		this->double_Capacity();
		database[numRecords] = record;
	} else {
		database[numRecords] = record;
	}
	numRecords++;
}

void Tracing_Database::print_Database(){
	for(int i = 0; i < numRecords; i++){
		database[i].print_Record();
	}	
}

void Tracing_Database::clear_Database(){
	delete[] database;
	numRecords = 0;
}

string Tracing_Database::get_Name(){
	return name;
}

int Tracing_Database::get_Capacity(){
	return capacity;
}

void Tracing_Database::set_Name(string n){
	name = n;
}

int Tracing_Database::get_numRecords(){
	return numRecords;
}

bool Tracing_Database::is_Empty(){
	if(name.empty()) return true;
	else return false;
}

bool input_Exists(string filename){
	ifstream in(filename);
	if(in) return true;
	else return false;
}

void Tracing_Database::print_Info(){
	cout << name + " " + to_string(capacity) + " " + to_string(numRecords) + "\n";
}

void Tracing_Database::appendToFile(){
	string fileName;
	cout << "File Name: ";
	getline(cin, fileName);
	fileName.erase(remove(fileName.begin(), fileName.end(), ' '), fileName.end());
	ofstream output (fileName, ofstream::out | ofstream::app);
	for(int i = 0; i < numRecords; i++){
		string recordString = database[i].getRecordString();
		output << recordString + "\n";	
	}
	output.close();
}

void Tracing_Database::overwriteFile(){
	string fileName;
	cout << "File Name: ";
	getline(cin, fileName);
	fileName.erase(remove(fileName.begin(), fileName.end(), ' '), fileName.end());
	ofstream output (fileName, ofstream::out | ofstream::trunc);
	for(int i = 0; i < numRecords; i++){
		string recordString = database[i].getRecordString();
		output << recordString + "\n";
	}
	output.close();
}

ostream& operator<<(ostream &out, const Tracing_Database &database){
	for(int i = 0; i < database.numRecords; i++){
		out << database.database[i] << "\n";
	}
	return out;
}

void Tracing_Database::replaceFromFile(){
	delete[] database;
	database = new Tracing_Record[capacity];
	numRecords = 0;
	string fileName;
	cout << "File Name: ";
	getline(cin, fileName);
	fileName.erase(remove(fileName.begin(), fileName.end(), ' '), fileName.end());
	if(input_Exists(fileName)){
		ifstream input(fileName, ifstream::in);
		string line;
		int i = 0;
		while(getline(input, line)){
			if(!line.empty()){
				string part;
				string parts[6];
				int index = 0;
				istringstream ss(line);
				while(getline(ss, part, ' ')){
					parts[index] = part;
					index++;
				}
				Time time(parts[3]);
				Date date(parts[4]);
				Tracing_Record record(parts[1], parts[0], time, date, parts[2], stof(parts[5]));
				if(capacity == numRecords){
					this->double_Capacity();
					database[i] = record;
				} else{
					database[i] = record;
				}
				i++;
				numRecords++;
			}
		}
		input.close();
	} else {
		throw 3;
	}
}

void Tracing_Database::uploadFromFile(){
	string fileName;
	cout << "File Name: ";
	getline(cin, fileName);
	fileName.erase(remove(fileName.begin(), fileName.end(), ' '), fileName.end());
	if(input_Exists(fileName)){
		ifstream input(fileName, ifstream::in);
		string line;
		int i = numRecords;
		while(getline(input, line)){
			if(!line.empty()){
				string part;
				string parts[6];
				int index = 0;
				istringstream ss(line);
				while(getline(ss, part, ' ')){
					parts[index] = part;
					index++;
				}
				Time time(parts[3]);
				Date date(parts[4]);
				Tracing_Record record(parts[1], parts[0], time, date, parts[2], stof(parts[5]));
				if(capacity == numRecords){
					this->double_Capacity();
					database[i] = record;
				} else {
					database[i] = record;
				}
				i++;
				numRecords++;
			}
		}
		input.close();
	} else {
		throw 3;
	}
}
