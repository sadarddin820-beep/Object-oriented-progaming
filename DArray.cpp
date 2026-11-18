#include "DArray.h"

DArray::DArray() 
 data{nullptr}, size{0} capacity{0};

DArray::DArray(const DArray& other) {
    for (int i = 0; i < other.size; ++i){
     push_back(other.data[i]);
    }
}

DArray::~DArray()
 { 
    delete[] data;
 }

DArray& DArray::operator=(const DArray& rhs) {
    if (this != &rhs) {
        delete[] data;
        data = nullptr;
        size = 0;
        for (int i = 0; i < rhs.size; ++i) 
        {
            push_back(rhs.data[i]);
        }
    }
    return *this;
}

void DArray::push_back(int value) {
    int* temp = new int[size + 1];
    for (int i = 0; i < size; ++i) temp[i] = data[i];
    temp[size] = value;
    delete[] data;
    data = temp;
    ++size;
}

void DArray::print(std::ostream& os) const {
    for (int i = 0; i < size; ++i) os << data[i] << ' ';
}

std::ostream& operator<<(std::ostream& os, const DArray& arr) {
    arr.print(os);
    return os;
}