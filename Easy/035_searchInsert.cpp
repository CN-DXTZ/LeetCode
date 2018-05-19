#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] >= target)
				return i;
		}
		return nums.size();
	}
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