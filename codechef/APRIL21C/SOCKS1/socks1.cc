// https://www.codechef.com/APRIL21C/problems/SOCKS1
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
    vector<int> x;
    int i = 2, temp = 0;
    cin >> temp;
    x.push_back(temp);
    cin >> temp;
    x.push_back(temp);
    cin >> temp;
    x.push_back(temp);
    sort(x.begin(), x.end());
    if(x[0] == x[1] || x[0] == x[2]){
        cout << "YES";
    }
    else if(x[1] == x[2]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}