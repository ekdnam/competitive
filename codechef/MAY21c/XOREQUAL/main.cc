// https://www.codechef.com/MAY21C/problems/XOREQUAL
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
using namespace std;

#define ull unsigned long long
#define MODULO 1000000007


ull PowMod(ull n)
{
    ull ret = 1;
    ull a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(void)
{
    unsigned long long int T, N, ans;
    unsigned long long modulo_value = 1000000000 + 7;
    cin >> T;
    vector<long long> out;
    long long t_copy = T;
    while (T--)
    {
        ans = 1;
        cin >> N;
        N = N -1;
        ans = PowMod(N);
        // out.push_back(ans);
        cout << ans << endl;
    }
    // for (long long i : out)
    // {
    //     cout << i << endl;
    // }
    return 0;
}