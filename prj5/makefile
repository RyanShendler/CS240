CC	= g++
FLAGS	= -Wall -Wextra -g

all: main

main: main.o db.o bst.o heap.o user.o item.o
	$(CC) $(FLAGS) main.o db.o bst.o heap.o user.o item.o -o main

main.o: main.cpp UserDB.h BST.h User_Heap.h User.h Item.h
	$(CC) $(FLAGS) -c main.cpp -o main.o 

item.o: Item.cpp Item.h
	$(CC) $(FLAGS) -c Item.cpp -o item.o

user.o: User.cpp User.h Item.h
	$(CC) $(FLAGS) -c User.cpp -o user.o

heap.o: User_Heap.cpp User_Heap.h User.h Item.h
	$(CC) $(FLAGS) -c User_Heap.cpp -o heap.o

bst.o: BST.cpp BST.h User.h Item.h
	$(CC) $(FLAGS) -c BST.cpp -o bst.o

db.o: UserDB.cpp UserDB.h User_Heap.h BST.h User.h Item.h
	$(CC) $(FLAGS) -c UserDB.cpp -o db.o

clean:
	rm -f *.o main
