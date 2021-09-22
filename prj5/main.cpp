#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "UserDB.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc == 2){
		UserDB database;
		ifstream file(argv[1]);
		string line;
		while(getline(file, line)){
			istringstream s(line);
			string instruction;
			s >> instruction;
			if(instruction == "register"){
				string userid, lastname, nickname;
				s >> userid >> lastname >> nickname;
				database.registerr(userid, lastname, nickname);
			} else if(instruction == "update"){
				string userid, nickname;
				s >> userid >> nickname;
				database.update(userid, nickname);
			} else if(instruction == "buy"){
				string userid, item;
				int price;
				s >> userid >> item;
				s >> price;
				database.buy(userid, item, price);
			} else if(instruction == "history"){
				string userid;
				s >> userid;
				database.history(userid);
			} else if(instruction == "report"){
				int n;
				s >> n;
				database.report(n);
			} else if(instruction == "surprise"){
				int n, price;
				string item;
				s >> n;
				s >> item;
				s >> price;
				database.surprise(n, item, price);
			} else{
				cout << "Incorrect input format.\n";
			}
		}
		file.close();
	} else {
		cout << "Incorrect format.\n";
	}
}
