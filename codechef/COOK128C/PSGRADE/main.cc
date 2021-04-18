// https://www.codechef.com/COOK128C/problems/PSGRADE
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
    long long int t, t_copy, a, b, c, a_min, b_min, c_min, t_min;
    bool out;
    cin >> t;
    t_copy = t;
    vector<string> out_vec;
    while (t--)
    {
        out = true;
        cin >> a_min >> b_min >> c_min >> t_min >> a >> b >> c;
        if (a < a_min)
        {
            out = false;
        }
        if (b < b_min)
        {
            out = false;
        }
        if (c < c_min)
        {
            out = false;
        }
        if (a + b + c < t_min)
        {
            out = false;
        }
        if (out)
        {
            // cout << "YES" << endl;
            out_vec.push_back("YES");
        }
        else
        {
            // cout << "NO" << endl;
            out_vec.push_back("NO");
        }
    }
    for (long long int i = 0; i < t_copy - 1; i++)
    {
        cout << out_vec[i] << endl;
    }
    cout << out_vec[t_copy - 1];
    return 0;
}