#include <stdlib.h>
#include <string>

using namespace std;

class Date{
	public:
		Date(int d, int m, int y);
		Date();
		string get_Date();
		void print_Date();

	private:
		int day;
		int month;
		int year;
};
