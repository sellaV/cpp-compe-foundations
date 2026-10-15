#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
CHECK(contains_recursive({1,3,3,8},3));CHECK(!contains_recursive({},1));CHECK(!contains_recursive({1,3},2));CHECK(contains_recursive({1},1));CHECK(!contains_recursive({1},0));
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
