#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(crop({0,1,2,3,4,5},3,2,1,0,2,2)==std::vector<int>({1,2,4,5}));CHECK(crop({0,1},2,1,2,0,0,1).empty());
THROWS(crop({0,1},2,1,1,0,2,1),std::invalid_argument);THROWS(crop({0},2,1,0,0,1,1),std::invalid_argument);
CHECK(crop({},0,0,0,0,0,0).empty());THROWS(crop({},-1,0,0,0,0,0),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
