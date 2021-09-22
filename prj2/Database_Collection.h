#include <stdlib.h>
#include <string>
#include <iostream>
#include "Tracing_Database.h"

using namespace std;

class Database_Collection{
	public:
		Database_Collection();
		Database_Collection(const Database_Collection &source);
		~Database_Collection();
		void double_Capacity();
		Tracing_Database connect_Database(string name);
		void print_Collection();
		void add_Database();
		void set_Database(int index, const Tracing_Database &source);
		int get_ConnectedIndex(string name);
		void add_Database(const Tracing_Database& database);
		Database_Collection& operator=(const Database_Collection& source);
		friend ostream & operator<<(ostream &out, const Database_Collection &collection);

	private:
		int capacity = 10;
		Tracing_Database *collection;
		int numDatabases = 0;
};
