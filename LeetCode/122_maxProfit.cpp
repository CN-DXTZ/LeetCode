#include<iostream>
#include<vector> 
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int ans = 0;
		if (prices.size() <= 1)
			return ans;

		int i = 0, j = 0, n = prices.size();
		while (1)
		{
			if (j == n - 1)
			{
				ans += prices[j] - prices[i];
				break;
			}
			if (prices[j] <= prices[j + 1])
				j++;
			else
			{
				ans += prices[j] - prices[i];
				i = j = j + 1;
			}
		}
		return ans;
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