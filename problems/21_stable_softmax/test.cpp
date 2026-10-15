#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(near_vec(softmax({1000,1000}),{0.5,0.5}));CHECK(softmax({}).empty());CHECK(near_vec(softmax({-7}),{1}));
auto p=softmax({1,2,3});auto q=softmax({1001,1002,1003});CHECK(near_vec(p,q));CHECK(near(std::accumulate(p.begin(),p.end(),0.0),1));CHECK(p[0]<p[1]&&p[1]<p[2]);
THROWS(softmax({std::numeric_limits<double>::infinity()}),std::invalid_argument);CHECK(near_vec(softmax({-1e6,1e6}),{0,1}));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
