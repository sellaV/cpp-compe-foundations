#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
PID p(1,1,0,10);CHECK(near(p.step(2,1),4));CHECK(near(p.step(1,1),4));p.reset();CHECK(near(p.step(1,1),2));
PID d(0,0,1,100);CHECK(near(d.step(5,1),0));CHECK(near(d.step(7,0.5),4));
PID c(10,0,0,3);CHECK(near(c.step(-2,1),-3));THROWS(c.step(1,0),std::invalid_argument);THROWS(PID(1,1,1,-1),std::invalid_argument);
PID w(0,1,0,1);CHECK(near(w.step(10,1),1));CHECK(near(w.step(-1,1),1));
PID safe(0,0,1,100);safe.step(1,1);THROWS(safe.step(9,0),std::invalid_argument);CHECK(near(safe.step(2,1),1));
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
