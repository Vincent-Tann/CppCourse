#include <iostream>
using namespace std;

class Matrix{
private:
    int matrix[4][4];

public:
    Matrix(){
        cout << "无参数输入，默认设置为全1矩阵" << endl;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                matrix[i][j]=1;
            }
        }

    }
    Matrix(int keyboardInput){
        cout << "请依次输入4x4矩阵的16个元素:" << endl;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> matrix[i][j]; //等待键盘输入
            }
        }
    }

    void display(){
        cout << "矩阵为:" << endl;
        cout << " _" << '\t' << '\t' << '\t' << '\t' << '\t' << "_" << endl; //打印出矩阵的括号
        for(int i=0; i<4; i++){
            char ch = ((i==0 || i==3) ? '-' : ' ');
            cout << '|' << '\t';
            for(int j=0; j<4; j++){
                cout << matrix[i][j] << '\t';
            }
            cout << " |" << endl;
        }
        cout << " -" << '\t' << '\t' << '\t' << '\t' << '\t' << "-" << endl;
    }
\
};

int main(){
    Matrix m1; //不传入参数时，默认为全1矩阵
    m1.display();

    Matrix m2(1); //传入任意整数参数时，可以从键盘输入矩阵元素
    m2.display();

    return 0;
}