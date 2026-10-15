#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        const Fraction a(1,2),b(1,3);CHECK(a+b==Fraction(5,6));CHECK(a==Fraction(2,4));CHECK(a.numerator()==1&&a.denominator()==2);
        CHECK(Fraction(0,-3)==Fraction(0));CHECK(Fraction(-3,-9)==b);THROWS(Fraction(1,0),std::invalid_argument);
        auto copy=a;CHECK(copy+b==Fraction(5,6));CHECK(a==Fraction(1,2));
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
