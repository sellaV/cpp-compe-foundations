#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
int a[]{2,7,7};int* p=max_element_ptr(a,3);CHECK(p==a+1);*p=9;CHECK(a[1]==9);const int b[]{-2,-1};const int* q=max_element_ptr(b,2);CHECK(q==b+1);CHECK(max_element_ptr(static_cast<int*>(nullptr),0)==nullptr);CHECK(max_element_ptr(a,0)==nullptr);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
