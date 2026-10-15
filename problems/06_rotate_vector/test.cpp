#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
for(std::size_t n=0;n<10;++n)for(std::size_t k=0;k<25;++k){std::vector<int>v;for(std::size_t i=0;i<n;++i)v.push_back(static_cast<int>(i));rotate_right(v,k);CHECK(v.size()==n);for(std::size_t i=0;i<n;++i)CHECK(v[i]==static_cast<int>((i+n-k%n)%n));}
std::vector<int>x{1,2,3};rotate_right(x,1);CHECK(x==std::vector<int>({3,1,2}));
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
