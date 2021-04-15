// https://www.codechef.com/APRIL21C/problems/SDICE
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
    long long int t, n, ans, temp;
    cin >> t;
    vector<long long int> out;
    while (t--)
    {
        cin >> n;
        if (n % 4 == 0)
        {
            temp = n / 4;
            ans = temp * 14 + 24;
        }
        else if(n%4 == 1){
            
        }
    }

    for (int i = 0; i < out.size() - 1; i++)
    {
        cout << out[i] << endl;
    }
    cout << out[out.size() - 1];
    return 0;
}