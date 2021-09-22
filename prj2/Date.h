#include <stdlib.h>
#include <string>

using namespace std;

class Date{
	public:
		Date(int d, int m, int y);
		Date();
		Date& operator=(const Date& source);
		Date(const string & dateString);
		string get_Date();
		void print_Date();
		friend istream & operator>>(istream &in, Date &date);
		friend ostream & operator<<(ostream &out, const Date &date);

	private:
		int day;
		int month;
		int year;
};
