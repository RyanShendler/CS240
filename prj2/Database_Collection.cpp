#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include "Database_Collection.h"

using namespace std;

Database_Collection::Database_Collection(){
	collection = new Tracing_Database[capacity];
}

Database_Collection::~Database_Collection(){
	delete[] collection;
}

Database_Collection::Database_Collection(const Database_Collection &source){
	capacity = source.capacity;
	collection = new Tracing_Database[capacity];
	numDatabases = source.numDatabases;
	for(int i = 0; i < numDatabases; i++){
		collection[i] = source.collection[i];
	}
}

Database_Collection& Database_Collection::operator=(const Database_Collection& source){
	if(this != &source){
		delete [] collection;
		capacity = source.capacity;
		numDatabases = source.numDatabases;
		collection = new Tracing_Database[capacity];
		for(int i = 0; i < numDatabases; i++){
			collection[i] = source.collection[i];
		}
	}
	return *this;
}

void Database_Collection::double_Capacity(){
	Tracing_Database * doubled;
	capacity = 2*capacity;
	doubled = new Tracing_Database[capacity];
	for(int i = 0; i < numDatabases; i++){
		doubled[i] = collection[i];
	}
	delete[] collection;
	collection = doubled;
}

Tracing_Database Database_Collection::connect_Database(string name){
	name.erase(remove(name.begin(), name.end(), ' '), name.end());
	Tracing_Database retVal;
	for(int i = 0; i < capacity; i++){
		if(collection[i].get_Name().compare(name) == 0){
			cout << "**Connected to database " << name << "**\n";
			retVal = collection[i];
			break;
		}
	}
	return retVal;
}

int Database_Collection::get_ConnectedIndex(string name){
	name.erase(remove(name.begin(), name.end(), ' '), name.end());
	int retVal;
	for(int i = 0; i < capacity; i++){
		if(collection[i].get_Name().compare(name) == 0){
			retVal = i;
			break;
		}
	}
	return retVal;
}

void Database_Collection::set_Database(int index, const Tracing_Database &source){
	collection[index] = source;
}

void Database_Collection::print_Collection(){
	for(int i = 0; i < numDatabases; i++){
		collection[i].print_Info();
	}
}

void Database_Collection::add_Database(){
	string name;
	cout << "Name: ";
	getline(cin, name);
	name.erase(remove(name.begin(), name.end(), ' '), name.end());
	if(name.empty()){
		throw 1;
	} else {
		Tracing_Database database(name);
		if(numDatabases == capacity){
			this->double_Capacity();
			collection[numDatabases] = database;
		} else {
       			collection[numDatabases] = database;
		}
		numDatabases++;	
	}
}

void Database_Collection::add_Database(const Tracing_Database& database){
	if(numDatabases == capacity){
		this->double_Capacity();
		collection[numDatabases] = database;
	} else {
		collection[numDatabases] = database;
	}
	numDatabases++;
}

ostream& operator<<(ostream &out, const Database_Collection &collection){
	out << "Tracing Collections: \n";
	for(int i = 0; i < collection.numDatabases; i++){
		out <<  collection.collection[i].get_Name() << " " << collection.collection[i].get_Capacity() << " " << collection.collection[i].get_numRecords() << "\n";
	}	
	return out;
}

