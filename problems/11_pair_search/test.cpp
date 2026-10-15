#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
auto a=find_pair({4,2,4},8);CHECK(a.found&&a.first==0&&a.second==2);CHECK(!find_pair({4},8).found);CHECK(!find_pair({},0).found);
auto b=find_pair({3,3,3},6);CHECK(b.found&&b.first==0&&b.second==1);CHECK(find_pair({INT_MAX,INT_MAX},4294967294LL).found);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
