#ifndef _HEAP_H_
#define _HEAP_H_
#include <vector>
#include "User.h"

using namespace std;

class User_Heap{
	private:
		vector<User *> heap;
		int size;
	public:
		User_Heap();
		void max_heapify(int index);
		void increase_key(int index, int key);
		void insert(User* user);
		void build_heap();
		void clear_key(User* user);
		User* extract_max();
};
#endif
