//File: Stackt.h

//Name: Islam Osama Nwishy
//ID#:900170200
//Assignment 1 - Part (2)

#ifndef Stackt_H
#define Stackt_H


template<class Type>
class stackt {

private:
	
	class Node {
	public:
		//var for variable
		Type var;
		Node* Next;
	};
	typedef Node * NodePointer;
	NodePointer top;
public:
	stackt();
	~stackt();
	void push(Type e);
	Type pop();
	Type Peak();
	bool IsEmpty();
	void Display();
	


};
#endif;
