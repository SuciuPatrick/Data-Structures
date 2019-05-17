//
// Created by Suciu Patrick on 2019-04-06.
//

#include "Node.h"

Node::Node(TElem e)
{
    this->e = e;
    this->next = nullptr;
}

TElem Node::getElement() const
{
    return this->e;
}

void Node::setElem(TElem e){
    this->e = e;
}

Node *Node::getNext() const
{
    return this->next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

Node::~Node()
{
}
