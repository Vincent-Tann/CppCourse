#include <iostream>
using namespace std;

void func(int x){
    cout << x;
}

int main(){
    void (*func_pointer)(int)=func;
    func_pointer(666);
    cout << endl;
    (*func_pointer)(888);//尝试两种调用方式

    return 0;
}