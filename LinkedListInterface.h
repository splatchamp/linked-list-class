// YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <string>

template<typename T>
class LinkedListInterface {
public:
    LinkedListInterface() {}

    virtual ~LinkedListInterface() {}

    virtual void push_front(T item) = 0;
    virtual void push_back(T item) = 0;
    virtual void insert(T item, size_t position) = 0;

    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual void remove(size_t position) = 0;

    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual T at(size_t index) const = 0;

    virtual bool contains(const T& item) const = 0;

    virtual size_t size() const = 0;

    virtual void clear() = 0;

    virtual std::string toString() const = 0;
};