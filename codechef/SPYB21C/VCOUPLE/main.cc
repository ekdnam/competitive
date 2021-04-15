// https://www.codechef.com/SPYB21C/problems/VCOUPLE
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
    long long int t, n, temp;

    cin >> t;
    while (t--)
    {
        vector<long long int> g, b, likeness;
        cin >> n;
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            g.push_back(temp);
        }
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        for (long long int i = 0; i < n; i++)
        {
            likeness.push_back(g[i] + b[n - i - 1]);
        }
        sort(likeness.begin(), likeness.end());
        cout << likeness[n - 1] << endl;
    }
    return 0;
}