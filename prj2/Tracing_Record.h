#include <stdlib.h>
#include <sstream>
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
		string getRecordString();
		void set_FirstName(string first);
		void set_LastName(string last);
		void set_Time(Time ti);
		void set_Date(Date d);
		void set_Location(string loc);
		void set_Temperature(float t);
		Tracing_Record& operator=(const Tracing_Record& source);
		friend ostream& operator<<(ostream &out, const Tracing_Record &record);
		friend istream& operator>>(istream &in, Tracing_Record &record);

	private:
		string last_Name;
		string first_Name;
		Time time;
		Date date;
		string location;
		float temp;
};
