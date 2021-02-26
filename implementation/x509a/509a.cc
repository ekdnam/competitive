// https://codeforces.com/problemset/problem/509/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
using namespace std;

long long int matrix[10][10];

int main(void)
{
    long long int temp1 = 0, temp2 = 0;
    for (int i = 0; i < 10; i++)
    {
        matrix[i][0] = 1;
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i - 1 < 0)
            {
                temp1 = 0;
            }
            else
            {
                temp1 = matrix[i - 1][j];
            }
            if (j - 1 < 0)
            {
                temp2 = 0;
            }
            else
            {
                temp2 = matrix[i][j - 1];
            }
            matrix[i][j] = temp1 + temp2;
        }
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int n;
    cin >> n;
    cout << matrix[n - 1][n - 1];
}