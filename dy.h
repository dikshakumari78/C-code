#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
    T* array;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    Stack(size_t initial_capacity = 10);
    ~Stack();

    void push(const T& value);
    void pop();
    T& peek();
    const T& peek() const;
    bool isEmpty() const;
    size_t getSize() const;
    size_t getCapacity() const;
};

#include "Stack.cpp" // Include implementation for templates

#endif // STACK_H
