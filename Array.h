#ifndef _Array
#define _Array

template <class T>
class Array{
private:
    int low;
    int high;
    T *storage;

public:
    Array(int lh, int rh):low(lh), high(rh){storage = new T [high - low + 1];}
    Array(const Array &arr);
    Array &operator=(const Array &a);

    T & operator[](int index){
        assert 
    }








};









#endif