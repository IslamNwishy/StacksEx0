//File: Stackt.cpp

//Name: Islam Osama Nwishy
//ID#:900170200
//Assignment 1 - Part (2)

#include <iostream>
#include "Stackt.h"
using namespace std;

//Constructor: instantiates the top to NULL
template <class Type>
stackt<Type>::stackt() {
	top = NULL;

}

//Deconstructor: sets the top to NULL (Destroys the stack)
template <class Type>
stackt<Type>::~stackt() {
	top = NULL;
}

//Pushes an element to the stack 
//if it is NULL then it has no elements, so the functions pushes the new element on top
//else it creats a new node, make it point to the top and make that new node the top
template <class Type>
void stackt<Type>::push(Type e) {
	if (top==NULL) {
		top = new Node;
		top->var = e;
		top->Next = NULL;
	}
	else {
		NodePointer NewTop = new Node;
		NewTop->var = e;
		NewTop->Next = top;
		top = NewTop;
	}
	
}


//returns the top element if possible, then deletes the node
template <class Type>
Type stackt<Type>::pop() {
	if (top==NULL) {
		cout << "Can't pop from an empty stack! Stack Underflow! " << endl;
	}
	else {
		Type temp = top->var;
		top = top->Next;
		return temp;
	}
	
}

//returns the top element without deleting the node
template <class Type>
Type stackt<Type>::Peak() {
	
	if (top!=NULL)
		return top->var;
	
}

//returns true if the stack is empty
template <class Type>
bool stackt<Type>::IsEmpty() {
	return (top==NULL);
}

//Displays all the elements in the stack
template<class Type>
void stackt<Type>::Display() {
	NodePointer cursor = new Node;
	cursor = top;
	while (cursor != NULL) {
		cout << cursor->var;
		cursor = cursor->Next;
	}
}