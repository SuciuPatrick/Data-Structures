#include "IteratorValue.h"
#include <iostream>
#include <queue>

IteratorValue::IteratorValue(const DynamicArray *c, int key) {
    for (int i = 0; i < c->size(); i++)
        if (c->getElement(i).first == key)
            this->myqueue.push(c->getElement(i).second);
    this->copy = this->myqueue;
}

void IteratorValue::first() {
    this->myqueue = copy;
}

void IteratorValue::next() {
    this->myqueue.pop();
}

bool IteratorValue::valid() const {
    return this->myqueue.empty() == false;
}

int IteratorValue::getCurrent() const {
    return myqueue.front();
}
