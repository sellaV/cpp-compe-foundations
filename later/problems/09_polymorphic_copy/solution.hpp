#pragma once
#include <algorithm>
#include <array>
#include <charconv>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

class Shape {
public:
    virtual ~Shape()=default;
    virtual double area() const=0;
    virtual std::unique_ptr<Shape> clone() const=0;
};
class Rectangle : public Shape {
    double width_,height_;
public:
    Rectangle(double w,double h):width_(w),height_(h) {
        if (!std::isfinite(w)||!std::isfinite(h)||w<0||h<0) throw std::invalid_argument("dimension");
    }
    double area() const override { return width_*height_; }
    std::unique_ptr<Shape> clone() const override { return std::make_unique<Rectangle>(*this); }
};
class Square : public Shape {
    double side_;
public:
    explicit Square(double s):side_(s) {
        if (!std::isfinite(s)||s<0) throw std::invalid_argument("dimension");
    }
    double area() const override { return side_*side_; }
    std::unique_ptr<Shape> clone() const override { return std::make_unique<Square>(*this); }
};
