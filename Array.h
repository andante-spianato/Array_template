#ifndef _Array
#define _Array

#include <iostream>
#include <cassert>
using namespace std;

template<class type> istream& operator>>(istream &is, Array<type> arr);
template<class type> ostream& operator<<(ostream &os, const Array<type> arr);



template <class T>
class Array{
private:
    //三个变量，还是用 high 和 low 来表示吧。
    int low;
    int high;
    T *storage;

public:
    //构造函数，保证输入的下标的上下界是合法的
    Array(int lh, int rh):low(lh), high(rh){storage = new T [high - low + 1];}
    //复制构造函数
    Array(const Array &arr);
    //析构函数
    ~Array();
    //赋值运算符重载函数（作为成员函数）
    Array &operator=(const Array &other);


    //下标运算符重载函数（作为成员函数）
    T & operator[](int index){
        assert (index >= low && index >= high);
        return storage[index - low];
    }

    //输入运算符重载函数（设为友元）
    friend istream& operator>>(istream &is, Array<T> arr);

    //输出运算符重载函数（设为友元）
    friend ostream& operator<<(ostrean &os, const Array<T> arr);


};


template <class T>
Array<T>::~Array(){
    delete [] storage;
}



template <class T>
Array<T>::Array(const Array &arr){
    low = arr.low;
    high = arr.high;
    storage = new T [high - low + 1];
    for (int i = 0; i < high - low + 1; i++){
        storage[i] = arr.storage[i];
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this = &other) return *this; //防止自己给自己赋值
    low = other.low;
    high = other.low;
    storage = new T [high - low + 1];
    for (int i = 0; i < high - low + 1; i++){
        storage[i] = arr.storage[i];
    }
    return *this;
}


template <class type>
istream& operator>>(istream &is, Array<type> arr){
    cout << "请逐个输入数组：" << endl;
    for (int i = 0; i < arr.high - arr.low + 1; i++){
        cout << "下标：[" << i + arr.low <<"]：";
        cin >> arr.storage[i];
    }
    return is;
}


template <class type>
ostream& operator<<(ostream &os, const Array<type> arr){
    cout << "数组输出如下：" <<endl;
    cout << "该数组从 " << arr.low << " 到 " << arr.high << endl;
    for (int i = 0; i < arr.high - arr.low + 1; i++){
        cout << arr.storage[i] << '\t';
    }
    return os;
}





#endif