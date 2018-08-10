#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	// 法二: 动态规划: 时间O(n),空间O(1)
	int maxSubArray(vector<int>& nums)
	{
		int dp = INT_MIN, Max = INT_MIN;
		for (int i : nums)
		{
			dp = i + ((dp > 0) ? dp : 0);
			Max = Max > dp ? Max : dp;
		}
		return Max;
	}
	// 法一: 动态规划: 时间O(n),空间O(n)
	//int maxSubArray(vector<int>& nums)
	//{
	//	int n = nums.size();
	//	if (!n)
	//		return 0;

	//	vector<int> dp(n);
	//	int max = dp[0] = nums[0];
	//	for (int i = 1; i < n; i++)
	//	{
	//		dp[i] = nums[i] + ((dp[i - 1] > 0) ? dp[i - 1] : 0);
	//		max = max > dp[i] ? max : dp[i];
	//	}
	//	return max;
	//}
} s;

int main()
{
	vector<int> v0 = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> v1 = { -1 };
	cout << s.maxSubArray(v0) << endl;
	cout << s.maxSubArray(v1) << endl;
	system("pause");
	return 0;
}