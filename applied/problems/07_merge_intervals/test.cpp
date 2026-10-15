#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
auto a=merge_intervals({{5,8},{1,3},{3,6}}); CHECK(a.size()==1); CHECK(a[0].start==1 && a[0].end==8);
CHECK(merge_intervals({}).empty()); auto b=merge_intervals({{1,1},{4,5}}); CHECK(b.size()==2);
auto c=merge_intervals({{1,10},{2,3}}); CHECK(c[0].end==10); THROWS(merge_intervals({{5,2}}),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
