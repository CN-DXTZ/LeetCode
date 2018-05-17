#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int i = 0, j = 0;
		for (i = 0; i < nums.size(); i++)
			for (j = i + 1; j < nums.size(); j++)
			{
				if ((nums[i] + nums[j]) == target)
					goto flag;
			}
	flag:		return { i,j };
	}
} s;
int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> ans = s.twoSum(nums, target);
	cout << ans[0] << " " << ans[1] << endl;
	system("pause");
	return 0;
}