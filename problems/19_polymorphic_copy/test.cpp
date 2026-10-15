#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        static_assert(std::has_virtual_destructor_v<Shape>);static_assert(std::is_abstract_v<Shape>);
        std::unique_ptr<Shape> p=std::make_unique<Rectangle>(2,3);auto q=p->clone();CHECK(near(p->area(),6));CHECK(q.get()!=p.get());CHECK(dynamic_cast<Rectangle*>(q.get())!=nullptr);p.reset();CHECK(near(q->area(),6));
        Square s(4);auto c=s.clone();CHECK(near(c->area(),16));CHECK(dynamic_cast<Square*>(c.get())!=nullptr);THROWS(Square(-1),std::invalid_argument);THROWS(Rectangle(2,-1),std::invalid_argument);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
