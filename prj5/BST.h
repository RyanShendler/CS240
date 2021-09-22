#ifndef _BST_H_
#define _BST_H_

#include "User.h"
#include <string>

class Node {
	public:
		User* user;
		Node* leftchild;
		Node* rightchild;
		Node();
		Node(User* a_user);
		~Node();

};
class BST{
	private:
		Node* root;
		void aux_insert(Node*& root, User* new_user);
		User* aux_find(Node*& root, string user_id);
	public:
		BST();
		~BST();
		void insert(User* new_user);
		User* find_user(string user_id); 
			//returns NULL if not found
		Node* get_root();
		void display(Node* root);
};

#endif


