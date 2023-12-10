#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Cuboid{
private:
    double length;
    double width;
    double height;
    static double total_cost;

public:
    Cuboid(double l=5.0, double w=5.0, double h=5.0){ //长宽高默认值都为5.0
        length=l;
        width=w;
        height=h;
        total_cost+=10*length*width*height;//计算价格并叠加到总价
    }
    static double get_cost(){
        return total_cost;
    }
};
double Cuboid::total_cost=0; //在Cuboid类的定义之外，对静态成员变量total_cost初始化


int main(){
    double length, width, height;
    string user_input;
    
    for(int i=1; i<=4; i++){
        cout << "请依次输入第" << i << "个长方体的长、宽、高（单位：米），用空格隔开：" << endl;
        getline(cin, user_input);
        stringstream s(user_input);
        //用户必须输入三个正数才为有效输入，否则为无效输入，使用默认值
        if (s >> length >> width >> height && length>0 && width>0 && height>0){
            cout << "有效输入，长=" << length << "米，宽=" << width << "米，高=" << height << "米" << endl; 
            Cuboid cuboid(length, width, height);
        }
        else{
            cout << "无效输入，长=宽=高=5米" << endl;
            Cuboid cuboid;
        }
    }
        
    cout << "四个立方体的总造价为：" << Cuboid::get_cost() << endl;
    return 0;
}