#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        int a[]{2,7,7};auto p=max_element_ptr(a,3);CHECK(p==a+1);*p=9;CHECK(a[1]==9);
        const int b[]{-2,-1};static_assert(std::is_same_v<decltype(max_element_ptr(b,2)),const int*>);CHECK(max_element_ptr(b,2)==b+1);
        CHECK(max_element_ptr(static_cast<int*>(nullptr),0)==nullptr);THROWS(max_element_ptr(static_cast<const int*>(nullptr),1),std::invalid_argument);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
