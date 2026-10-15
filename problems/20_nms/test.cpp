#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(nms({{0,0,2,2},{0,0,2,2}},{0.8,0.9},0.5)==std::vector<std::size_t>({1}));
CHECK(nms({{0,0,1,1},{2,2,3,3},{0,0,1,1}},{0.9,0.8,0.7},0.5)==std::vector<std::size_t>({0,1}));
CHECK(nms({{0,0,1,1},{0,0,1,1}},{1,1},1)==std::vector<std::size_t>({0,1}));CHECK(nms({{0,0,1,1},{0,0,1,1}},{1,1},0.5)==std::vector<std::size_t>({0}));
CHECK(nms({}, {},0.5).empty());THROWS(nms({{0,0,1,1}},{},0.5),std::invalid_argument);THROWS(nms({}, {},-1),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
