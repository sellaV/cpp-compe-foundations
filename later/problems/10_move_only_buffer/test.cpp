#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        static_assert(!std::is_copy_constructible_v<IntBuffer>);static_assert(!std::is_copy_assignable_v<IntBuffer>);static_assert(std::is_nothrow_move_constructible_v<IntBuffer>);static_assert(std::is_nothrow_move_assignable_v<IntBuffer>);
        IntBuffer a(2);CHECK(a.at(0)==0&&a.at(1)==0);a.at(0)=7;auto* address=&a.at(0);IntBuffer b(std::move(a));CHECK(a.size()==0&&b.size()==2);CHECK(&b.at(0)==address&&b.at(0)==7);THROWS(a.at(0),std::out_of_range);
        IntBuffer c(3);c=std::move(b);CHECK(b.size()==0&&c.at(0)==7);auto* alias=&c;c=std::move(*alias);CHECK(c.size()==2&&c.at(0)==7);const auto& view=c;static_assert(std::is_same_v<decltype(view.at(0)),const int&>);THROWS(view.at(2),std::out_of_range);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
