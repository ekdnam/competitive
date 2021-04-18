// https://www.codechef.com/COOK128C/problems/CM164364
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int main(void)
{
    long long int t, t_copy, n, x, temp, temp2 = 0;
    cin >> t;
    t_copy = t;
    vector<long long int> out;
    while (t--)
    {
        map<long long int, long long int> chocolateCount;
        vector<long long int> A;
        cin >> n >> x;
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            A.push_back(temp);
        }
        for (long long int a : A)
        {
            chocolateCount[a]++;
        }
        long long int extra = 0;
        for (auto i : chocolateCount)
        // for(long long int i = 0; i < chocolateCount.size)
        {
            if (i.second > 1)
            {
                extra += i.second - 1;
            }
        }
        // for(long long int i = 0; i < chocolateCount.size(); i++){
        //     if(chocolateCount[i] > 1){
        //         extra += chocolateCount[i] - 1;
        //     }
        // }
        if (extra >= x)
        {
            cout << chocolateCount.size() << endl;
        }
        else
        {
            long long int remaining = x - extra;
            cout << chocolateCount.size() - remaining << endl;
        }
    }
}