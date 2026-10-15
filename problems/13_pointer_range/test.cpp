#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
int a[]{1,2,3,4};CHECK(reverse_range(a,4));CHECK(a[0]==4&&a[1]==3&&a[2]==2&&a[3]==1);CHECK(reverse_range(nullptr,0));CHECK(!reverse_range(nullptr,1));int b[]{1};CHECK(reverse_range(b,1)&&b[0]==1);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
