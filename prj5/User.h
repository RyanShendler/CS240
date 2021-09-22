#ifndef _USER_H_
#define _USER_H_
#include <vector>
#include "Item.h"

using namespace std;

class User{
	private:
		string userid;
		string last_name;
		string nickname;
		int jambucks;
		int heap_index;
		vector<Item> purchases;

	public:
		User(string id, string name, string nn);
		void update(string new_name);
		void history();
		void purchase(Item item);
		int get_jambucks();
		void set_jambucks(int bucks);
		string get_userid();
		int get_heap_index();
		void set_heap_index(int index);
		string get_nickname();
};
#endif
