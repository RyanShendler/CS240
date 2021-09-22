#include <stdlib.h>
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

class Tracing_Record{
	public:
		Tracing_Record(string last, string first, int hour, int min, int day, int month, int year, string loc, float t);
		Tracing_Record(string last, string first, Time ti, Date d, string loc, float t);
		Tracing_Record();
		void print_Record();

	private:
		string last_Name;
		string first_Name;
		Time time;
		Date date;
		string location;
		float temp;
};
