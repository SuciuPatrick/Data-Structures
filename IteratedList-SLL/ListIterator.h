//
// Created by Suciu Patrick on 2019-04-06.
//

#ifndef LINKED_LIST_ListIterator_H
#define LINKED_LIST_ListIterator_H

#include "SLL.h"

class SortedBag;

class ListIterator
{
private:
    const SLL *list;
    Node *current;
public:
    //constructor
    ListIterator(const SLL *list);

    void first();

    //checks if the iterator is in a valid position
    bool valid() const;

    //returns the value of the current element
    //throws an exception if the current position is invalid
    TElem getCurrent() const;

    //if the current position is valid, sets the next element as current
    //throws an exception otherwise
    void next();

    //destructor
    ~ListIterator();
};



#endif //LINKED_LIST_ListIterator_H
