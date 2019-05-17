#pragma once
#include "Node.h"

class ListIterator;

class SLL
{
private:
    Node *head;
public:
    //constructor with head set to nullptr
    SLL();

    //constructor with head set to given node
    SLL(Node *head);

    //searches for an element, returns true if found, otherwise false
    bool search(TElem e) const;

    //inserts an element to the beginning of the list
    void insertFirst(TElem e);

    //inserts an element after a given node
    void insertAfter(Node *current, TElem e);

    //inserts an element at a given position
    //throws an exception if given position is invalid
    void insertPosition(int position, TElem elem);

    //gets a node from a given position
    //throws an exception if given position is invalid
    Node *getNode(int position) const;

    //gets info from node at a given postion
    //throws an exception if given position is invalid
    TElem getNodeElement(int position) const;

    //deletes a node containing a given info
    Node *deleteElement(TElem e);

    //returns the first element of the list
    Node *getHead() const;

    //returns an iterator for this list
    ListIterator iterator() const;

    //destructor
    ~SLL();
};

