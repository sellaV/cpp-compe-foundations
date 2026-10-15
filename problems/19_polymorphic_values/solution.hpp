#pragma once

class Shape {
public:
    virtual ~Shape()=default;
    virtual double area() const=0;
};
class Rectangle:public Shape {
    double width_,height_;
public:
    Rectangle(double w,double h):width_(w),height_(h) {}
    double area() const override {return width_*height_;}
};
class Square:public Shape {
    double side_;
public:
    explicit Square(double side):side_(side) {}
    double area() const override {return side_*side_;}
};
inline double total_area(const Shape& a,const Shape& b) {return a.area()+b.area();}
