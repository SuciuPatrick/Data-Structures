//
// Created by Suciu Patrick on 2019-04-21.
//

#include "SortedMap.h"
#include <unistd.h>
#include <iostream>


//Complexity: theta(1)
DLLAIterator::DLLAIterator(DLLA &toIterate){
    this->toIterate = toIterate;
    this->pos = toIterate.head;
}

//Complexity: theta(1)
DLLAIterator::DLLAIterator(SortedMap &map){
    this->toIterate = map.map;
    this->pos = toIterate.head;
}

//Complexity: theta(1)
void DLLAIterator::first() {
    this->pos = this->toIterate.head;
}
//Complexity: theta(1)
bool DLLAIterator::valid() {
    if (this->pos == -1)
        return false;
    return true;
}
//Complexity: theta(1)
void DLLAIterator::next() {
    if (!this->valid())
        throw std::exception();
    this->pos = this->toIterate.nodes[this->pos].next;
}

//Complexity: theta(1)
TElem DLLAIterator::getCurrent() {
    if (!this->valid())
        throw std::exception();
    return this->toIterate.nodes[this->pos].elem;
}
/*
subalgoritm next (it) is:
//pre: it is a DLLAIterator, it is valid
//post: the current elements from it is moved to the next element
//throws exception if the iterator is not valid
    if it.currentElement = -1
        then @throw exception
    end-if
    it.currentElement <- it.list.nodes[it.currentElement].next
end-subalgorithm
 */
//Complexity theta(1)
void DLLAIterator::previous() {
    if (this->pos == - 1)
        throw std::exception();
    this->pos = this->toIterate.nodes[this->pos].prev;
}

DLLAIterator::~DLLAIterator() {
}