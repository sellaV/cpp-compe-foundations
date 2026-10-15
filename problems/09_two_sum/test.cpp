#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK((two_sum({4,2,4},8)==std::make_optional(std::make_pair(std::size_t{0},std::size_t{2}))));
CHECK(!two_sum({1,2},7)); CHECK(!two_sum({4},8));
CHECK((two_sum({3,3,3},6)==std::make_optional(std::make_pair(std::size_t{0},std::size_t{1}))));
CHECK(two_sum({2147483647,2147483647},4294967294LL).has_value());
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
