#include "SMMIterator.h"
#include "DynamicArray.h"

SMMIterator::SMMIterator(const DynamicArray *c)
{
	this->c = c;
	this->currentPosition = 0;
}

void SMMIterator::first()
{
	this->currentPosition = 0;
}

void SMMIterator::next()
{
	if (!this->valid())
		throw std::exception();
	this->currentPosition += 1;
}

bool SMMIterator::valid() const
{
	return this->currentPosition < this->c->size();
}

TElem SMMIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception();
	return this->c->getElement(this->currentPosition);
}