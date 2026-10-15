#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        auto a=parse_value("int:42");CHECK(a&&std::holds_alternative<int>(*a)&&std::get<int>(*a)==42);
        auto b=parse_value("bool:false");CHECK(b&&std::holds_alternative<bool>(*b)&&!std::get<bool>(*b));auto c=parse_value("text:42");CHECK(c&&std::get<std::string>(*c)=="42");CHECK(std::get<std::string>(*parse_value("text:"))=="");
        for(auto s:{"int:","int:+1","int:2x","int:99999999999","bool:1","42"})CHECK(!parse_value(s));
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
