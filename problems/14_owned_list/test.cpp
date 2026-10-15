#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        std::unique_ptr<Node> head;insert_sorted(head,3);auto* original=head.get();insert_sorted(head,1);insert_sorted(head,3);insert_sorted(head,2);
        CHECK(head->value==1&&head->next->value==2&&head->next->next.get()==original);
        CHECK(original->next->value==3&&!original->next->next);
        insert_sorted(head,9);CHECK(original->next->next->value==9);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
