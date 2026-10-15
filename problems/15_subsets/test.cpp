#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        auto a=subsets({1,2});std::sort(a.begin(),a.end());CHECK(a==std::vector<std::vector<int>>({{},{1},{1,2},{2}}));
        CHECK(subsets({})==std::vector<std::vector<int>>({{}}));auto b=subsets({1,2,3,4});std::sort(b.begin(),b.end());CHECK(b.size()==16);CHECK(std::adjacent_find(b.begin(),b.end())==b.end());
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
