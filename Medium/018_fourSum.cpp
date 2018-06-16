#include<iostream>
#include<vector> 
#include<set> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ans;
		if (nums.empty())
			return ans;

		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 3; i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < n - 2; j++)
			{
				if (j != i + 1 && nums[j] == nums[j - 1])
					continue;

				// Á½±ß¼Ð(twoSum )
				int twoSum = target - nums[i] - nums[j];
				int left = j + 1, right = nums.size() - 1;
				while (left < right)
				{
					if (nums[left] + nums[right] == twoSum)
					{
						ans.push_back({ nums[i],nums[j], nums[left], nums[right] });
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
		}
		return ans;
	}
} s;

int main()
{
	vector<int> a1 = { 1, 0, -1, 0, -2, 2 };
	vector<int> a2 = { -3,-1,0,2,4,5 };
	vector<int> a3 = { 0,0,0,0 };
	vector<int> a4 = { -493,-470,-464,-453,-451,-446,-445,-407,-406,-393,
		-328,-312,-307,-303,-259,-253,-252,-243,-221,-193,-126,-126,-122,
		-117,-106,-105,-101,-71,-20,-12,3,4,20,20,54,84,98,111,148,149,152,
		171,175,176,211,218,227,331,352,389,410,420,448,485 };

	//vector<vector<int> > ans = s.fourSum(a1, 0);
	//vector<vector<int> > ans = s.fourSum(a2, 0);
	vector<vector<int> > ans = s.fourSum(a3, 0);
	//vector<vector<int> > ans = s.fourSum(a4, 1057);

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
