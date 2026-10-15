#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
Controller c;CHECK(c.state()==State::Idle);c.handle(Event::Stop);CHECK(c.state()==State::Idle);c.handle(Event::Start);CHECK(c.state()==State::Running);c.handle(Event::Reset);CHECK(c.state()==State::Running);c.handle(Event::Fault);c.handle(Event::Start);c.handle(Event::Stop);CHECK(c.state()==State::Emergency);c.handle(Event::Reset);CHECK(c.state()==State::Idle);
for(auto initial:{State::Idle,State::Running,State::Emergency})for(auto e:{Event::Start,Event::Stop,Event::Fault,Event::Reset}){Controller x;if(initial==State::Running)x.handle(Event::Start);if(initial==State::Emergency)x.handle(Event::Fault);x.handle(e);State expected=initial;if(e==Event::Fault)expected=State::Emergency;else if(initial==State::Idle&&e==Event::Start)expected=State::Running;else if(initial==State::Running&&e==Event::Stop)expected=State::Idle;else if(initial==State::Emergency&&e==Event::Reset)expected=State::Idle;CHECK(x.state()==expected);}
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
