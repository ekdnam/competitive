// link to problem: https://codeforces.com/problemset/problem/149/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int k;
    cin >> k;
    vector<int> ai;
    int i = 0, temp;
    while (i < 12)
    {
        cin >> temp;
        ai.push_back(temp);
        i += 1;
    }
    if(k == 0){
        cout << 0;
        return 0;
    }
    sort(ai.begin(), ai.end(), greater<int>());
    int len = 0;
    int ans = 0;
    while (ans < 12)
    {
        len += ai.at(ans);
        if (len >= k)
        {
            break;
        }
        ans += 1;
    }
    if (len < k)
    {
        cout << -1;
    }
    else
    {
        cout << ans + 1;
    }
    return 0;
}