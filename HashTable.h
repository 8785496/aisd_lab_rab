//HashTable.h
#ifndef AISD_LAB_RAB_HASHTABLE_H
#define AISD_LAB_RAB_HASHTABLE_H

#include <iostream>
#include "List.h"

template <typename T> class HashTable
{
private:
    List<T> **data;
    int size;
    int count;
    int countIteration;
    int hash(T &key)
    {
        float hash = key + 10000.0f;
        hash = hash * 0.6180339887f;
        hash = hash - (int)hash;
        return (int)(size * hash);
    }
public:
	class iterator
	{
		List<T> **currentHead;
		List<T> *currentItem;
	public:
		iterator(List<T> **head)
		{
			currentHead = head;
			//std::cout << "iterator constructor: " << currentHead << std::endl;
		}
		iterator& operator++()
		{
			currentHead++;
			//std::cout << "operator++: " << currentHead << std::endl;
			return *this;
			//if (this->currentItem->next == nullptr)
			//{
			//	while (this->currentHead == nullptr)
			//	{
			//		this->currentHead++;
			//	}
			//}
		}
		//iterator(const iterator& mit) : iterator(mit.currentHead) {}
		bool operator!=(const iterator& rhs) const { return currentHead != rhs.currentHead; }
		bool operator==(const iterator& rhs) const { return currentHead == rhs.currentHead; }
		T operator*() 
		{ 
			return 5.1f; 
		}
	};

    HashTable(int size)
    {
        data = new List<T>*[size];
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
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (data[i] != nullptr) {
                List<T> *head = data[i];
                while (head != nullptr) {
                    count++;
                    head = head->next;
                }
            }
        }
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
    bool search(T &key)
    {
		int i = hash(key);
		countIteration = 1;
		if (data[i] != nullptr)
		{
			List<T> *node = data[i];
			while (node != nullptr)
			{
				if (node->value == key)
				{
					return true;
				}
				node = node->next;
				countIteration++;
			}
		}
		return false;
    };
    void insert(T &key)
    {
        int i = hash(key);
		countIteration = 1;
        if (data[i] == nullptr) {
            data[i] = new List<T>(key);
        }
        else {
            List<T> *item = data[i];
            do {
                if (item->value == key) {
                    return;
                }
                item = item->next == nullptr ? item : item->next;
				countIteration++;
			} while (item->next != nullptr);
            item->next = new List<T>(key);
        }
    };
    void del(T &key)
    {
        int i = hash(key);
		countIteration = 1;
        if (data[i] == nullptr) {
			return;
        }
		List<T> *item = data[i];
		List<T> *prev = nullptr;
        while (item != nullptr) {
            if (item->value == key) {
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
				return;
            }
			prev = item;
            item = item->next;
			countIteration++;
        }
    };
    int getCountIteration()
    {
        return countIteration;
    }

	iterator begin()
	{
		return iterator(&data[0]);
	}
	iterator end()
	{
		return iterator(&data[size]);
	}
	
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != nullptr)
			{
				std::cout << "[" << i << "] ";
				List<T> *list = data[i];
				while (list != nullptr)
				{
					std::cout << list->value << " -> ";
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
