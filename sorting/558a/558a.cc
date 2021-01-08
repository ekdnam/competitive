#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <utility>
// #include <bits/stdc++>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int temp1, temp2;
	vector<pair<int, int>> xi;
	
	int i = 0;
	
	while (i < n)
	{
		cin >> temp1;
		cin >> temp2;
		xi.push_back(make_pair(temp1, temp2));
		i++;
	}

	sort(xi.begin(), xi.end());

	if (n == 1)
	{
		cout << xi[0].second;
		return 0;
	}
	int posX = 0;
	
	while (posX < n)
	{
		if (xi[posX].first > 0)
		{
			break;
		}
		posX += 1;
	}

	

	int sum = 0;
	if (posX == n - posX)
	{
		// int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += xi[i].second;
		}
	}
	else
	{
		if (posX > n - posX)
		{
			int startPos = 2 * posX - n - 1;
			for (int i = startPos; i < n; i++)
			{
				sum += xi[i].second;
			}
		}
		else
		{
			int endPos = 2 * posX + 1;
			for (int i = 0; i < endPos; i++)
			{
				sum += xi[i].second;
			}
		}
	}
	cout << sum;
	return 0;
}
