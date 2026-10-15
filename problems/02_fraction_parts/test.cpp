#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
auto a=normalize_fraction(6,-8);CHECK(a.valid&&a.numerator==-3&&a.denominator==4);
auto z=normalize_fraction(0,-9);CHECK(z.valid&&z.numerator==0&&z.denominator==1);
auto bad=normalize_fraction(1,0);CHECK(!bad.valid&&bad.numerator==0&&bad.denominator==1);
auto b=normalize_fraction(-3,-9);CHECK(b.valid&&b.numerator==1&&b.denominator==3);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
