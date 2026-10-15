#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
FixedQueue q;int out=99;CHECK(!q.pop(out)&&out==99);for(int i=0;i<8;++i)CHECK(q.push(i));CHECK(!q.push(100));CHECK(q.size()==8);for(int i=0;i<4;++i){CHECK(q.pop(out));CHECK(out==i);}for(int i=8;i<12;++i)CHECK(q.push(i));for(int i=4;i<12;++i){CHECK(q.pop(out));CHECK(out==i);}CHECK(q.size()==0);q.push(7);FixedQueue c=q;CHECK(c.pop(out)&&out==7);CHECK(q.size()==1);
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
