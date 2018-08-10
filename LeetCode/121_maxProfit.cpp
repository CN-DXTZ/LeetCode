#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
			return 0;

		int min, max, profit = 0;
		min = max = prices[0];
		for (int i : prices)
		{
			if (i < min)
				min = max = i;
			else if (i > max)
			{
				max = i;
				if ((max - min) > profit)
					profit = max - min;
			}
		}
		return profit;
	}
} s;

int main()
{
	vector<int> v0 = { 1,2 };
	vector<int> v1 = { 7,1,5,3,6,4 };
	vector<int> v2 = { 1,2,3,4,5 };
	vector<int> v3 = { 7,6,4,3,1 };
	cout << s.maxProfit(v0) << endl;
	cout << s.maxProfit(v1) << endl;
	cout << s.maxProfit(v2) << endl;
	cout << s.maxProfit(v3) << endl;
	system("pause");
	return 0;
}