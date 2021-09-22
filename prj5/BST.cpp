#include "BST.h"
#include <iostream>
#include <stdlib.h>
#include <string>

Node::Node(){
	user = nullptr;
	leftchild = nullptr;
	rightchild = nullptr;
}
Node::Node(User* a_user){
	user = a_user;
	leftchild = nullptr;
	rightchild = nullptr;
}
Node::~Node(){
	delete leftchild;
	delete rightchild;
}
BST::BST(){
	root = nullptr;
}
BST::~BST(){
	delete root;
}
void BST::insert(User* new_user){
	aux_insert(root, new_user);
}
void BST::aux_insert(Node*& curnode, User* new_user){
	if(curnode==nullptr){
		curnode = new Node(new_user);
	}
	else if(new_user->get_userid() < curnode->user->get_userid()){
		aux_insert(curnode->leftchild, new_user);
	}
	else{
		aux_insert(curnode->rightchild, new_user);
	}
	
}
User* BST::find_user(string user_id){ //Returns null if not found
	return aux_find(root, user_id);
}
User* BST::aux_find(Node*& curnode, string user_id){
	if(curnode==nullptr){
		return nullptr;
	}
	else if(user_id < curnode->user->get_userid()){
		return aux_find(curnode->leftchild, user_id);
	}
	else if(user_id > curnode->user->get_userid()){
		return aux_find(curnode->rightchild, user_id);
	}
	else{ //User found
		return curnode->user;
	}

}
Node* BST::get_root(){
	return root;
}
void BST::display(Node* curnode){
	if(curnode->leftchild==nullptr){
		std::cout<<"NULL "<<std::endl;
	}
	else{
		display(curnode->leftchild);
	}
	std::cout << curnode->user->get_userid() << " "<< curnode->user->get_nickname() << std::endl;
	if(curnode->rightchild==nullptr){
		std::cout<<"NULL "<<std::endl;
	}
	else{
		display(curnode->rightchild);
	}
}


