#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        int a[]{1,2,3,4};reverse_range(a,4);CHECK(std::vector<int>(a,a+4)==std::vector<int>({4,3,2,1}));
        reverse_range(nullptr,0);THROWS(reverse_range(nullptr,1),std::invalid_argument);int b[]{1,2,3};reverse_range(b,3);CHECK(b[0]==3&&b[1]==2&&b[2]==1);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
