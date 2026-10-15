#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main() {
    try {
        CHECK(longest_unique("abcabcbb")==3);CHECK(longest_unique("abba")==2);CHECK(longest_unique("")==0);
        CHECK(longest_unique("bbbb")==1);CHECK(longest_unique("pwwkew")==3);CHECK(longest_unique("abcdef")==6);
        for(int code=0;code<729;++code) {
            int v=code;std::string text;
            for(int j=0;j<6;++j) {text.push_back(static_cast<char>('a'+v%3));v/=3;}
            std::size_t expected=0;
            for(std::size_t start=0;start<text.size();++start) {
                std::array<bool,256> seen{};
                for(std::size_t end=start;end<text.size();++end) {
                    auto byte=static_cast<unsigned char>(text[end]);
                    if(seen[byte])break;
                    seen[byte]=true;expected=std::max(expected,end-start+1);
                }
            }
            CHECK(longest_unique(text)==expected);
        }
        return finish();
    } catch (const std::exception& error) {
        std::cerr << "Uncaught exception: " << error.what() << '\n';
        return 1;
    }
}
