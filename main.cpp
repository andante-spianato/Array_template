#include <iostream>
#include <cassert>
using namespace std;
#include "Array.h"

int main(){
    //下标的输入与处理
    int lh, rh;
    cout << "请输入下标的下界：" << endl;
    cin >> lh;
    cout << "请输入下标的上界：" << endl;
    cin >> rh;
    assert (lh > rh);

    //定义两个对象
    Array<double> doubleArray(lh, rh);
    Array<int> intArray(lh, rh);

    //输入
    cout << "现在输入的是doubleArray：" << endl;
    cin >> doubleArray;
    cout << "现在输入的是intArray："  << endl;
    cin >> intArray;

    //输出
    cout << doubleArray;
    cout << intArray;
    


    return 0;


}