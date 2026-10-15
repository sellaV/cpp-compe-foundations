#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
auto a=first_unique("swiss");CHECK(a.found&&a.index==1);auto b=first_unique("aabb");CHECK(!b.found&&b.index==0);CHECK(!first_unique("").found);
std::string s;s.push_back(static_cast<char>(255));s.push_back('a');s.push_back('a');CHECK(first_unique(s).found&&first_unique(s).index==0);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
