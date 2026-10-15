#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
Rectangle r(2,3);Square s(4);const Shape& base=r;CHECK(near(base.area(),6));CHECK(near(total_area(r,s),22));Square zero(0);CHECK(near(total_area(zero,s),16));
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
