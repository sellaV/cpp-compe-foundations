#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(task_order(3,{{0,2},{1,2}})==std::make_optional(std::vector<int>{0,1,2}));CHECK(!task_order(2,{{0,1},{1,0}}));
CHECK(task_order(0,{})->empty());CHECK(task_order(3,{{1,2},{1,2}})==std::make_optional(std::vector<int>{0,1,2}));
CHECK(!task_order(1,{{0,0}}));THROWS(task_order(2,{{0,2}}),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
