#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
auto a=subsets({1,2});CHECK(a.size()==4);for(const auto& expected:std::vector<std::vector<int>>{{},{1},{2},{1,2}}){int count=0;for(const auto& actual:a)if(actual==expected)++count;CHECK(count==1);}CHECK(subsets({})==std::vector<std::vector<int>>({{}}));CHECK(subsets({1,2,3,4}).size()==16);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
