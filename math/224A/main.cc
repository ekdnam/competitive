// link to the problem: https://codeforces.com/problemset/problem/224/A
// DONE
#include <iostream>
#include <algorithm>
#include <cmath>

int main(void)
{
    long long int s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    double a = pow((s1 * s3) / s2, 0.5);
    double b = pow((s1 * s2) / s3, 0.5);
    double c = pow((s2 * s3) / s1, 0.5);
    double ans = 4 * (a + b + c);
    std::cout << ans;
}