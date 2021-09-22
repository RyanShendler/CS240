#include <stdlib.h>
#include <string>
#include "Tracing_Database.h"
#include <iostream>

using namespace std;

Tracing_Database::Tracing_Database(){
	database = new Tracing_Record[ARRAY_SIZE];
}

void Tracing_Database::add_Record(Tracing_Record record, int index){
	database[index] = record;
}

void Tracing_Database::print_Database(int final_index){
	for(int i = 0; i < final_index; i++){
		database[i].print_Record();
	}	
}
