#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){try{for(int n=0;n<40;++n){std::vector<int>a;for(int i=0;i<n;++i)a.push_back(i/3-5);for(int target=-8;target<20;++target){std::size_t expected=0;while(expected<a.size()&&a[expected]<target)++expected;CHECK(first_at_least(a,target)==expected);}}return finish();}catch(const std::exception& e){std::cerr<<e.what();return 1;}}
