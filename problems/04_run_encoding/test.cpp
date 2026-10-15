#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        auto r=encode_runs("aaabbA");CHECK(r.size()==3);CHECK(r[0].value=='a'&&r[0].count==3);CHECK(r[2].value=='A'&&r[2].count==1);
        CHECK(encode_runs("").empty());auto s=encode_runs(" a a");CHECK(s.size()==4);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
