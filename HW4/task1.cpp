#include <iostream> 
using namespace std; 
class Complex 
{ 
public: 
    Complex(double r, double i){
        real=r;
        imag=i;
    }

    Complex complex_add(Complex input_complex){ //自身和另一个复数相加
        Complex result(real+input_complex.real, imag+input_complex.imag);
        real=result.real;
        imag=result.imag; //更新自身复数值，可以访问同类对象result的private成员
        return result;
    } 

    Complex complex_add(int input){ //自身和一个整数相加
        Complex result(real+input, imag);
        real=result.real; //更新自身实部
        return result;
    }

    void display(){
        if(real!=0 && imag>0){ //实部非0，虚部为正
            cout << real << '+' << imag << 'i' << endl;
        }
        else if(real!=0 && imag<0){ //实部非0，虚部为负
            cout << real << imag << 'i' << endl;
        }
        else if(real==0 && imag!=0){ //实部为0，虚部非0
            cout << imag << 'i' << endl;
        }
        else{ //虚部为0
            cout << real << endl;
        }
    }

    friend Complex add_two_complex(Complex c1, Complex c2); //声明友元函数

private: 
    double real; 
    double imag; 
};

Complex add_two_complex(Complex c1, Complex c2){
    Complex result(c1.real+c2.real, c1.imag+c2.imag);
    return result;
}


int main(){
    cout << "c1:" << endl;
    Complex c1(1.5, 2);
    c1.display();
    cout << endl;

    cout << "c2:" << endl;
    Complex c2(4, -5);
    c2.display();
    cout << endl;

    cout << "c1=c1+c2(单目):"  << endl;
    c1.complex_add(c2);
    c1.display();
    cout << endl;

    cout << "c2=c2+3(单目):" << endl;
    c2.complex_add(3);
    c2.display();
    cout << endl;

    cout << "c3=c1+c2(双目):" << endl;
    Complex c3=add_two_complex(c1, c2);
    c3.display();
    cout << endl;

    cout << "c4:" << endl;
    Complex c4(-3.5, 8);
    c4.display();
    cout << endl;

    cout << "c3+c4(双目):" << endl;
    add_two_complex(c3, c4).display();
    cout << endl;

    cout << "测试显示纯虚数：" << endl;
    Complex c5(0,7);
    c5.display();
    Complex c6(0,-6);
    c6.display();
    cout << endl;

    cout << "测试显示实数:" << endl;
    Complex c7(2,0);
    c7.display();
    Complex c8(-3,0);
    c8.display();
    Complex c9(0,0);
    c9.display();
    return 0;

}