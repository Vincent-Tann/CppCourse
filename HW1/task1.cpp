// 本程序实现队列类，具有入队、出队、返回队首元素、返回队尾元素、判断队列是否为空、返回队列长度一共6个操作。
#include <iostream>
using namespace std;

class Queue{
private:
    int max_len; //记录最大长度
    int len; //记录当前长度
    int* data; //指向数据队列首元素的指针

public:
    Queue(int l){
        max_len=l; //初始化最大长度
        len=0; //初始化当前长度
        data=new int[max_len]; //根据最大长度创建队列
    }
    ~Queue() {
        delete[] data;//用于释放被占用的内存
    }

    //入队
    void enqueue(int number){
        if(len<max_len){
            data[len]=number;
            len+=1;
        }
        else{
            cout << "Queue is already full with max length " << max_len << "!" << endl;
        }
    };

    //出队
    int dequeue(){
        int number;
        if(len>0){
            number=data[0];
            for(int i=0;i<len;i++){
                data[i]=data[i+1];
            }
            len-=1;
        }
        else{
            cout << "Queue is empty! Return 0." << endl;
            number=0;
        }
        return number;
    }

    //返回队首元素
    int get_first_element(){
        return data[0];
    }

    //返回队尾元素
    int get_last_element(){
        if(len==0){
            cout << "Queue is empty! Return 0." << endl;
            return 0;
        }
        return data[len-1];
    }

    //返回队列是否为空
    bool is_empty(){
        return len==0;
    }

    //返回队列长度
    int get_length(){
        return len;
    }


    void print_data(){
        for(int i=0; i<len; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    cout << "测试入队操作,包括队列满时不能再入队：" << endl;
    Queue queue(5);
    for(int i=0;i<6;i++){
        queue.enqueue(i);
        queue.print_data();
    }
    cout << endl;

    cout << "测试出队操作,包括队列空时不能再出队：" << endl;
    for(int i=0;i<6;i++){
        queue.dequeue();
        queue.print_data();
    }
    cout << endl;

    cout << "测试获取首元素和尾元素:" << endl;
    for(int i=100; i>96; i--){
        queue.enqueue(i);
        queue.print_data();
        cout << "First Element:" << queue.get_first_element() << " Last Element:" << queue.get_last_element() << endl;
    }
    cout << endl;

    cout << "测试返回是否为空、返回队列长度:"  << endl;
    queue.print_data();
    cout << "Is Empty:" << queue.is_empty() << " Length:" << queue.get_length() << endl;
    queue=Queue(5);
    queue.print_data();
    cout << "Is Empty:" << queue.is_empty() << " Length:" << queue.get_length() << endl;
}
