// https://www.codechef.com/APRIL21C/problems/BOLT
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
    long long int t;
    double k1, k2, k3, v, speed;
    double time = 9.58;
    int distance = 100;
    cin >> t;
    long long t_copy = t;
    vector<string> ans;
    while (t--)
    {
        cin >> k1 >> k2 >> k3 >> v;
        speed = k1 * k2 * k3 * v;
        double xx = distance/speed;
        double temp = round(xx * 100.0);
        temp = temp/100;
        if(temp < time){
            ans.push_back("YES");
        }
        else {
            ans.push_back("NO");
        }
        // cout << temp << "\n\n";
    }
    for(int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] << "\n";
    }
    cout << ans[ans.size() - 1];
    return 0;
}