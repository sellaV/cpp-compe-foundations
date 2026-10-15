#pragma once

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
class Fraction {
public:
    Fraction(long long,long long=1) {throw std::logic_error("TODO");}
    long long numerator() const {throw std::logic_error("TODO");}
    long long denominator() const {throw std::logic_error("TODO");}
    Fraction operator+(const Fraction&) const {throw std::logic_error("TODO");}
    bool operator==(const Fraction&) const {throw std::logic_error("TODO");}
};
