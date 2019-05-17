#pragma once

#include <stdexcept>
#include <vector>
//unidirectional iterator for a container

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class DynamicArray;

class SMMIterator
{
private:
	const DynamicArray *c;
	int currentPosition;

public:
	SMMIterator(const DynamicArray *c);
	
	void first();

	void next();

	bool valid() const;

	TElem getCurrent() const;
};

