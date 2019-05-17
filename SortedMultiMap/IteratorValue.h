//
// Created by Suciu Patrick on 2019-04-08.
//
#include "DynamicArray.h"
#include <queue>
#include <iostream>

class IteratorValue
{
private:
    std::queue<int> myqueue;
    std::queue<int> copy;
public:
    IteratorValue(const DynamicArray *c, int key);

    void first();

    void next();

    bool valid() const;

    int getCurrent() const;
};

