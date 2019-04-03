#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std;
class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size(), close_sum = INT_MAX;
		for (int i = 0; i < n - 2; i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;
			int abs_diff = i ? abs(close_sum - target) : INT_MAX;
			// 当三数和大于最大可能和时退出
			if (i && (nums[i] + nums[i + 1] + nums[i + 2]) >= (target + abs_diff))
				break;

			// 两边夹(twoSumClosest)
			int twoSum = target - nums[i];
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (abs(nums[left] + nums[right] - twoSum) < abs_diff)
				{
					close_sum = nums[i] + nums[left] + nums[right];
					abs_diff = abs(close_sum - target);
					if (abs_diff == 0)
						return close_sum;
				}
				if (nums[left] + nums[right] < twoSum)
					left++;
				else
					right--;
			}
		}
		return close_sum;
	}
} s;

int main()
{
	vector<int> a = { -1, 2, 1, -4 };
	vector<int> b = { 1, 1, -1, -1, 3 };
	cout << s.threeSumClosest(a, 1) << endl;
	cout << s.threeSumClosest(b, -1) << endl;
	system("pause");
	return 0;
}
