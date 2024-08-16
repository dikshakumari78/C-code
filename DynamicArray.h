// DynamicArray.h
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>

template<typename T>
class DynamicArray {
public:
    DynamicArray() : size_(0), capacity_(2), data_(new T[2]) {}

    ~DynamicArray() { delete[] data_; }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Array is empty");
        }
        --size_;
    }

    T& operator[](std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    std::size_t size() const { return size_; }

private:
    void resize(std::size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    std::size_t size_;
    std::size_t capacity_;
    T* data_;
};

#endif // DYNAMICARRAY_H
