#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(longest_alarm({1,7,8,2,9},5)==2);
CHECK(longest_alarm({},5)==0);
CHECK(longest_alarm({5,5},5)==0);
CHECK(longest_alarm({6,6,6},5)==3);
CHECK(longest_alarm({6,5,6},5)==1);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
