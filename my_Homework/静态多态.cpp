#include <iostream>
using namespace std;

#define ‌π 3.14

//CRTP基类：形状基类模板
template<typename  Derived>
class Shape
{
private:
    
public:
    double area() const //统一的面积接口
    {
        //静态转换，编译时期确定调用派生类的calcArea()
        return static_cast<const Derived *>(this)->calcArea();
    }

    void print() const //统一的打印接口
    {
        cout << "该形状的面积为: " << area() << endl;
    }
};

class Rect: public Shape<Rect>
{
    friend class Shape<Rect>;
private:
    int _len; //长
    int _wid; //宽
public:
    Rect(int len, int wid) :_len(len),_wid(wid){}

protected:
    //派生类自己实现具体的面积计算
    double calcArea() const
    {
        return _len * _wid;
    }
};

class Circle: public Shape<Circle>
{
    friend class Shape<Circle>;
private:
    int _r;
public:
    Circle(int r) :_r(r){}

protected:
    double calcArea() const
    {
        return ‌π * _r * _r;
    }
};

int main()
{
    Rect r(7, 9);
    Circle c(7);

    //调用统一的接口，无虚函数开销
    r.print();
    c.print();

    return 0;
}

