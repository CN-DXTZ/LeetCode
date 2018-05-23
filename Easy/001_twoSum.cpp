#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	// 法二:O(N)
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> v = nums;
		sort(v.begin(), v.end());
		int left = 0, right = v.size() - 1;
		int sum = v[left] + v[right];
		while (sum != target)
		{
			if (sum < target)
				left++;
			else
				right--;
			sum = v[left] + v[right];
		}

		vector<int> ans;
		for (int k = 0; k < nums.size(); k++)
		{
			if (ans.size() == 2)
				break;
			if (nums[k] == v[left] || nums[k] == v[right])
				ans.push_back(k);
		}
		return ans;
	}
	// 法一:O(N^2)
	//vector<int> twoSum(vector<int>& nums, int target)
	//{
	//	int i = 0, j = 0;
	//	for (i = 0; i < nums.size(); i++)
	//		for (j = i + 1; j < nums.size(); j++)
	//		{
	//			if ((nums[i] + nums[j]) == target)
	//				goto flag;
	//		}
	//flag:		return { i,j };
	//}
} s;

int main()
{
	vector<int> nums1 = { 2, 7, 11, 15 };
	vector<int> ans1 = s.twoSum(nums1, 13);
	cout << ans1[0] << " " << ans1[1] << endl;
	vector<int> nums2 = { 3,2,4 };
	vector<int> ans2 = s.twoSum(nums2, 6);
	cout << ans2[0] << " " << ans2[1] << endl;
	system("pause");
	return 0;
}