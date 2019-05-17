//
// Created by Suciu Patrick on 2019-04-21.
//

#ifndef LABORATORY4_DLLA_H
#define LABORATORY4_DLLA_H

#include <iostream>

class DLLAIterator;
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

struct DLLANode
{
    TElem elem;
    int next;
    int prev;
};

class DLLA
{
    friend class DLLAIterator;
    friend class SortedMap;
private:
    DLLANode *nodes;
    int head;
    int tail;
    int firstEmpty;
    int capacity;
    int length;

public:
    DLLA();
    void resize();
    int allocate();
    void free(int position);
    void insertElement(TElem elem, int position);
    DLLAIterator iterator();
    ~DLLA();
};
#endif //LABORATORY4_DLLA_H
