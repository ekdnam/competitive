// https://www.codechef.com/APRIL21C/problems/SSCRIPT
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
    long long int t;
    vector<string> out;
    cin >> t;
    long long int k, n;
    string in;
    while (t--)
    {
        cin >> n >> k >> in;
        int count = 0, count_max = 0;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == '*')
            {
                count += 1;
                if (count > count_max)
                {
                    count_max = count;
                }
            }
            else
            {
                count = 0;
            }
        }
        ans = count_max >= k;
        if (ans)
        {
            out.push_back("YES");
        }
        else
        {
            out.push_back("NO");
        }
    }
    for (int i = 0; i < out.size() - 1; i++)
    {
        cout << out[i] << "\n";
    }
    cout << out[out.size() - 1];
}
