#include "DynamicArray.h"
#include "SMMIterator.h"
#include <cstring>
#include <vector>

DynamicArray::DynamicArray(int capacity)
{
	if (capacity <= 0)
		throw std::invalid_argument("Capacity must be greater than 0.");
	this->arr = new TElem[capacity];
	if (this->arr == nullptr)
		throw std::exception();
	this->capacity = capacity;
	this->length = 0;
}


DynamicArray::~DynamicArray()
{
	delete this->arr;
}

int DynamicArray::size() const
{
	return this->length;
}

TElem DynamicArray::getElement(int pos) const
{
	if (pos >= this->length)
		throw std::invalid_argument("Index out of range.");
	return this->arr[pos];
}

TElem DynamicArray::setElement(int pos, TElem newElem)
{
	TElem oldElem;

	if (pos >= this->length)
		throw std::invalid_argument("Index out of range.");
	oldElem = this->arr[pos];
	this->arr[pos] = newElem;
	return oldElem;
}

void DynamicArray::addToEnd(TElem newElem)
{
	TElem *auxArr, *oldArr;

	if (this->length + 1 >= this->capacity)
	{
		auxArr = new TElem[this->capacity * 2];
		memcpy(auxArr, this->arr, sizeof(TElem) * this->length);
		oldArr = this->arr;
		this->arr = auxArr;
		delete oldArr;
		this->capacity *= 2;
	}
	this->arr[length] = newElem;
	this->length += 1;
}

void DynamicArray::addToPosition(int pos, TElem newElem)
{
	TElem *auxArr, *oldArr;

	if (pos < 0 || pos > this->length)
		throw std::invalid_argument("Position must be greater than or equal to 0");
	if (this->length + 1 >= this->capacity)
	{
		auxArr = new TElem[this->capacity * 2];
		if (auxArr == nullptr)
			throw std::exception();
		memcpy(auxArr, this->arr, sizeof(TElem) * this->length);
		oldArr = this->arr;
		this->arr = auxArr;
		delete oldArr;
		this->capacity *= 2;
	}
	for (int i = this->length; i > pos; i--)
		this->arr[i] = this->arr[i - 1];
	this->arr[pos] = newElem;
	this->length += 1;
}

TElem DynamicArray::remove(int pos)
{
	TElem removed;

	if (pos < 0 || pos > this->length - 1)
		throw std::invalid_argument("Index out of range.");
	removed = this->arr[pos];
	for (int i = pos; i < this->length - 1; i++)
		this->arr[i] = this->arr[i + 1];
	this->length -= 1;
	return removed;
}

SMMIterator DynamicArray::iterator() const
{
	return {this};
}

int DynamicArray::setLength(int new_size) {
    this->length = new_size;
}

int DynamicArray::getLength() const {
    return this->length;
}