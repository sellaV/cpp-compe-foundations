#include <climits>
#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        int a=1,b=2,c=3; rotate_values(a,b,c); CHECK(a==3 && b==1 && c==2);
        rotate_values(a,b,c);rotate_values(a,b,c);CHECK(a==1&&b==2&&c==3);
        int x=INT_MIN,y=0,z=INT_MAX;rotate_values(x,y,z);CHECK(x==INT_MAX&&y==INT_MIN&&z==0);
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
