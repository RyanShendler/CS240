#include "User.h"

using namespace std;

User::User(string id, string name, string nn){
	userid = id;
	last_name = name;
	nickname = nn;
	jambucks = 0;
	heap_index = -1;
}

void User::history(){
	cout << "purchase history => [ ";
	for(unsigned long i = 0; i < purchases.size(); i++){
		cout << purchases[i] << " ";
	}
	cout << "]\n";

}

void User::purchase(Item item){
	purchases.push_back(item);
	int p = item.get_price();
	jambucks = jambucks + 5 + 10*(p/100);
}

void User::update(string new_name){
	nickname = new_name;
}

int User::get_jambucks(){
	return jambucks;
}

void User::set_jambucks(int bucks){
	jambucks = bucks;
}

string User::get_userid(){
	return userid;
}
int User::get_heap_index(){
	return heap_index;
}
void User::set_heap_index(int index){
	heap_index = index;
}

string User::get_nickname(){
	return nickname;
}
