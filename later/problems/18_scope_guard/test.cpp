#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        static_assert(!std::is_copy_constructible_v<FormatGuard>);static_assert(!std::is_move_constructible_v<FormatGuard>);
        std::ostringstream out;auto flags=out.flags();auto precision=out.precision();
        try {FormatGuard guard(out);out<<std::fixed<<std::setprecision(2);{FormatGuard inner(out);out<<std::scientific<<std::setprecision(4);}CHECK(out.precision()==2);throw std::runtime_error("test");}catch(const std::runtime_error&){}
        CHECK(out.flags()==flags&&out.precision()==precision);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
