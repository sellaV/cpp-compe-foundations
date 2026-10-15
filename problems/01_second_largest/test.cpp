#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
auto a=second_largest({8,8,3,5});CHECK(a.found&&a.value==5);
auto b=second_largest({1,0});CHECK(b.found&&b.value==0);
auto c=second_largest({7,7});CHECK(!c.found&&c.value==0);
CHECK(!second_largest({}).found);auto d=second_largest({INT_MIN,INT_MAX});CHECK(d.found&&d.value==INT_MIN);
for(int code=0;code<625;++code){int n=code;std::vector<int>v;for(int i=0;i<4;++i){v.push_back(n%5-2);n/=5;}
 bool found=false;int expected=0;
 for(int x:v){bool bigger=false;int distinct_bigger=0;for(int y:v)if(y>x){if(!bigger){bigger=true;distinct_bigger=y;}else if(y!=distinct_bigger){distinct_bigger=99;break;}}
 if(bigger&&distinct_bigger!=99){found=true;expected=x;break;}}
 auto actual=second_largest(v);CHECK(actual.found==found);if(found)CHECK(actual.value==expected); }
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
