#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

using namespace std;

class Item{
	private:
		string name;
		int price;
	public:
		Item(string n, int p);
		int get_price();
		friend ostream& operator<<(ostream &out, const Item &item);
};
#endif
