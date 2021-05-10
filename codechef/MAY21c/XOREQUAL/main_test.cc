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
    int count = 0;
    int N = 5;
    int range = (1 << N) - 1;
    for(int i = 0; i < range; i++){
        auto a = (i) ^ (i+1);
        auto b = (i+2) ^ (i+3);
        if(a == b){
            cout << i << endl;
            count += 1;
        }
    }
    cout << "FINAL COUNT: " << count << endl;
    cout << "Code output: " << (1 << (N - 1)) << endl;
    return 0;
}
