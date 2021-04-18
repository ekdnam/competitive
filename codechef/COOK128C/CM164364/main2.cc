// https://www.codechef.com/COOK128C/problems/CM164364
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>

using namespace std;

bool fcompare(pair<int, pair<int, int>> p,
              pair<int, pair<int, int>> p1)
{
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}

// vector<long long int> sortByFrequency(vector<long long int> arr, long long int n, long long int x)
// void sortByFrequency(vector<long long int> arr, long long int n, long long int x)
long long int sortByFrequency(vector<long long int> arr, long long int n, long long int x)
{
    // vector<long long int> out;
    unordered_map<long long int, pair<long long int, long long int>> hash; // hash map
    for (long long int i = 0; i < n; i++)
    {
        if (hash.find(arr[i]) != hash.end())
            hash[arr[i]].second++;
        else
            hash[arr[i]] = make_pair(i, 1);
    } // store the count of all the elements in the hashmap

    // Iterator to Traverse the Hashmap
    auto it = hash.begin();

    // Vector to store the Final Sortted order
    vector<pair<long long int, pair<long long int, long long int>>> b;
    for (it; it != hash.end(); ++it)
        b.push_back(make_pair(it->first, it->second));

    sort(b.begin(), b.end(), fcompare);

    // Printing the Sorted sequence
    long long int out = 0;
    cout << "SIZE: " << b.size() << endl;
    bool exit = false;
    // for (int i = 0; i < b.size() && !exit; i++)
    // {
    //     int count = b[i].second.second;
    //     out -= 1;
    //     while (count--)
    //         if (x >= 0)
    //         {
    //             x -= 1;
    //         }
    //         else
    //         {
    //             exit = true;
    //             break;
    //         }
    //     // cout << b[i].first << " ";
    // }
    for (long long int i = 0; i < b.size(); i++)
    {
        long long int count = b[i].second.second;
        long long int count2 = count;
        if (x <= 0)
        {
            break;
        }
        while (count && x)
        {
            x -= 1;
            count -= 1;
        }
        b[i].second.second = count;
    }
    for(long long int i = 0; i < b.size(); i++){
        if(b[i].second.second > 0){
            out += 1;
        }
    }
    return out;
}

int main(void)
{
    long long int t, t_copy, n, x, temp, temp2 = 0;
    cin >> t;
    t_copy = t;
    vector<long long int> out;
    while (t--)
    {
        vector<long long int> a;
        cin >> n >> x;
        for (long long int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        // a = sortByFrequency(a, n, x);
        temp2 = sortByFrequency(a, n, x);
        cout << "OUT: " << temp2 << endl;
        // for(long long int i = 0; i < n; i++){
        //     cout << a[i] << endl;
        // }
    }

    // for (long long int i = 0; i < t_copy - 1; i++)
    // {
    //     cout << out[i] << endl;
    // }
    // cout << out[t_copy - 1];
    return 0;
}