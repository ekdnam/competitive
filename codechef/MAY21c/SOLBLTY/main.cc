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
    long long int T, X, A, B;
    double temp;
    vector<double> ans;
    cin >> T;
    while (T--)
    {
        cin >> X >> A >> B;
        temp = A + (100 - X) * B;
        temp = temp * 10;
        ans.push_back(temp);
    }
    for (double i : ans)
    {
        cout << i << endl;
    }
}