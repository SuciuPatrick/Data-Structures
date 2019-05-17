//
// Created by Suciu Patrick on 2019-04-06.
//

#include "SLL.h"
#include "ListIterator.h"
#include <unistd.h>

SLL::SLL()
{
    this->head = nullptr;
}

SLL::SLL(Node *head)
{
    this->head = head;
}
bool SLL::search(TElem e) const
{
    Node *current = this->head;

    if (current == nullptr)
        return false;
    while (current->getNext() != nullptr && current->getElement() != e)
        current = current->getNext();
    return current->getElement() == e;
}

void SLL::insertFirst(TElem e)
{
    Node *newNode;
    newNode = new Node(e);

    newNode->setNext(this->head);
    this->head = newNode;
}

void SLL::insertAfter(Node *current, TElem e)
{
    Node *newNode;

    newNode = new Node(e);

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

void SLL::insertPosition(int position, TElem e)
{
    Node *current;
    int currentPosition;

    if (position < 0)
        throw std::invalid_argument("Index out ooof range.");
    if (position == 0)
    {
        this->insertFirst(e);
        return;
    }
    currentPosition = 1;
    current = this->head;
    while (current && currentPosition < position)
    {
        currentPosition++;
        current = current->getNext();
    }
    if (current)
        this->insertAfter(current, e);
    else
        throw std::invalid_argument("Index out of range.");
}

Node *SLL::getNode(int position) const
{
    Node *current;
    int currentPosition;

    current = this->head;
    if (position < 1)
        throw std::invalid_argument("Index out of range.");
    if (position == 1)
        return current;
    currentPosition = 1;
    while (current && currentPosition < position - 1)
    {
        currentPosition++;
        current = current->getNext();
    }
    if (current)
        return current;
    else
        throw std::invalid_argument("Index out of range.");
}

TElem SLL::getNodeElement(int position) const
{
    Node *current;
    int currentPosition;

    current = this->head;
    currentPosition = 1;
    if (position < 1)
        throw std::invalid_argument("Index out of range.");
    while (current && currentPosition < position - 1)
    {
        currentPosition++;
        current = current->getNext();
    }
}

Node* SLL::deleteElement(TElem e)
{
    Node *current, *prev;

    current = this->head;
    prev = nullptr;
    while (current && current->getElement() != e)
    {
        prev = current;
        current = current->getNext();
    }
    if(prev == nullptr) {
        this->head = nullptr;
    }
    else if (current != nullptr && current->getElement() == e)
        prev->setNext(current->getNext());

    return current;
}

Node *SLL::getHead() const
{
    return this->head;
}

ListIterator SLL::iterator() const
{
    return ListIterator(this);
}

SLL::~SLL()
{
    Node *current, *next;
    int i;

    i = 0;
    current = this->head;
    while (current)
    {
        next = current->getNext();
        delete current;
        current = nullptr;
        current = next;
    }
    this->head = nullptr;
}
