#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(chain_values(nullptr).empty());auto a=std::make_unique<Node>();a->value=7;a->next=std::make_unique<Node>();a->next->value=2;a->next->next=std::make_unique<Node>();a->next->next->value=9;
CHECK(chain_values(a.get())==std::vector<int>({7,2,9}));CHECK(a->next->value==2);CHECK(chain_values(a->next->next.get())==std::vector<int>({9}));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
