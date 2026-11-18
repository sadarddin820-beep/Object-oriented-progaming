#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>

class DArray {
private:
    int* data;      
    int  size;      
    int  capacity;  

public:
    DArray();                                 
                                  
    DArray& operator=(const DArray& rhs);      
    void push_back(int value);                 

    friend std::ostream& operator<<(std::ostream& os, const DArray& arr);
    
    

};

#endif