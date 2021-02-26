// https://codeforces.com/problemset/problem/688/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
using namespace std;

string stringMatrix[100];
int wins[100];
int main(void)
{
    int n, d;
    cin >> n >> d;
    int temp;
    int rows = d;
    int cols = n;
    for (int i = 0; i < rows; i++)
    {
        cin >> stringMatrix[i];
    }

    for (int i = 0; i < rows; i++)
    {
        string temp = stringMatrix[i];
        for (int j = 0; j < cols; j++)
        {
            if (temp[j] == '0')
            {
                wins[i] = 1;
                break;
            }
        }
    }
    int count = 0, max = 0;
    // for(int i = 0; i < d; i++){
    //     cout << wins[i] << " ";
    // }
    for (int i = 0; i < d; i++)
    {
        if (wins[i] == 0)
        {
            count = 0;
        }
        else
        {
            count += 1;
        }
        max = count > max ? count : max;
    }
    cout << max;
    return 0;
}