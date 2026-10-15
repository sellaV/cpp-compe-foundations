#include <climits>
#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(merge_sorted({1,3,3},{2,3})==std::vector<int>({1,2,3,3,3}));CHECK(merge_sorted({},{}).empty());
        CHECK(merge_sorted({},{-2,4})==std::vector<int>({-2,4}));CHECK(merge_sorted({INT_MIN},{INT_MAX})==std::vector<int>({INT_MIN,INT_MAX}));
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
