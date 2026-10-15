#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(group_anagrams({"eat","tea","tan","ate"})==std::vector<std::vector<std::string>>({{"eat","tea","ate"},{"tan"}}));
        CHECK(group_anagrams({}).empty());CHECK(group_anagrams({"","a",""})==std::vector<std::vector<std::string>>({{"",""},{"a"}}));CHECK(group_anagrams({"x","x"})==std::vector<std::vector<std::string>>({{"x","x"}}));
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
