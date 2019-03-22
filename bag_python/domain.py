class Bag:
	def __init__(self):
		self.__elems = []

	def add(self, e): #complexity O(Unique numbers)
		ok = False
		for set in self.__elems:
			if set[0] == e:
				ok = True
				set[1] += 1

		if ok is False:
			newSet = [e, 1]
			self.__elems.append(newSet)

	def remove(self, e): #complexity O(Unique numbers)
		for index in range(len(self.__elems)):
			set = self.__elems[index]
			if set[0] == e and set[1] > 1:
				set[1] -= 1
				return True
			elif set[0] == e and set[1] == 1:
				self.__elems.pop(index)
				return True
		return False

	def search(self, e): #complexity O(Unique numbers)
		for set in self.__elems:
			if set[0] == e:
				return True
		return False

	def size(self): #complexity theta(Unique numbers)
		cnt = 0
		for set in self.__elems:
			cnt += set[1]
		return cnt

	def nrOccurrences(self, e): #complexity O(Unique numbers)
		for set in self.__elems:
			if set[0] == e:
				return set[1]
		return 0

	def iterator(self): #O(1)
		return BagIterator(self)

	def isEmpty(self):#O(1)
		if len(self.__elems) == 0:
			return True
		return False
	
	def __str__(self):
		for a in self.__elems:
			print(str(a[0]) + " " + str(a[1]))
		return ""


class BagIterator:
	def __init__(self, bag):
		self.__bag = bag
		self.__current = 0
		self.__currentSecond = 0

	def first(self):#O(1)
		self.__current = 0
		self.__currentSecond = 0

	def valid(self):#O(1)
		return self.__current < len(self.__bag._Bag__elems)

	def next(self):
		if self.__current == self.__bag.size():
			raise ValueError()
		if self.__currentSecond <  self.__bag._Bag__elems[self.__current][1] - 1:
			self.__currentSecond += 1
		else:
			self.__current += 1
			self.__currentSecond = 0
		"""
		elif self.__bag._Bag__elems[self.__current][1] - 1 > self.__currentSecond:
			self.__currentSecond += 1
		else:
			self.__current += 1
		"""

	def getCurrent(self):
		if self.valid() == False:
			raise ValueError()
		return self.__bag._Bag__elems[self.__current][0]

