#pragma once

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
class Shape {
public:
    virtual ~Shape()=default;
    virtual double area() const=0;
};
class Rectangle:public Shape {
public:
    Rectangle(double,double) {}
    double area() const override {throw std::logic_error("TODO");}
};
class Square:public Shape {
public:
    explicit Square(double) {}
    double area() const override {throw std::logic_error("TODO");}
};
inline double total_area(const Shape&,const Shape&) {throw std::logic_error("TODO");}
