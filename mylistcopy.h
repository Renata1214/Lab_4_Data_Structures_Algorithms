#include "payload.h"
#include <iostream>

using std::string;

struct Node
{
//Members of the structure
    Payload instance;
    Node *next_link;
//Constructor
    Node (Payload n);
};

struct ListIterator {

    Node *current;

    ListIterator(Node *node);

    ListIterator& operator++();
    bool operator!=(const ListIterator& other) const;
    Payload& operator*() const;
};

struct List
{
// Members of list
    Node *Head_List; 
//Constructor
List ();
//Destructor
~List();
//Deleting and adding Nodes to list
void push_front (const Payload& name);
void pop_front ();
void push_back (const Payload& name);
void pop_back ();
//Size
int size()const;


// CAPACITY 
int capacity ()const;

//Print
void print () const;

Payload& operator[](int i);

Payload& operator[](int i) const;

//Additional Functions 
bool empty() const; 
Payload front() const; 
Payload back() const;

//Prelab4
ListIterator begin () const;
ListIterator end() const;

};






