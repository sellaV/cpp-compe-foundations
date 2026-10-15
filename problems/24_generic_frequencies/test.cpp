#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        std::list<int>a{3,1,3};auto r=frequencies(a.cbegin(),a.cend());CHECK((r==std::map<int,std::size_t>{{1,1},{3,2}}));
        std::string s="aba";CHECK((frequencies(s.begin(),s.end())==std::map<char,std::size_t>{{'a',2},{'b',1}}));CHECK(frequencies(a.begin(),a.begin()).empty());
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
