#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(balanced_brackets("{[()]}"));CHECK(!balanced_brackets("([)]"));CHECK(balanced_brackets(""));
        CHECK(!balanced_brackets(")("));CHECK(!balanced_brackets("(("));CHECK(balanced_brackets("()[]{}"));
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
