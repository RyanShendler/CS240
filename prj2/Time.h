#include <stdlib.h>
#include <string>

using namespace std;

class Time{
	public:
		Time(int h, int m);
		Time();
		Time& operator=(const Time& source);
		Time(const string & timeString);
		string get_Time();
		void print_Time();
		friend istream & operator>>(istream& in, Time &time);
		friend ostream & operator<<(ostream &out, const Time &time);

	private:
		int hour;
		int min;	
};
