#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i])
				nums[j++] = nums[i];
		for(;j< nums.size();j++)
			nums[j]=0;
	}
} s;

int main()
{
	vector<int> nums1 = { 0,1,0,3,12 };
	s.moveZeroes(nums1);
	system("pause");
	return 0;
}