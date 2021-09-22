#include "Item.h"

using namespace std;

Item::Item(string n, int p){
	name = n;
	price = p;
}

ostream& operator<<(ostream &out, const Item &item){
	out << "{" << item.name << ", $" << item.price << "}";
	return out;
}

int Item::get_price(){
	return price;
}
