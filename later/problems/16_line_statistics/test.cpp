#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        std::istringstream a("a\n\nbb\n");auto s=summarize_lines(a);CHECK(s.lines==3&&s.nonempty==2&&s.max_length==2);
        std::istringstream b("a\r\nlast");auto t=summarize_lines(b);CHECK(t.lines==2&&t.max_length==4);std::istringstream empty("");CHECK(summarize_lines(empty).lines==0);
        std::ostringstream out;out<<std::hex;auto flags=out.flags();write_stats(out,{12,10,15});CHECK(out.str()=="lines=12;nonempty=10;max=15\n");CHECK(out.flags()==flags);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
