#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
auto a=map_values(std::vector<int>{1,2,3},[](int x){return x*0.5;});static_assert(std::is_same_v<decltype(a),std::vector<double>>);CHECK(near_vec(a,{0.5,1,1.5}));
int calls=0;auto b=map_values(std::vector<int>{},[&](int x){++calls;return x;});CHECK(b.empty()&&calls==0);
auto c=map_values(std::vector<std::string>{"abc","d"},[](const auto& s){return s.size();});CHECK(c==std::vector<std::size_t>({3,1}));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
