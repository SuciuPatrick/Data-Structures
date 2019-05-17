#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <unistd.h>
#include <iostream>

SortedMultiMap::SortedMultiMap(Relation r) {
    this->relation = r;
    this->da = new DynamicArray(100);
}

vector<TValue> SortedMultiMap::search(TKey c) const {
    int index = 0;
    vector<int> vec;
    SMMIterator it = this->da->iterator();
    it.first();
    while (it.valid())
    {
        TElem current = it.getCurrent();
        if (current.first == c)
            vec.push_back(current.second);
        it.next();
    }
    return vec;
}

void SortedMultiMap::add(TKey c, TValue v) {
    int index = 0;
    SMMIterator it = this->da->iterator();
    it.first();
    while (it.valid())
    {
        TElem current = it.getCurrent();

        if (this->relation(std::get<0>(current), c)) {
            this->da->addToPosition(index, TElem(c, v));
            return;
        }

        index++;
        it.next();
       // this->da->setLength(index);
    }
    this->da->addToEnd(TElem(c, v));
}

int SortedMultiMap::size() const {
    int index = 0;
    vector<int> vec;
    SMMIterator it = this->da->iterator();
    it.first();
    while (it.valid())
    {
        index++;
        it.next();
    }
    return index;
}

bool SortedMultiMap::isEmpty() const {
    return this->size() == 0;
}

SMMIterator SortedMultiMap::iterator() const {
    return this->da->iterator();
}

bool SortedMultiMap::remove(TKey c, TValue v) {
    int index = 0;
    bool ok = false;
    SMMIterator it = this->da->iterator();
    it.first();
    while(it.valid())
    {
        TElem current = it.getCurrent();
        if (current.first == c && current.second == v)
            ok = true;

        if (current.first == c && current.second == v)
        {
            for (int k = index + 1; k < da->size(); k++)
            {
                da->setElement(k - 1, da->getElement(k));
                break;
            }
        }
        it.next();
        index++;
    }
    if (ok == false)
        return false;
    da->setLength(da->getLength() - 1);
    return true;
}
