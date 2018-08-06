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
		if (nums.empty())
			return ans;

		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; nums[i] <= 0 && i < n - 2; i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;

			// Á½±ß¼Ð(twoSum)
			int twoSum = -nums[i];
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] == twoSum)
				{
					ans.push_back({ nums[i], nums[left], nums[right] });
					left++, right--;
					while (left < right && nums[left] == nums[left - 1])
						left++;
					while (left < right && nums[right] == nums[right + 1])
						right--;
				}
				while (left < right && nums[left] + nums[right] < twoSum)
					left++;
				while (left < right && nums[left] + nums[right] > twoSum)
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
			cout << ans[i][j]<<" ";
		cout << endl;
	}
	system("pause");
	return 0;
}
