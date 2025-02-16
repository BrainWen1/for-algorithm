//倍增思想
#include <iostream>

//[模板]快速幂
long long FastPower(long long a, long long b)
{
    long long ret = 1;
    while(b) {
        if(b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

//[模板]快速幂模
long long FastPower_modulo(long long a, long long b, long long p)
{
    long long ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

//[模板]快速乘
long long FastMultiply(long long a, long long b)
{
    long long ret = 0;
    while(b) {
        if(b & 1) ret = ret + a;
        a = a + a;
        b >>= 1;
    }
    return ret;
}

//[模板]快速乘模
long long FastMultiply(long long a, long long b, long long p)
{
    long long ret = 0;
    while(b) {
        if(b & 1) ret = (ret + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ret;
}