#pragma once

class Fraction {
long long numerator_,denominator_;
public:
    Fraction(long long n,long long d=1):numerator_(n),denominator_(d) {
        if (denominator_<0) {numerator_=-numerator_;denominator_=-denominator_;}
        long long a=numerator_<0?-numerator_:numerator_,b=denominator_;
        while (b!=0) {long long remainder=a%b;a=b;b=remainder;}
        numerator_/=a;denominator_/=a;
    }
    long long numerator() const {return numerator_;}
    long long denominator() const {return denominator_;}
    Fraction operator+(const Fraction& other) const {return Fraction(numerator_*other.denominator_+other.numerator_*denominator_,denominator_*other.denominator_);}
    bool operator==(const Fraction& other) const {return numerator_==other.numerator_&&denominator_==other.denominator_;}
};
