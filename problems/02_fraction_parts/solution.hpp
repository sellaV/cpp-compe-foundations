#pragma once

struct FractionParts { bool valid; long long numerator,denominator; };
inline FractionParts normalize_fraction(long long n,long long d) {
if (d==0) return {false,0,1};
if (d<0) {n=-n;d=-d;}
long long a=n<0?-n:n,b=d;
while (b!=0) {long long remainder=a%b;a=b;b=remainder;}
return {true,n/a,d/a};
}
