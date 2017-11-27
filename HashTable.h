#ifndef AISD_LAB_RAB_HASHTABLE_H
#define AISD_LAB_RAB_HASHTABLE_H

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
		List<T> *currentHead;
		List<T> *currentItem;
	public:
		iterator(List<T> *begin)
		{
			this->currentHead = begin;
			this->currentItem = begin;
		}
		iterator& operator++()
		{
			if (this->currentItem->next == nullptr)
			{
				while (this->currentHead == nullptr)
				{
					this->currentHead++;
				}
			}
		}
		T operator*() 
		{ 
			return 5.1; 
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
    };
    ~HashTable()
    {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        delete data;
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
        return 0;
    };
    void clear()
    {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        size = 0;
        count = 0;
    };
    bool search(T &key)
    {
        return false;
    };
    void insert(T &key)
    {
        int i = hash(key);
        if (data[i] == nullptr) {
            data[i] = new List<T>(key);
        }
        else {
            List<T> *head = data[i];
            while (head->next != nullptr) {
                if (head->value == key) {
                    return;
                }
                head = head->next;
            }
            head = new List<T>(key);
        }
    };
    void del(T &key)
    {
        int i = hash(key);
        if (data[i] == nullptr) {
            data[i] = new List<T>(key);
        }
        else {
            List<T> *head = data[i];
            while (head->next != nullptr) {
                if (head->value == key) {
                    return;
                }
                head = head->next;
            }
            head = new List<T>(key);
        }
    };
    int getCountIteration()
    {
        return countIteration;
    }

	iterator begin()
	{
		//
		iterator res(this->data[0]);
		return res;
	}
	iterator& end()
	{
		//
		return new iterator();
	}
	

};

#endif //AISD_LAB_RAB_HASHTABLE_H
