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
    long long int T, N, x, k;
    bool check;
    cin >> T;
    while (T--)
    {
        check = false;
        cin >> N >> x >> k;
        double forward_mod = x % k;
        double backward_mod = (N - x + 1) % k;
        if(forward_mod == 0 || backward_mod == 0){
            check = true;
        }
        if(check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}