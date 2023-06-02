#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "LinkedListInterface.h"

using std::cout, std::endl, std::cerr;

template<typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node(T value) {
            data = value;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    size_t ll_size = 0;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }


    virtual ~LinkedList() {
        clear();
    }

    virtual void push_front(T item) {
        Node* new_node = new Node(item);
        if (ll_size == 0) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
        ll_size++;
    }

    virtual void push_back(T item) {
        Node* new_node = new Node(item);
        if (ll_size == 0) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
            tail->next = NULL;
        }
        ll_size++;
    }

    virtual void insert(T item, size_t position) {
        if (position > ll_size)
            throw std::out_of_range("Index for insertion is too high.");

        Node* new_node = new Node(item);
        size_t index = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (index == position-1) {
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
            index++;
        }
        ll_size++;
    }

    virtual void pop_front() {
        if (head == NULL)
            throw std::length_error("There are no elements in the list.");
        if (head->next == NULL)
            tail = nullptr;
        head = head->next;
        ll_size--;
    }

    virtual void pop_back() {
        if (head == NULL)
            throw std::length_error("There are no elements in the list.");
        else if (head == tail)
            head = nullptr;
            tail = nullptr;

        size_t index = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (index == ll_size-2) {
                ptr->next = nullptr;
                tail = ptr;
            }
            index++;
        }
        ll_size--;
    }

    virtual void remove(size_t position) {
        if (head == NULL)
            throw std::length_error("There are no elements in the list.");
        else if (position >= ll_size)
            throw std::out_of_range("Index for removal is too high.");
        else if (position == 0) {
            pop_front();
            return;
        }

        size_t index = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (index == position-1) {
                ptr->next = ptr->next->next;
            }
            index++;
        }
        ll_size--;
    }

    virtual T front() const {
        if (head == NULL)
            throw std::length_error("There are no elements in the list.");
        return head->data;
    }

    virtual T back() const {
        if (head == NULL)
            throw std::length_error("There are no elements in the list.");
        return tail->data;
    }

    virtual T at(size_t index) const {
        if (index >= ll_size)
            throw std::out_of_range("Index for accessing is too high");

        size_t count = 0;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (count == index)
                return ptr->data;
            count++;
        }
    }

    virtual bool contains(const T &item) const {
        if (head == NULL)
            return false;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (ptr->data == item)
                return true;
        }
        return false;
    }

    virtual size_t size() const {
        return ll_size;
    }

    virtual void clear() {
        Node* temp = nullptr;
        Node* ptr = head;
        while (ptr != NULL) {
            temp = ptr->next;
            delete ptr;
            ptr = temp;
        }

        ll_size = 0;
        head = nullptr;
        tail = nullptr;
    }

    virtual std::string toString() const {
        if (head == NULL)
            cerr << "Nothing in list.";

        std::stringstream ss;
        for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
            ss << ptr->data << ' ';
        }
        std::string output_string = ss.str();
        return output_string;
    }
};