#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ans;
		if (nums.size() == 0)
			return ans;

		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; nums[i] <= 0 && i < n - 2; i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;

			// Á½±ßÇ÷½ü - Éý¼¶°æ 001_twoSum 
			int tmpTarget = 0 - nums[i];
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] == tmpTarget)
				{
					ans.push_back({ nums[i], nums[left], nums[right] });
					while (left < right - 1 && nums[right] == nums[right - 1]) 
						right--;
					right--;
				}
				while (nums[left] + nums[right] < tmpTarget)
					left++;
				while (nums[left] + nums[right] > tmpTarget)
					right--;
			}
		}
		return ans;
	}
} s;

int main()
{
	vector<int> a = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	//[[-5,1,4],[-4,0,4],[-4,1,3],[-2,-2,4],[-2,1,1],[0,0,0]]
	vector<vector<int> > ans = s.threeSum(a);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}
