#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
using namespace std;

bool lowercaseAlphabetExists(string input){
    regex b("[a-z]");
    
}

int main(void){
    long long int t, i;
    vector<string> input;
    cin >> t;
    string temp;
    vector<string> output(t, "NO");
    for(i = 0; i < t; i++){
        cin >> temp;
        input.push_back(temp);
    }
}