#ifndef AISD_LAB_RAB_LIST_H
#define AISD_LAB_RAB_LIST_H

template <typename T> class List {
public:
    T value;
    List<T> *next;
    List(T value)
    {
        this->value = value;
        next = nullptr;
    }
};

#endif //AISD_LAB_RAB_LIST_H
