#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(near(iou({0,0,2,2},{1,1,3,3}),1.0/7));CHECK(near(iou({0,0,2,2},{0,0,2,2}),1));
CHECK(near(iou({0,0,1,1},{1,0,2,1}),0));CHECK(near(iou({0,0,0,0},{0,0,0,0}),0));
THROWS(iou({2,0,1,1},{0,0,1,1}),std::invalid_argument);CHECK(near(iou({0,0,4,4},{1,1,2,2}),1.0/16));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
