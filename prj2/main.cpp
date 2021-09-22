#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "Database_Collection.h"

using namespace std;


int main(){
	Tracing_Database currentDatabase;
	int connectedIndex;
	Database_Collection collection;
	bool running = true;
	string command;

	while (running){
		cout << "\nEnter a command.\n";
		cout << "Choose from [New, List, Quit, Create, Connect, Disconnect, Copy, Show, Drain, Append, Overwrite, Replace, Upload]\n";
		getline(cin, command);
		command.erase(remove(command.begin(), command.end(), ' '), command.end());

		if (command.compare("New") == 0){
			if(!currentDatabase.is_Empty()){
				try{
					currentDatabase.add_Record();
					collection.set_Database(connectedIndex, currentDatabase);
				} catch(int e){
					if(e == 1) cout << "Illegal time format\n";
					if(e == 2) cout << "Illegal date format\n";
				}
			} else {
				cout << "Not connected to any database\n";
			}
		} else if (command.compare("List") == 0){
			if(!currentDatabase.is_Empty()){
				cout << "Tracing Records: \n";
				cout << currentDatabase;
			} else {
				cout << "Not connected to any database\n";
			}
		} else if (command.compare("Quit") == 0){
			running = false;
		} else if (command.compare("Create") == 0){
			try{
				collection.add_Database();
			} catch(int e){
				if(e == 1) cout << "Did not enter a name\n";
			}
		} else if(command.compare("Connect") == 0){
			cout << "Name: ";
			string name;
			getline(cin, name);
			name.erase(remove(name.begin(), name.end(), ' '), name.end());
			currentDatabase = collection.connect_Database(name);
			connectedIndex = collection.get_ConnectedIndex(name);	
		} else if(command.compare("Disconnect") == 0){
			if(!currentDatabase.is_Empty()){
				Tracing_Database emptyDatabase;
				collection.set_Database(connectedIndex, currentDatabase);
				currentDatabase = emptyDatabase;
				cout << "**Disconnected from current collection**\n";
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Copy") == 0){
			if(!currentDatabase.is_Empty()){
				string name;
				cout << "Name: ";
				getline(cin, name);
				name.erase(remove(name.begin(), name.end(), ' '), name.end());
				Tracing_Database copy = currentDatabase;
				copy.set_Name(name);
				collection.add_Database(copy);
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Show") == 0){
			cout << collection;
		} else if(command.compare("Drain") == 0){
			if(!currentDatabase.is_Empty()){
				currentDatabase.clear_Database();
				collection.set_Database(connectedIndex, currentDatabase);
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Append") == 0){
			if(!currentDatabase.is_Empty()){
				currentDatabase.appendToFile();
				collection.set_Database(connectedIndex, currentDatabase);
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Overwrite") == 0){
			if(!currentDatabase.is_Empty()){
				currentDatabase.overwriteFile();
				collection.set_Database(connectedIndex, currentDatabase);
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Replace") == 0){
			if(!currentDatabase.is_Empty()){
				try{
					currentDatabase.replaceFromFile();
				} catch(int e) {
					if(e == 1) cout << "Illegal time format\n";
					if(e == 2) cout << "Illegal data format\n";
					if(e == 3) cout << "Input file does not exist\n";
				}
				collection.set_Database(connectedIndex, currentDatabase);
			} else {
				cout << "Not connected to any database\n";
			}
		} else if(command.compare("Upload") == 0){
			if(!currentDatabase.is_Empty()){
				try{
					currentDatabase.uploadFromFile();
				} catch(int e){
					if(e == 1) cout << "Illegal time format\n";
					if(e == 2) cout << "Illegal date format\n";
					if(e == 3) cout << "Input file does not exist\n";
				}
				collection.set_Database(connectedIndex, currentDatabase);
			} else {
				cout << "Not connected to any database\n";
			}
		} else {
			cout << "Please enter a valid command\n";
		}
	}
}
