#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
CHECK(shortest_grid_path({{0,1},{0,0}})==2);CHECK(shortest_grid_path({{0}})==0);CHECK(shortest_grid_path({{1}})==-1);
CHECK(shortest_grid_path({{0,1},{1,0}})==-1);CHECK(shortest_grid_path({})==-1);CHECK(shortest_grid_path({{}})==-1);
CHECK(shortest_grid_path({{0,0,0},{1,1,0},{0,0,0}})==4);THROWS(shortest_grid_path({{0},{0,0}}),std::invalid_argument);
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
