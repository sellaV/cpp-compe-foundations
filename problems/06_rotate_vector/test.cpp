#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        std::vector<int>a{1,2,3,4,5};rotate_right(a,2);CHECK(a==std::vector<int>({4,5,1,2,3}));
        rotate_right(a,5);CHECK(a==std::vector<int>({4,5,1,2,3}));std::vector<int>b;rotate_right(b,99);CHECK(b.empty());
        std::vector<int>c{1,2};rotate_right(c,5);CHECK(c==std::vector<int>({2,1}));
        for(std::size_t n=0;n<10;++n)for(std::size_t k=0;k<25;++k) {
            std::vector<int> values(n);std::iota(values.begin(),values.end(),0);
            auto expected=values;
            if(n>0)std::rotate(expected.begin(),expected.end()-static_cast<std::ptrdiff_t>(k%n),expected.end());
            rotate_right(values,k);CHECK(values==expected);
        }
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
