#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        std::istringstream a("12 -3 004");CHECK(read_integers(a)==std::vector<int>({12,-3,4}));std::istringstream b(" ");CHECK(read_integers(b).empty());
        for(auto s:{"12 3x","99999999999","+1","-"}){std::istringstream in(s);THROWS(read_integers(in),std::invalid_argument);}
        std::istringstream broken;broken.setstate(std::ios::badbit);THROWS(read_integers(broken),std::runtime_error);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
