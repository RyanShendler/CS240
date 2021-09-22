#include <iostream>
#include "User_Heap.h"

using namespace std;

int get_parent(int index){
	return ((index-1)/2);
}

int get_right(int index){
	return ((2*index)+2);
}

int get_left(int index){
	return ((2*index)+1);
}

User_Heap::User_Heap(){
	size = 0;
}

void User_Heap::max_heapify(int index){
	int l = get_left(index);
	int r = get_right(index);
	int largest = 0;

	if((l <= (size-1)) && (heap[l]->get_jambucks() > heap[index]->get_jambucks())){
		largest = l;
	} else{
		largest = index;
	}
	if((r <= (size-1)) && (heap[r]->get_jambucks() > heap[largest]->get_jambucks())){
		largest = r;
	}
	if(largest != index){
		User* tmp = heap[index];
		heap[index]->set_heap_index(largest);
		heap[index] = heap[largest];
		heap[largest]->set_heap_index(index);
		heap[largest] = tmp;
		max_heapify(largest);
	}
}

void User_Heap::build_heap(){
	for(int i = ((size-1)/2); i >= 1; i--){
		max_heapify(i);
	}
}

void User_Heap::increase_key(int index, int key){
	if(key >= heap[index]->get_jambucks()){
		heap[index]->set_jambucks(key);
		while((index >= 1) && (heap[get_parent(index)]->get_jambucks() < heap[index]->get_jambucks())){
			User* tmp = heap[index];
			heap[index]->set_heap_index(get_parent(index));
			heap[index] = heap[get_parent(index)];
			heap[get_parent(index)]->set_heap_index(index);
			heap[get_parent(index)] = tmp;
			index = get_parent(index);
		}
	} 
}

void User_Heap::insert(User* user){
	if(size != 0){
		int key = user->get_jambucks();
		user->set_jambucks(-1);
		heap.push_back(user);
		size++;
		user->set_heap_index(size-1);
		increase_key((size-1), key);
	} else {
		heap.push_back(user);
		size++;
		user->set_heap_index(size-1);
	}
}

User* User_Heap::extract_max(){
	User* max = NULL;
	if(size >= 1){
		max = heap[0];
		heap[0]->set_heap_index(-1);
		heap[0] = heap[size-1];
		heap.pop_back();
		size--;
		max_heapify(0);
	} 
	return max;
}

void User_Heap::clear_key(User* user){
	user->set_jambucks(0);
	heap.push_back(user);
	size++;
}
