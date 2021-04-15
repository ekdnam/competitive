// https://www.codechef.com/SPYB21C/problems/GOTHAM
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
    long long int N, temp, Q;
    long long int total_distance, quant_distance;
    cin >> N;
    vector<long long int> P;
    for (long long int i = 0; i < N; i++)
    {
        cin >> temp;
        P.push_back(temp);
    }
    cin >> Q;
    while (Q--)
    {
        long long int X, K, i = 0;
        cin >> X >> K;
        total_distance = 0;
        quant_distance = 0;
        i = X - 1;
        while (i < N)
        {
            temp = P[i] - K;
            if (temp < 0)
            {
                temp = P[i];
                K = K - P[i];
                P[i] = 0;
                total_distance += quant_distance * temp;
                quant_distance += 1;
                i++;
            }
            else
            {
                P[i] = P[i] - K;
                total_distance += K;
                break;
            }
        }
        cout << total_distance << endl;
    }
}