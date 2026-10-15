#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(filter_samples({-2,4,9,4},0,5) == std::vector<int>({4,4}));
CHECK(filter_samples({},0,1).empty());
CHECK(filter_samples({2,2},2,2) == std::vector<int>({2,2}));
THROWS(filter_samples({},3,2), std::invalid_argument);
const std::vector<int> a{-1,0,1}; auto b=filter_samples(a,-1,0); CHECK(a==std::vector<int>({-1,0,1})); CHECK(b.size()==2);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
