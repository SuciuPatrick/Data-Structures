//
// Created by Suciu Patrick on 2019-04-21.
//

#include "DLLAIterator.h"

DLLA::DLLA() {
    this->capacity = 1000;
    this->length = 0;
    this->head = -1;
    this->tail = -1;
    this->firstEmpty = 0;
    this->nodes = new DLLANode[1000];
    for (int i = 0;i < this->capacity;i++)
    {
        if (i != 0)
            this->nodes[i].prev = i - 1;
        else
            this->nodes[i].prev = -1;
        if (i != this->capacity - 1)
            this->nodes[i].next = i + 1;
        else
            this->nodes[i].next = -1;
    }
}

//Complexity: O(n)
void DLLA::resize() {
    int newCapacity = this->capacity * 2;
    DLLANode *toDelete = this->nodes;

    this->nodes = new DLLANode[newCapacity];
    memcpy(this->nodes, toDelete, sizeof(DLLANode) * this->capacity);
    this->firstEmpty = this->capacity;
    this->capacity = newCapacity;
    for (int i = this->firstEmpty;i < this->capacity;i++) {
        if (i != 0)
            this->nodes[i].prev = i - 1;
        else
            this->nodes[i].prev = -1;
        if (i != this->capacity - 1)
            this->nodes[i].next = i + 1;
        else
            this->nodes[i].next = -1;
    }
}

//theta(1)
int DLLA::allocate() {
    int position;
    int newEmpty;

    this->length++;
    if (this->firstEmpty == -1)
        this->resize();
    position = this->firstEmpty;
    newEmpty = this->nodes[this->firstEmpty].next;
    if (newEmpty == -1)
        this->nodes[this->firstEmpty].prev = -1;
    this->nodes[this->firstEmpty].next = -1;
    this->nodes[this->firstEmpty].prev = -1;
    this->firstEmpty = newEmpty;
    return position;
}

//complexity theta(1)
void DLLA::free(int position) {
    int prev, next;

    prev = this->nodes[position].prev;
    next = this->nodes[position].next;
    if (this->head == position)//daca e primul elem
        this->head = next;
    this->nodes[prev].next = next;
    this->nodes[next].prev = prev;
    this->nodes[position].next = this->firstEmpty;
    this->nodes[position].prev = -1;
    if (this->firstEmpty != -1)
        this->nodes[firstEmpty].prev = position;
    this->firstEmpty = position;
    this->length--;
}

//Complexity: O(n)
void DLLA::insertElement(TElem elem, int position) {
    int newPos = this->allocate();
    this->nodes[newPos].elem = elem;
    if (position == 0) {
        if (this->head == -1) {
            this->head = newPos;
            this->tail = newPos;
        }
        else {
            this->nodes[newPos].next = this->head;
            this->nodes[this->head].prev = newPos;
            this->head = newPos;
        }
    }
    else {
        int nodC = this->head;
        int pozC = 0;
        while (nodC != -1 && pozC < position - 1) {
            nodC = this->nodes[nodC].next;
            pozC++;
        }
        if (nodC != -1) {
            int nodNext = this->nodes[nodC].next;
            this->nodes[newPos].next = nodNext;
            this->nodes[newPos].prev = nodC;
            this->nodes[nodC].next = newPos;
            if (nodNext == -1)
                this->tail = newPos;
            else
                this->nodes[nodNext].prev = newPos;
        }
    }
}

DLLAIterator DLLA::iterator() {
    return DLLAIterator(*this);
}
DLLA::~DLLA() {
}