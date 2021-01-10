// link: https://codeforces.com/problemset/problem/490/A
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> lowest(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    pair<int, int> min = a;

    if(b.first < min.first){
        min = b;
    }
    if(c.first < min.first){
        min = c;
    }
    return min;
}
int main(void)
{
    int n;
    vector<pair<int, int>> x;

    cin >> n;
    int i = 0, temp;
    while (i < n)
    {
        cin >> temp;
        x.push_back(make_pair(temp, i + 1));
        i += 1;
    }

    sort(x.begin(), x.end());

    vector<pair<int, int>> ones;
    vector<pair<int, int>> twos;
    vector<pair<int, int>> threes;

    i = 0;
    while (i < x.size())
    {
        if (x.at(i).first == 1)
        {
            ones.push_back(make_pair(x.at(i).first, x.at(i).second));
        }
        else if (x.at(i).first == 2)
        {
            twos.push_back(make_pair(x.at(i).first, x.at(i).second));
        }
        else
        {
            threes.push_back(make_pair(x.at(i).first, x.at(i).second));
        }
        i += 1;
    }

    if (ones.size() == 0)
    {
        cout << 0;
        return 0;
    }
    if (twos.size() == 0)
    {
        cout << 0;
        return 0;
    }
    if (threes.size() == 0)
    {
        cout << 0;
        return 0;

    }

    pair<int, int> one_size = make_pair(ones.size(), 1);
    pair<int, int> two_size = make_pair(twos.size(), 2);
    pair<int, int> three_size = make_pair(threes.size(), 3);

    pair<int, int> least = lowest(one_size, two_size, three_size);
    cout << least.first << endl;

    temp = 0;

    while(temp < least.first - 1){
        cout << ones.at(temp).second << " " << twos.at(temp).second << " " << threes.at(temp).second << endl;
        temp += 1;
    }
    cout << ones.at(least.first - 1).second << " " << twos.at(least.first - 1).second << " " << threes.at(least.first - 1).second;
    return 0;
}