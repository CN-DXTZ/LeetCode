#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int n = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[n++] = nums[i];
		}
		return n;
	}
} s;

int main()
{
	vector<int> nums1 = { 3,2,2,3 };
	vector<int> nums2 = { 0,1,2,2,3,0,4,2 };
	cout << s.removeElement(nums1, 3) << endl;
	cout << s.removeElement(nums2, 2) << endl;
	system("pause");
	return 0;
}