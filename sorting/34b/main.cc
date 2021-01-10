// problem link: https://codeforces.com/problemset/problem/34/B
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ai;
    int i = 0;
    int temp;
    while (i < n)
    {
        std::cin >> temp;
        ai.push_back(temp);
        i += 1;
    }
    std::sort(ai.begin(), ai.end());
    int ans = 0, lastPos = 0, ansPrev = -1;
    if (ai.at(0) >= 0)
    {
        std::cout << 0;
        return 0;
    }
    if (m < n)
    {
        while (lastPos <= m && lastPos < n)
        {
            ansPrev = ans;

            ans += -1 * ai.at(lastPos);

            if (ans < ansPrev)
            {
                break;
            }

            lastPos += 1;
        }

        std::cout << ansPrev;

        return 0;
    }
    else if (m == n)
    {
        ans = 0, lastPos = 0, ansPrev = -1;
        // ans = 0, ansPrev = ai.at(0);
        int second_counter = m;
        while (second_counter >= -1)
        {
            ansPrev = ans;

            ans += -1 * ai.at(lastPos);

            if (ans < ansPrev)
            {
                break;
            }

            lastPos += 1;
            second_counter -= 1;
        }
        std::cout << ansPrev;
        return 0;
    }
    return 0;
}