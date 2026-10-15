#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(second_largest({8,8,3,5}) == 5);
        CHECK(!second_largest({})); CHECK(!second_largest({4,4}));
        CHECK(second_largest({-4,-9,-4}) == -9);
        CHECK(second_largest({INT_MIN,INT_MAX}) == INT_MIN);
        for(int mask=0;mask<625;++mask) {
            std::vector<int> values;int code=mask;
            for(int j=0;j<4;++j) {values.push_back(code%5-2);code/=5;}
            auto sorted=values;std::sort(sorted.begin(),sorted.end());
            sorted.erase(std::unique(sorted.begin(),sorted.end()),sorted.end());
            std::optional<int> expected;
            if(sorted.size()>1)expected=sorted[sorted.size()-2];
            CHECK(second_largest(values)==expected);
        }
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
