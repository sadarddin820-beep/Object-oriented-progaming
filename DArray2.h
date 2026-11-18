#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>

class DArray {
    int* data;
    int size;
    int capacity;
public:
    DArray();
    
    DArray& operator=(const DArray& rhs);
    void push_back(int value);
    int size() const;
    int capacity() const;
    void print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const DArray& arr);
~DArray();
#endif