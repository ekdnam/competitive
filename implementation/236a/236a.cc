#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    string input;
    string outputs[] = {"CHAT WITH HER!", "IGNORE HIM!"};
    cin >> input;
    int n = input.length();
    vector<char> uniqueCharacters;
    for (int i = 0; i < n; i++)
    {
        char temp = input[i];
        if (!uniqueCharacters.empty())
        {
            if (!binary_search(uniqueCharacters.begin(), uniqueCharacters.end(), temp))
            {
                uniqueCharacters.push_back(temp);
            }
            sort(uniqueCharacters.begin(), uniqueCharacters.end());
        }
        else
        {
            uniqueCharacters.push_back(temp);
        }
    }
    // for (int i = 0; i < uniqueCharacters.size(); i++)
    // {
    //     cout << uniqueCharacters.at(i) << " ";
    // }
    // cout << endl;
    if (uniqueCharacters.size() % 2 == 1)
    {
        cout << outputs[1];
    }
    else
    {
        cout << outputs[0];
    }
}