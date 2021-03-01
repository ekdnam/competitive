// https://codeforces.com/problemset/problem/450/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
using namespace std;

int main(void)
{
    unsigned long long int x, y, n;
    cin >> x >> y >> n;
    unsigned long long int modulo_term = 1000000007;
    unsigned long long int n_copy = n;
    unsigned long long int f_1 = x, f_2 = y, f_n = 0;
    if (n <= 2)
    {
        // cout << "AMIHERE" << endl;
        unsigned long long int ans = 0;
        if (n == 1)
        {
            // cout << "CON 1" << endl;
            ans = f_1 % modulo_term;
        }
        else
        {
            // cout << "CON 2" << endl;
            ans = f_2 % modulo_term;
        }
        cout << ans;
        // cout << "EXIT" << endl;
        return 0;
    }
    n_copy -= 2;
    while (n_copy)
    {
        // cout << n_copy << endl;
        // cout << "f_n: " << f_n << " f_1: " << f_1 << " f_2: " << f_2 << endl;
        // f_n = (f_1 % modulo_term - f_2 % modulo_term) % modulo_term;
        f_n = f_1 - f_2;
        f_2 = f_1;
        f_1 = f_n;
        n_copy -= 1;
    }
    cout << "Final f_n: " << f_n << endl;
    // cout << f_n;
    cout << f_n % modulo_term;
    return 0;
}