#include "DArray.h"

DArray::DArray() {
    data = nullptr;
    size = 0;
    capacity = 0;
}

DArray::DArray(const DArray& other) {
    data = nullptr;
    size = 0;
    capacity = 0;
    for (int i = 0; i < other.size; i++) {
        push_back(other.data[i]);
    }
}

DArray::~DArray() {
    delete[] data;
}

DArray& DArray::operator=(const DArray& rhs) {
    if (this != &rhs) {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
        for (int i = 0; i < rhs.size; i++) {
            push_back(rhs.data[i]);
        }
    }
    return *this;
}

void DArray::push_back(int value) {
    if (size == capacity) {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity = capacity * 2;
        }
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    data[size] = value;
    size++;
}

int DArray::size() const {
    return size;
}

int DArray::capacity() const {
    return capacity;
}

int& DArray::operator[](int index) {
    return data[index];
}

void DArray::print(ostream& os) const {
    for (int i = 0; i < size; i++) {
        os << data[i] << ' ';
    }
}

ostream& operator<<(ostream& os, const DArray& arr) {
    arr.print(os);
    return os;
}