#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
std::vector<int>a{3,1,3,2,1};remove_duplicates(a);CHECK(a==std::vector<int>({3,1,2}));std::vector<int>b;remove_duplicates(b);CHECK(b.empty());std::vector<int>c{0,0,-1,-1};remove_duplicates(c);CHECK(c==std::vector<int>({0,-1}));
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
