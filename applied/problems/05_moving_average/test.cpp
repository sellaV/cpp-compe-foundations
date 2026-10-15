#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(near_vec(moving_average({1,3,5,7},2),{2,4,6})); CHECK(near_vec(moving_average({-2,2},2),{0}));
CHECK(near_vec(moving_average({1,2},1),{1,2})); CHECK(moving_average({},1).empty()); CHECK(moving_average({1},2).empty());
THROWS(moving_average({},0), std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
