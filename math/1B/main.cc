// https://codeforces.com/problemset/problem/1/B
// TODO
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string getAnswer(string input)
{
    string ans;

    if (input[0] == 'R')
    {
        string row = NULL, col = NULL;
        int row_iter = 0;
        int string_len = input.length();
        while (input[row_iter++] != 'C')
            ;
        row = input.substr(1, row_iter);
        col = input.substr(row_iter + 1, string_len - row_iter - 1);
    }
    else
    {
    }
}
int main(void)
{
    long long int n;
    cin >> n;
    long long int x = n;
    vector<string> input;
    vector<string> answer;
    string temp;
    while (x--)
    {
        cin >> temp;
        input.push_back(temp);
    }
    x = 0;
    while (x < n)
    {
        answer.push_back(getAnswer(input.at(x)));
        x += 1;
    }
    x = 0;
    while (x < n - 1)
    {
        cout << answer.at(x) << endl;
    }
    cout << answer.at(n - 1);
}
