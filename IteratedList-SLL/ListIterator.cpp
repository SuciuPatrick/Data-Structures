//
// Created by Suciu Patrick on 2019-04-06.
//

#include "ListIterator.h"
#include "IteratedList.h"

ListIterator::ListIterator(const SLL *list)
{
    this->list = list;
    this->current = list->getHead();
}

void ListIterator::first()
{
    this->current = this->list->getHead();
}

bool ListIterator::valid() const
{
    if (this->current == nullptr)
        return false;
    return true;
}

TElem ListIterator::getCurrent() const
{
    if (this->valid()) {
        return this->current->getElement();
    }
    throw std::exception();
}

void ListIterator::next()
{
    if (!this->valid())
        throw std::exception();
    this->current = this->current->getNext();
}

ListIterator::~ListIterator()
{
}
