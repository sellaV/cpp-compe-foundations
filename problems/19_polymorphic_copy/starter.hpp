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
public:
    Rectangle(double,double) { throw std::logic_error("TODO"); }
    double area() const override { throw std::logic_error("TODO"); }
    std::unique_ptr<Shape> clone() const override { throw std::logic_error("TODO"); }
};
class Square : public Shape {
public:
    explicit Square(double) { throw std::logic_error("TODO"); }
    double area() const override { throw std::logic_error("TODO"); }
    std::unique_ptr<Shape> clone() const override { throw std::logic_error("TODO"); }
};
