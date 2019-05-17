#pragma once

#include <stdexcept>

class SMMIterator;

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class DynamicArray
{
private:
	int length;
	int capacity;
	TElem *arr;
public:
	//constructor
	//throws an exception if capacity is 0 or negative
	DynamicArray(int capacity);

	//destructor
	~DynamicArray();

	//returns the size(number of elements) of the array
	int size() const;

	//returns the element from a given position(indexing starts from 0
	//throws exception if pos is not a valid position
	TElem getElement(int pos) const;

	int setLength(int);
    int getLength() const;
	//changes the element from position pos to the value of newElem
	//returns the old element from position pos
	//throws exception if pos is not a valid position
	TElem setElement(int pos, TElem newElem);

	//adds a new element to the end of the DynamicArray
	void addToEnd(TElem newElem);

	//adds a new element to a given position
	void addToPosition(int pos, TElem newElem);

	//removes an element from a given position
	//returns the removed element
	//throws exception if pos is not a valid position
	TElem remove(int pos);

	//returns an iterator for the DynamicArray
	SMMIterator iterator() const; // am modificat, de verificat in caz ca nu merge
};

