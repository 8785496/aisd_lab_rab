//HashTable.h
#ifndef AISD_LAB_RAB_HASHTABLE_H
#define AISD_LAB_RAB_HASHTABLE_H

#include <iostream>

template <typename K, typename V> class HashTable
{
private:
	const float ALPHA = 2.0f;
	template <typename K, typename V> class List {
	public:
		K key;
		V value;
		List<K, V> *next;
		List(K key, V value)
		{
			this->key = key;
			this->value = value;
			next = nullptr;
		}
	};
    List<K, V> **data;
    int size;
    int count;
    int countIteration;
    int hash(K key)
    {
		long long intKey = int(key * 10000) + 1000000000;
        double hash = intKey * 0.6180339887;
        hash = hash - (long long)hash;
        return (int)(size * hash);
    }
public:
	static const int ERROR_GET_VALUE = 2;
	static const int ERROR_INCREMENT = 3;
	static const int ERROR_EMPTY_TABLE = 4;
	class iterator
	{
		List<K, V> **currentHead;
		List<K, V> **endHead;
		List<K, V> *currentItem;
	public:
		
		iterator(List<K, V> **head, List<K, V> **end)
		{
			currentHead = head;
			endHead = end;
			while (*currentHead == nullptr && currentHead != endHead)
			{
				currentHead++;
			}
			currentItem = *currentHead;
			if (currentHead == endHead)
			{
				throw HashTable::ERROR_EMPTY_TABLE;
			}
		}
		iterator()
		{}
		iterator& operator++()
		{
			if (currentHead == endHead)
			{
				throw ERROR_INCREMENT;
			}
			if (currentItem->next != nullptr)
			{
				currentItem = currentItem->next;
			}
			else
			{
				currentHead++;
				while (*currentHead == nullptr && currentHead != endHead)
				{
					currentHead++;
				}
				currentItem = *currentHead;
			}
			return *this;
		}
		bool operator!=(const iterator& rhs) const { return currentHead != rhs.currentHead; }
		bool operator==(const iterator& rhs) const { return currentHead == rhs.currentHead; }
		V* operator*() 
		{ 
			if (currentHead == endHead)
			{
				throw ERROR_GET_VALUE;
			}
			if (currentHead == endHead || currentItem == nullptr)
			{
				throw HashTable::ERROR_GET_VALUE;
				return nullptr;
			}
			return &currentItem->value;
		}
	};
    HashTable(int count)
    {
		int size = (int)(count / ALPHA);

		int curSize = 2;
		int prevSize = 2;
		while (curSize < size)
		{
			prevSize = curSize;
			curSize *= 2;
		}
		size = prevSize;

		data = new List<K, V>*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = nullptr;
        }
        this->size = size;
        this->count = 0;
		this->countIteration = 0;
    };
    ~HashTable()
    {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        delete [] data;
    };
    int getSize()
    {
        return this->size;
    };
    int getCount()
    {
        return count;
    };
    int getFree()
    {
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (data[i] == nullptr)
			{
				count++;
			}
		}
		return count;
    };
    void clear()
    {
        for (int i = 0; i < size; i++) {
            delete data[i];
			data[i] = nullptr;
        }
        count = 0;
    };
    bool search(K key, V &value)
    {
		int i = hash(key);
		countIteration = 1;
		if (data[i] != nullptr)
		{
			List<K, V> *node = data[i];
			while (node != nullptr)
			{
				if (node->key == key)
				{
					value = node->value;
					return true;
				}
				node = node->next;
				countIteration++;
			}
		}
		return false;
    };
    bool insert(K key, V value)
    {
        int i = hash(key);
        if (data[i] == nullptr) {
			countIteration = 1;
            data[i] = new List<K, V>(key, value);
			count++;
			return true;
        }
        else {
            List<K, V> *item = data[i];
			countIteration = 0;
			while (item != nullptr)
			{
				countIteration++;
				if (item->key == key) {
					return false;
				}
				item = item->next;
			}
			item = new List<K, V>(key, value);
			item->next = data[i];
			data[i] = item;
			count++;
			return true;
        }
    };
    bool remove(K key)
    {
        int i = hash(key);
		countIteration = 1;
        if (data[i] == nullptr) {
			return false;
        }
		List<K, V> *item = data[i];
		List<K, V> *prev = nullptr;
        while (item != nullptr) {
            if (item->key == key) {
				if (prev == nullptr)
				{
					data[i] = item->next;
					item->next = nullptr;
					delete item;
				}
				else
				{
					prev->next = item->next;
					item->next = nullptr;
					delete item;
				}
				count--;
				return true;
            }
			prev = item;
            item = item->next;
			countIteration++;
        }
		return false;
    };
    int getCountIteration()
    {
        return countIteration;
    }
	iterator begin()
	{
		return iterator(&data[0], &data[size]);
	}
	iterator end()
	{
		return iterator(&data[size], &data[size]);
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != nullptr)
			{
				std::cout << "[" << i << "] ";
				List<K, V> *list = data[i];
				while (list != nullptr)
				{
					std::cout << "(" << list->key << ", " << list->value << ") -> ";
					list = list->next;
				}
				std::cout << "null" << std::endl;
			}
			else
			{
				std::cout << "[" << i << "] null" << std::endl;
			}
		}
	}
};

#endif //AISD_LAB_RAB_HASHTABLE_H
