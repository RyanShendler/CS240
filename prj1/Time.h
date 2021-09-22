#include <stdlib.h>
#include <string>

using namespace std;

class Time{
	public:
		Time(int h, int m);
		Time();
		string get_Time();
		void print_Time();

	private:
		int hour;
		int min;	
};
