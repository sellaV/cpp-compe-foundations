#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(write_bit(10,0,true)==11); CHECK(write_bit(10,1,true)==10); CHECK(write_bit(10,1,false)==8);
CHECK(write_bit(0,31,true)==0x80000000u); CHECK(write_bit(0xffffffffu,31,false)==0x7fffffffu);
THROWS(write_bit(0,32,true),std::out_of_range);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
