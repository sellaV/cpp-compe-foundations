#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(first_unique("swiss")==1);CHECK(!first_unique("aabb"));CHECK(!first_unique(""));
        std::string s; s.push_back(static_cast<char>(255));s.push_back('x');s.push_back('x');CHECK(first_unique(s)==0);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
