#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(parse_command("CMD:-42")==-42); CHECK(parse_command("CMD:0007")==7);
for(auto s : {"CMD:","cmd:3","CMD: 3","CMD:3x","CMD:+3","CMD:999999999999","CMD:--1"}) CHECK(!parse_command(s));
CHECK(parse_command("CMD:-2147483648")==std::numeric_limits<int>::min());
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
