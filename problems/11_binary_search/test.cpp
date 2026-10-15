#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(first_at_least({1,3,3,8},3)==1); CHECK(first_at_least({},3)==0); CHECK(first_at_least({1,3},4)==2);
CHECK(first_at_least({1,3},0)==0); CHECK(first_at_least({3,3,3},3)==0);
for(int t=-2;t<=12;++t){std::vector<int>a{0,0,2,4,4,9}; CHECK(first_at_least(a,t)==static_cast<std::size_t>(std::lower_bound(a.begin(),a.end(),t)-a.begin()));}
// Exhaustively compare all targets for several sorted shapes.
for (int n=0;n<40;++n) {
    std::vector<int> values;
    for (int i=0;i<n;++i) values.push_back(i/3-5);
    for (int target=-8;target<20;++target) {
        const auto expected=std::lower_bound(values.begin(),values.end(),target);
        CHECK(first_at_least(values,target)==static_cast<std::size_t>(expected-values.begin()));
    }
}
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
