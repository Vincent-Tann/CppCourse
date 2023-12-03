#include <iostream>

template <typename T>
class Array {
private:
    T *ptr; //成员指针
    int size; //数组大小

public:
    Array(T arr[], int s); //传入的arr数组为ptr指向的数组赋值，s为输入长度
    ~Array();
    void print(); //依次输出数组元素

};

template <typename T>
Array<T>::Array(T arr[], int s){ //传入的arr数组为ptr指向的数组赋值，s为输入长度
    ptr=new T[s];
    size=s;
    for(int i=0;i<s;i++){ //将arr指向的数组内容复制到ptr指向的数组
        ptr[i]=arr[i];
    }
}

template <typename T>
Array<T>::~Array(){
    delete[] ptr;
}

template <typename T>
void Array<T>::print(){
    for(int i=0;i<size;i++){
        std::cout << ptr[i] << " " ;
    }
    std::cout << std::endl;
}