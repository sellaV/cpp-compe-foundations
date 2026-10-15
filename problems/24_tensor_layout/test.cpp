#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
auto x=to_chw({255,0,128,0,255,64},1,2);CHECK(x.size()==6);CHECK(near(x[0],1)&&near(x[1],0)&&near(x[2],0)&&near(x[3],1));CHECK(near(x[4],128.0/255,1e-6)&&near(x[5],64.0/255,1e-6));
CHECK(to_chw({},0,5).empty());THROWS(to_chw({0},1,1),std::invalid_argument);
auto y=to_chw({1,2,3,4,5,6,7,8,9,10,11,12},2,2);CHECK(near(y[3],10.0/255,1e-6)&&near(y[4],2.0/255,1e-6)&&near(y[11],12.0/255,1e-6));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
