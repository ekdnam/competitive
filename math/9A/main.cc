// https://codeforces.com/contest/9/problem/A
// DONE
#include <iostream>
#include <cmath>
#include <algorithm>

int maximum(int a, int b)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    return max;
}
int main(void)
{
    int Y, W;
    std::cin >> Y >> W;
    int max(maximum(Y, W));
    int diff = 6 - max + 1;
    if (diff == 1)
    {
        std::cout << "1/6";
    }
    else if (diff == 2)
    {
        std::cout << "1/3";
    }
    else if (diff == 3)
    {
        std::cout << "1/2";
    }
    else if (diff == 4)
    {
        std::cout << "2/3";
    }
    else if (diff == 5)
    {
        std::cout << "5/6";
    }
    else if (diff == 6)
    {
        std::cout << "1/1";
    }
    return 0;
}