#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        Inventory i;i.add("book",3);CHECK(!i.remove("book",4));CHECK(i.count("book")==3);CHECK(i.remove("book",2));CHECK(i.count("book")==1);
        Inventory copy=i;copy.add("book",2);CHECK(i.count("book")==1&&copy.count("book")==3);CHECK(!i.remove("missing",1));
        THROWS(i.add("",1),std::invalid_argument);i.add("large",INT_MAX);THROWS(i.add("large",1),std::overflow_error);CHECK(i.count("large")==INT_MAX);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
