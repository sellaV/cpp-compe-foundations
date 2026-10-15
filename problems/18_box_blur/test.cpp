#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(near_vec(blur3({1,2,3,4},2,2),{2.5,2.5,2.5,2.5}));CHECK(near_vec(blur3({9},1,1),{9}));CHECK(blur3({},0,3).empty());
auto a=blur3({1,2,3,4,5,6,7,8,9},3,3);CHECK(near(a[0],3));CHECK(near(a[4],5));CHECK(near(a[8],7));
THROWS(blur3({1},2,2),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
