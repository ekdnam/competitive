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
    long long int t, n, x, m, out, t_copy, A, B;

    vector<long long int> out_vec;

    cin >> t;

    t_copy = t;

    while (t--)
    {
        cin >> n >> m >> x;
        x--;
        B = long long int(x / n);
        A = long long int(x % n);
        out_vec.push_back(m * A + B + 1);
    }
    

    for (long long int i = 0; i < t_copy; i++)
    {
        if(i == t_copy - 1){
            cout << out_vec.at(i);
            continue;
        }
        cout << out_vec.at(i) << endl;
    }
}