#pragma once
#include <cmath>
#include <exception>
#include <iostream>
#include <vector>
inline int failures=0;
inline int checks=0;
inline void check(bool ok,const char* expression,int line){
    ++checks;
    if(!ok){++failures;std::cerr<<"FAIL line "<<line<<": "<<expression<<'\n';}
}
#define CHECK(...) check((__VA_ARGS__), #__VA_ARGS__, __LINE__)
#define THROWS(expr, exception_type) do { \
    bool caught_expected=false; \
    try{ (void)(expr); }catch(const exception_type&){caught_expected=true;}catch(...){ } \
    CHECK(caught_expected); \
} while(false)
inline bool near(double a,double b,double eps=1e-8){return std::isfinite(a)&&std::isfinite(b)&&std::abs(a-b)<=eps;}
inline bool near_vec(const std::vector<double>& a,const std::vector<double>& b){
    if(a.size()!=b.size())return false;
    for(std::size_t i=0;i<a.size();++i)if(!near(a[i],b[i]))return false;
    return true;
}
inline int finish(){
    std::cout<<(failures==0?"PASS: ":"FAIL: ")<<checks<<" checks, "<<failures<<" failures\n";
    return failures==0?0:1;
}
