// https://codeforces.com/contest/1512/problem/A
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
    long long int t, t_copy, n, temp;
    cin >> t;
    t_copy = t;
    vector<int> out;
    int curr_index, index;
    while (t--)
    {
        vector<long long int> in, in_temp;
        cin >> n;
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            in.push_back(temp);
            in_temp.push_back(temp);
        }
        sort(in_temp.begin(), in_temp.end());
        long long int temp2 = (in_temp[0] == in_temp[1]) ? in_temp[n - 1] : in_temp[0];
        auto it = find(in.begin(), in.end(), temp2);

        index = it - in.begin();
        out.push_back(index + 1);
    }
    for(long long int i = 0; i < t_copy - 1; i++){
        cout << out[i] << endl;
    }
    cout << out[t_copy - 1];
}