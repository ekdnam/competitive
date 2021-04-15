// https://codeforces.com/problemset/problem/789/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;

bool isEmpty(vector<long long int> v)
{
    bool isEmpty = true;
    for (const long long int value : v)
    {
        if (value != 0)
        {
            isEmpty = false;
        }
    }
    return isEmpty;
}

int main(void)
{
    long long int n, k, temp, nPockets = 2, daysRequired = 0;
    cin >> n >> k;
    vector<long long int> wn;
    for (long long int i = 0; i < n; i++)
    {
        cin >> temp;
        wn.push_back(temp);
    }
    long long usablePockets = nPockets;
    sort(wn.begin(), wn.end());
    reverse(wn.begin(), wn.end());
    while (!isEmpty(wn))
    {
        usablePockets = nPockets;
        for (long long int range = 0; range < wn.size() && usablePockets != 0; range++)
        {
            if()
        }
    }
}