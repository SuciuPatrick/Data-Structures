//
// Created by Suciu Patrick on 2019-04-21.
//

//#include "DLLAIterator.h"
#include "SortedMap.h"
#include "unistd.h"
#include <iostream>
SortedMap::SortedMap(Relation r) {
    this->r = r;
}

//Complexity O(n)
TValue SortedMap::add(TKey c, TValue v) {
    int index = this->map.head;
    int position = 0;
    int oldVal;
    while (index != -1 && r(this->map.nodes[index].elem.first, c) == true)
    {
        position++;
        //if the pair exists we replace the oldValue
        if (this->map.nodes[index].elem.first == c)
        {
            oldVal = this->map.nodes[index].elem.second;
            this->map.nodes[index].elem.second = v;
            return oldVal;
        }
        index = this->map.nodes[index].next;
    }
    this->map.insertElement(TElem(c, v), position);
    return NULL_TVALUE;
}

//Complexity O(n)
TValue SortedMap::search(TKey c) const {
    int index = this->map.head;

    while (index != -1) {
        if (this->map.nodes[index].elem.first == c) {
            return this->map.nodes[index].elem.second;
        }
        index = this->map.nodes[index].next;
    }
    return NULL_TVALUE;
}

//Complexity O(n)
TValue SortedMap::remove(TKey c) {
    int index = this->map.head;
    int retVal;

    while (index != -1 && this->map.nodes[index].elem.first != c)
        index = this->map.nodes[index].next;
    if (index == -1)
        return NULL_TVALUE;
    retVal = this->map.nodes[index].elem.second;
    this->map.free(index);
    return retVal;
}

int SortedMap::size() const {
    return this->map.length;
}

bool SortedMap::isEmpty() const {
    if (this->map.length == 0)
        return true;
    return false;
}

SMIterator SortedMap::iterator() {
    return SMIterator{this->map};
}