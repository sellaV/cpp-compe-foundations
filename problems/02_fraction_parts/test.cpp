#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        auto a=normalize_fraction(6,-8); CHECK(a.numerator==-3 && a.denominator==4);
        auto z=normalize_fraction(0,-9); CHECK(z.numerator==0 && z.denominator==1);
        auto b=normalize_fraction(-3,-9); CHECK(b.numerator==1 && b.denominator==3);
        THROWS(normalize_fraction(1,0),std::invalid_argument);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
