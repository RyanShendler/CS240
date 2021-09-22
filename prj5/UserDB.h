#ifndef _USERDB_H_
#define _USERDB_H_
#include "User_Heap.h"
#include "BST.h"

class UserDB{
	private:
		BST bst;
		User_Heap heap;
		std::vector<User*> users;
	public:
		UserDB();
		~UserDB();
		void registerr(string userid, string lastname, string nickname);
			//"register" is a keyword in c++
			//so the spelling is wrong
		void update(string userid, string nickname);
		void buy(string userid, string item, int price);
		void history(string userid);
		void report(int n);
		void surprise(int n, string item, int price);
};
#endif
