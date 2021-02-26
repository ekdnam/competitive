// https://codeforces.com/problemset/problem/474/A
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
    string alphabets = "qwertyuiopasdfghjkl;zxcvbnm,./";
    int alphabetsLen = alphabets.size();

    string input;
    string inputDir;

    cin >> inputDir >> input;

    int lenInput = input.size();
    int dir;

    dir = (inputDir == "L") ? 1 : -1;

    // string checker = "L";
    // if (strcmp(inputDir, checker))
    // {
    //     dir = -1;
    // }
    // else
    // {
    //     dir = 1;
    // }
    vector<char> output;

    for (int i = 0; i < lenInput; i++)
    {
        char intermediate = input[i];
        for (int j = 0; j < alphabetsLen; j++)
        {
            if (intermediate == alphabets[j])
            {
                output.push_back(alphabets[j + dir]);
                break;
            }
        }
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }
    return 0;
}