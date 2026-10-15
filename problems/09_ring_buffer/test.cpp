#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
THROWS(RingBuffer<int>(0),std::invalid_argument); RingBuffer<int> r(2); CHECK(!r.pop()); r.push(1);r.push(2);r.push(3);CHECK(r.size()==2);CHECK(r.pop()==2);CHECK(r.pop()==3);CHECK(!r.pop());
r.push(4);CHECK(r.pop()==4); RingBuffer<std::string>s(1);s.push("a");s.push("b");CHECK(s.pop()=="b");
struct Item{int n;explicit Item(int x):n(x){}};RingBuffer<Item> q(1);q.push(Item{7});CHECK(q.pop()->n==7);
// Compare repeated overwrites, pops and wraparound with a simple FIFO model.
for(std::size_t capacity=1;capacity<=8;++capacity) {
    RingBuffer<int> buffer(capacity);
    std::vector<int> model;
    for(int step=0;step<200;++step) {
        if(step%3==0) {
            auto actual=buffer.pop();
            if(model.empty()) CHECK(!actual);
            else {CHECK(actual==model.front());model.erase(model.begin());}
        } else {
            buffer.push(step);
            if(model.size()==capacity) model.erase(model.begin());
            model.push_back(step);
        }
        CHECK(buffer.size()==model.size());
    }
}
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
