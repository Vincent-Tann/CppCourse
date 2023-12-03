#include <iostream>
#include "task1_Array.h"
using namespace std;


int main(){
    const int len=6;

    // 测试int Array
    cout << "测试int Array:" << endl;
    int* int_ptr=new int[len];
    for(int i=0;i<len;i++){
        int_ptr[i]=i*2;
    }
    Array<int> intArray(int_ptr, len);
    intArray.print(); 

    // 测试double Array
     cout << "测试double Array:" << endl;
    double* double_ptr=new double[len];
    for(int i=0;i<len;i++){
        double_ptr[i]=5-i*0.2;
    }
    Array<double> doubleArray(double_ptr, len);
    doubleArray.print();

    //测试char Array
     cout << "测试char Array:" << endl;
    char* char_ptr=new char[6];
    char_ptr[0]='A';
    char_ptr[1]='B';
    char_ptr[2]='C';
    char_ptr[3]='D';
    char_ptr[4]='E';
    char_ptr[5]='F'; //注意结尾没有加'\0'，不能用作字符串
    Array<char> charArray(char_ptr, len);
    charArray.print();

    return 0;
}

