//
// Created by Suciu Patrick on 2019-04-06.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <iostream>

typedef int TElem;

class Node
{
private:
    TElem e;
    Node *next;
public:
    //constructor
    Node(TElem e);
    void setElem(TElem e);

    //returns the value contained in the node
    TElem getElement() const;

    //returns the address of the next node
    Node *getNext() const;

    //change next element
    void setNext(Node *next);

    //destructor
    ~Node();
};



#endif //LINKED_LIST_NODE_H
