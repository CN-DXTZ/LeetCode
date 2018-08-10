#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	// 法二: 动态规划: 时间O(n),空间O(1)
	int rob(vector<int>& nums)
	{
		int a = 0, b = 0, flag = 0;
		for (int i : nums)
		{
			flag = !flag;
			if (flag)
				a = max(a + i, b);
			else
				b = max(a, b + i);
		}
		return max(a, b);
	}

	// 法一: 动态规划: 时间O(n),空间O(n)
	//int rob(vector<int>& nums)
	//{
	//	int n = nums.size();
	//	if (n == 0)
	//		return 0;

	//	vector<int> dp(n + 2);
	//	dp[0] = dp[1] = 0;
	//	for (int i = 0; i < n; ++i)
	//		dp[i + 2] = max(dp[i] + nums[i], dp[i + 1]);
	//	return dp[n + 1];
	//}
} s;

int main()
{
	vector<int> v0 = { 1,2,3,1 };
	vector<int> v1 = { 2,7,9,3,1 };
	vector<int> v2 = { 2 };
	vector<int> v3 = { 2,7 };
	cout << s.rob(v0) << endl;
	cout << s.rob(v1) << endl;
	cout << s.rob(v2) << endl;
	cout << s.rob(v3) << endl;
	system("pause");
	return 0;
}