// https://codeforces.com/problemset/problem/602/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;

int main(void)
{
    long long int nx, bx, ny, by, x = 0, y = 0, temp;
    vector<long long int> d_x, d_y;
    cin >> nx >> bx;
    for (long long i = 0; i < nx; i++)
    {
        cin >> temp;
        d_x.push_back(temp);
    }
    cin >> ny >> by;
    for (long long i = 0; i < ny; i++)
    {
        cin >> temp;
        d_y.push_back(temp);
    }
    reverse(d_x.begin(), d_x.end());
    reverse(d_y.begin(), d_y.end());
    for (long long i = 0; i < nx; i++)
    {
        x += d_x.at(i) * pow(bx, i);
    }
    for (long long i = 0; i < ny; i++)
    {
        y += d_y.at(i) * pow(by, i);
    }
    if (x > y)
    {
        cout << '>';
    }
    else if (x < y)
    {
        cout << '<';
    }
    else
    {
        cout << '=';
    }
    return 0;
}