#include <stdlib.h>
#include <string>
#include "Tracing_Record.h"

using namespace std;

class Tracing_Database{
	public:
		Tracing_Database();
		Tracing_Database(string n);
		Tracing_Database(string n, int cap, int records);
		Tracing_Database(const Tracing_Database &source);
		Tracing_Database& operator=(const Tracing_Database& source);
		~Tracing_Database();
		void add_Record();
		void double_Capacity();
		void print_Database();
		void clear_Database();
		void appendToFile();
		void overwriteFile();
		void replaceFromFile();
		void uploadFromFile();
		bool is_Empty();
		string get_Name();
		int get_Capacity();
		int get_numRecords();
		void print_Info();
		void set_Name(string n);
		friend ostream & operator<<(ostream &out, const Tracing_Database &database);

	private:
		Tracing_Record* database;
		int capacity = 2;
		string name;
		int numRecords = 0;
};

bool input_Exists(string filename);
