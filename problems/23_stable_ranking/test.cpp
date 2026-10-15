#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        const std::vector<Record>a{{"A",10},{"B",20},{"C",10}};auto r=ranked(a);CHECK(r.size()==3&&r[0].name=="B"&&r[1].name=="A"&&r[2].name=="C");CHECK(a[0].name=="A");CHECK(ranked({}).empty());
        auto t=ranked({{"x",INT_MIN},{"y",INT_MAX}});CHECK(t[0].name=="y");
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
