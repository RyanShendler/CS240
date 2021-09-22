#include <stdlib.h>
#include <string>
#include "Tracing_Record.h"

using namespace std;

class Tracing_Database{
	public:
		Tracing_Database();
		void add_Record(Tracing_Record record, int index);
		void print_Database(int final_index);

	private:
		Tracing_Record* database = NULL;
		const int ARRAY_SIZE = 100;
};
