// https://codeforces.com/problemset/problem/389/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int findGCD(vector<int> x, int n)
{
    int result = x.at(0);

    for (int i = 0; i < n; i++)
    {
        result = gcd(x.at(i), result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int main(void)
{
    int n;
    cin >> n;
    int v;

    int ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (i == 0)
            ans = v;
        else
            ans = gcd(ans, v);
    }

    cout << n * ans;

    return 0;
}