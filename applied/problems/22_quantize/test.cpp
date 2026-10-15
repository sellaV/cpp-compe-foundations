#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(quantize({-1,0,1},0.5,0)==std::vector<std::int8_t>({-2,0,2}));CHECK(quantize({-1e5,1e5},1,0)==std::vector<std::int8_t>({-128,127}));
CHECK(quantize({-0.5,0.5},1,3)==std::vector<std::int8_t>({2,4}));CHECK(quantize({},1,0).empty());
THROWS(quantize({},0,0),std::invalid_argument);THROWS(quantize({},1,128),std::invalid_argument);THROWS(quantize({std::numeric_limits<double>::quiet_NaN()},1,0),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
