#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(normalize_spaces("  one\ttwo  ")=="one two");CHECK(normalize_spaces("\r\n\f\v").empty());
        CHECK(normalize_spaces("a")=="a");CHECK(normalize_spaces("").empty());CHECK(normalize_spaces(" a  b\nc ")=="a b c");
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
