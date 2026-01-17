// intlist.cpp
// Implements class IntList
// Suveda Singamsetty, 1/16/25

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    this->head = nullptr;
	this->tail = nullptr;
	Node*curr = source.head;
	while(curr){
		push_back(curr->info);
		curr = curr->next;
} 
//IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node*curr = head;
	while(curr){
		Node* temp = curr->next;
		delete curr;
 		curr = temp;
	}
	head = nullptr;
	tail = nullptr;
//IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    if(!head){
	return 0;
}
int sum = 0;
	Node* curr =head;
	while(curr){
		sum+= curr->info;
		curr = curr->next;
	}
	return sum;
 // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(!head){
	return false;
    }
    Node* curr = head;
	while(curr){
		if(curr->info == value){
			return true;
		}
		curr = curr->next;
	}
	return false;
 // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head){
	return 0;
}    	
    int max = 0;
	Node* curr = this->head;
	while(curr){
		if(curr->info > max){
			max = curr->info;
		}
		curr = curr->next;
	}
	return max;
 // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head){
	return 0.0;
}
    int sum = 0;
	double counter = 0;
	Node* curr = head;
	while(curr){
	    sum+= curr->info;
	    counter++;
	    curr = curr->next;
	}
	return sum/counter;
 // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
	newNode->info = value;
	newNode->next = head;
	head = newNode;
// IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
	newNode->info = value;
	newNode->next = nullptr;
	if(!head){
	    head = newNode;
	}
	else{
	    tail->next = newNode;
	}
	tail = newNode;
// IMPLEMENT
 
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
    if(!head){
	return 0;
    }
    int counter = 0;
	Node* curr =head;
	while(curr){
		counter++;
		curr = curr->next;
	}
	return counter;

}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    if(this == &source){
		return *this;
	}
	Node* curr = this->head;
	while(curr){
		Node* temp = head->next;
		delete curr;
		curr = temp;
	}
	this->head = nullptr;
    this->tail = nullptr;
    curr = source.head;
    while(curr){
	    push_back(curr->info);
	    curr = curr->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
	tail = nullptr;
//IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

