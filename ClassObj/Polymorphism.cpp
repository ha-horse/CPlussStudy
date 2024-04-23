#include <iostream>
#include <math.h>

/*多态性：一个接口，多种方法*/

//抽象类
class Figure{
private:
    /* data */
public:
    //纯虚函数
    virtual double getArea() = 0;
};

//Figure的派生类Rectangle
class Rectangle : public Figure{
protected:
    double height;
    double width;
public:
    Rectangle(){};
    Rectangle(double height, double width){
        this->height = height;
        this->width = width;
    }
    double getArea(){
        return height * width;
    }
};

class Square : public Rectangle{
public:
    Square(double width){
        this->height = this->width = width;
    }
};

//Figure的派生类Triangle
class Triangle : public Figure{
private:
    double la;
    double lb;
    double lc;
public:
    Triangle(double la, double lb, double lc){
        this->la = la;
        this->lb = lb;
        this->lc = lc;
    }
    double getArea(){
        double s = (la + lb + lc) / 2.0;
        return sqrt(s * (s - la) * (s - lb) * (s - lc));
    }
};

void main(){
    Figure *figure[3] = {
        new Triangle(2, 3, 3),
        new Rectangle(5, 8),
        new Square(5)
        };
    for (int i = 0; i < 3; i++){
        std::cout << "figures[" << i << "] area = " << figure[i]->getArea() << std::endl; 
    }
    
}
