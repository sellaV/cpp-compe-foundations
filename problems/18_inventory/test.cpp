#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
#include <climits>
int main(){try{
Inventory i;CHECK(i.add("book",3));CHECK(!i.remove("book",4));CHECK(i.count("book")==3);CHECK(i.remove("book",2));CHECK(i.count("book")==1);Inventory c=i;CHECK(c.add("book",2));CHECK(i.count("book")==1&&c.count("book")==3);CHECK(!i.add("",1));CHECK(!i.add("book",0));CHECK(i.add("full",1000000));CHECK(!i.add("full",1));CHECK(i.count("full")==1000000);CHECK(!i.remove("missing",1));
return finish();
}catch(const std::exception& e){std::cerr<<"Uncaught exception: "<<e.what()<<'\n';return 1;}}
