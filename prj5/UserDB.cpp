#include "UserDB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

UserDB::UserDB(){}
UserDB::~UserDB(){
	for(unsigned long i=0; i < users.size(); i++){
		delete users[i];
	}
}

//"register" is c++ keyword, so I had to spell it wrong
void UserDB::registerr(string userid, string lastname, string nickname){
	if(bst.find_user(userid)==NULL){
		User* user = new User(userid, lastname, nickname);
		bst.insert(user);
		heap.insert(user); //adds user to heap and adjusts their index
		users.push_back(user);
		std::cout<<"user[" << userid << "] registered"<<std::endl;
	}
	else{
		std::cout<<"user[" << userid << "] already exists!"<<std::endl;
	}
}
void UserDB::update(string userid, string nickname){
	User* user = bst.find_user(userid);
	if(user==NULL){
		std::cout<<"user[" << userid <<"] does not exist!"<<std::endl;
	}
	else{
		user->update(nickname);
		std::cout<<"user[" << userid <<"] nickname updated to "<<nickname<<std::endl;
	}
}
void UserDB::buy(string userid, string item, int price){
	User* user = bst.find_user(userid);
	if(user==NULL){
		std::cout<<"user[" << userid <<"] does not exist!"<<std::endl;
	}
	else{
		user->purchase(Item(item, price));
		heap.increase_key(user->get_heap_index(), user->get_jambucks());
		std::cout<<"user["<<userid<<"] purchase of "<<item<<" SUCCESSFUL!"<<std::endl;
	}
}
void UserDB::history(string userid){
	User* user = bst.find_user(userid);
	if(user==NULL){
		std::cout << "user["<<userid<<"] does not exist!"<<std::endl;
	}
	else{
		std::cout << "user[" << userid << "] ";
		user->history();
	}
}
void UserDB::report(int n){
	int count = n;
	int total = 0;
	std::vector<User*> removed;
	while(count>0){
		User* user = heap.extract_max();
		removed.push_back(user);
		total+= user->get_jambucks();
		count--;
	}
	std::cout<<"#JAMBucks held by top "<<n<<" users = "<<total<<std::endl;
	for(unsigned long i=0; i<removed.size(); i++){
		heap.insert(removed[i]);
	}
}
void UserDB::surprise(int n, string item, int price){
	int count = n;
	std::vector<string> nicknames;
	while(count>0){
		User* user = heap.extract_max();
		nicknames.push_back(user->get_nickname());
		user->purchase(Item(item, price));
		user->set_jambucks(0);
		heap.insert(user);
		count--;
	}
	std::cout<<"Top "<<n<<" users surprised with "<<item<<" worth $"<<price;
	for(unsigned long i=0; i<nicknames.size(); i++){
		std::cout<<" "<<nicknames[i];
	}
	std::cout<<std::endl;	
}
