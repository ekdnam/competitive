// https://www.codechef.com/COOK128C/problems/CM164364
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
using namespace std;

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{

    // If frequency is same then sort by index
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

long long sortByFreq(vector<long long int> a, long long int n, long long int x)
// vector<long long int> sortByFreq(long long int a[], long long int n, long long int x)
{

    vector<long long int> res;

    unordered_map<long long int, long long int> m;

    vector<pair<long long int, long long int>> v;

    vector<long long int> freq;

    for (long long int i = 0; i < n; ++i)
    {

        // Map m is used to keep track of count
        // of elements in array
        m[a[i]]++;
    }

    // Copy map to vector
    copy(m.begin(), m.end(), back_inserter(v));

    // Sort the element of array by frequency
    sort(v.begin(), v.end(), sortByVal);

    for (long long int i = 0; i < v.size(); ++i)
    {
        freq.push_back(v[i].second);
        while (v[i].second--)
        {
            res.push_back(v[i].first);
        }
    }
    bool exit = true;
    long long int out_val = 0;
    long long hop_counter = 5;
    while (exit)
    {
        for (long long int i = 0; i < freq.size(); i++)
        {
            if (freq[i] <= 0)
            {
                continue;
            }
            if (x <= 0)
            {
                exit = false;
                break;
            }
            else
            {
                freq[i] -= 1;
                x -= 1;
            }
        }
    }
    for (long long int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > 0)
        {
            out_val += 1;
        }
    }
    // cout << "OUT: " << out_val << endl;
    cout << out_val << endl;
    return out_val;
}

int main(void)
{
    long long int t, t_copy, n, x, temp, temp2 = 0;
    cin >> t;
    t_copy = t;
    vector<long long int> out;
    while (t--)
    {
        vector<long long int> a;
        cin >> n >> x;
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        temp2 = sortByFreq(a, n, x);
    }
}