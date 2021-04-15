// https://www.codechef.com/SPYB21C/problems/SAVWATER
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
    cin >> t;
    int H, x, y, c, half_greywater, total, gwater, water_per_household;
    while (t--)
    {
        cin >> H >> x >> y >> c;
        half_greywater = y / 2;
        water_per_household = half_greywater + x;
        total = water_per_household * H;
        if (total > c)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}