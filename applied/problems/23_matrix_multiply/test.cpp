#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(near_vec(matmul({1,2,3,4},{5,6,7,8},2,2,2),{19,22,43,50}));
CHECK(near_vec(matmul({1,2,3,4,5,6},{1,2,3},2,3,1),{14,32}));CHECK(near_vec(matmul({}, {},2,0,3),{0,0,0,0,0,0}));
CHECK(matmul({}, {},0,2,0).empty());THROWS(matmul({1},{1},2,1,1),std::invalid_argument);THROWS(matmul({}, {},-1,0,0),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
