/*************************************************************************
	> File Name: 226快速幂.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年08月13日 星期二 11时31分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int mod;
typedef long long ll;
int Fast_Pow (int base , int times) {
    int  ret = 1;
    while(times) {
        if (times & 1) ret = (ll) ret *base;
        times >>= 1;
        base = (ll) base *base %mod;226快速幂.cpp
    }
    return ret % mod;
}

int main() {
    int a,b;
    cin  >>a >> b >> mod;
    cout << Fast_Pow(a,b) << endl;
    return 0;
}
