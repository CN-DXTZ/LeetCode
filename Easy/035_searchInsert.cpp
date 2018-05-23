#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	// 法二: 二分查找
	int searchInsert(vector<int>& nums, int target)
	{
		int min = 0, max = nums.size() - 1, mid;
		while (max - min > 1)
		{
			mid = (max - min) / 2 + min;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				max = mid;
			else
				min = mid;
		}
		if (nums[min] >= target)
			return min;
		return max;
	}
	// 法一
	//int searchInsert(vector<int>& nums, int target)
	//{
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		if (nums[i] >= target)
	//			return i;
	//	}
	//	return nums.size();
	//}
} s;

int main()
{
	vector<int> nums = { 1,3,5,6 };
	cout << s.searchInsert(nums, 5) << endl;
	cout << s.searchInsert(nums, 2) << endl;
	cout << s.searchInsert(nums, 7) << endl;
	cout << s.searchInsert(nums, 0) << endl;
	system("pause");
	return 0;
}