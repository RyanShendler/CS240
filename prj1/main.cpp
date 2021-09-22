#include <stdlib.h>
#include <iostream>
#include <string>
#include "Tracing_Database.h"

using namespace std;

int main(){
	Tracing_Database database;
	bool running = true;
	string command;
	int cur_Index = 0;

	//cout << "Please enter a command: \n"

	while (running){
		cout << "\nEnter a command.\n";
		cout << "Choose from [New, List, Quit]\n";
		getline(cin, command);

		if (command.compare("New") == 0){
			if (cur_Index >= 100){
				cout << "Record database is full\n";
			} else {
				
				string last;
				string first;
				string dateString;
				int day;
				int month;
				int year;
				string timeString;
				int hour;
				int min;
				string loc;
				string tempString;
				float t;

				cout << "\tFirst Name: ";
				getline(cin, first);
				cout << "\tLast Name: ";
				getline(cin, last);
				cout << "\tLocation: ";
				getline(cin, loc);
				cout << "\tTime [HH:MM]: ";
				getline(cin, timeString);
				if(timeString.size() != 5){
					cout << "Incorrect time format: " + timeString;
					continue;
				} else if (timeString.substr(2,1).compare(":") != 0){
					cout << "Incorrect time format: " + timeString;
					continue;
				}
				cout << "\tDate [MM/DD/YYYY]: ";
				getline(cin, dateString);
				if(dateString.size() != 10){
					cout << "Incorrect date format: " + dateString;
					continue;
				} else if((dateString.substr(2,1).compare("/") != 0) || (dateString.substr(5,1).compare("/") != 0)){
					cout << "Incorrect date format: " + dateString;
					continue;
				}
				cout << "\tTemperature: ";
				getline(cin, tempString);
				if(tempString.empty()){
					cout << "Incorrect temperature format: " + tempString;
					continue;
				}
	
				hour = stoi(timeString.substr(0, 2));
				min = stoi(timeString.substr(3, 2));
				day = stoi(dateString.substr(0, 2));
				month = stoi(dateString.substr(3, 2));
				year = stoi(dateString.substr(6, 4));
				t = stof(tempString);
				Date date(day, month, year);
				Time time(hour, min);
				Tracing_Record record(last, first, time, date, loc, t);
				database.add_Record(record, cur_Index);
				cur_Index++;
			}

		} else if (command.compare("List") == 0){
			cout << "Tracing Records: \n";
			database.print_Database(cur_Index);
		} else if (command.compare("Quit") == 0){
			running = false;
		} else {
			cout << "Please enter a valid command";
		}
	}
}
