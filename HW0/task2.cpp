// 本程序定义PERSON类，支持初始化是设定人名和年龄，同时支持重复设定或显示人名和年龄。
#include <iostream>
using namespace std;

class PERSON{
public:
    string name;
    int age;

    PERSON(string n, int a){
        name=n;
        age=a;
    }

    void set_name(string n){
        cout << "Set the person's name to " << n << "." << endl;
        name=n;
    }
    void set_age(int a){
        cout << "Set the person's age to " << a << "." << endl;
        age=a;
    }
    
    void show_name(){
        cout << "Name: " << name << endl;
    }
    void show_age(){
        cout << "Age: " << age << endl;
    }
};

int main(){
    // 实例化PERSON类
    PERSON person1("Bob",21);
    // 显示人名和年龄
    person1.show_name();
    person1.show_age();
    // 修改人名和年龄
    person1.set_name("Bob Williams");
    person1.set_age(29);
    // 再次显示人名和年龄
    person1.show_name();
    person1.show_age();
    return 0;
}