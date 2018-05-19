#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int n = 0, temp;
		if (nums.empty())
			return 0;
		else
		{
			temp = nums[0];
			n++;
		}
		for (int i = 1; i < nums.size(); i++)
		{
			if (temp != nums[i])
			{
				temp = nums[i];
				nums[n++] = temp;
			}
		}
		return n;
	}
} s;

int main()
{
	vector<int> nums1 = { 1,1,2 };
	vector<int> nums2 = { 0,0,1,1,1,2,2,3,3,4 };
	vector<int> nums3 = {  };
	cout << s.removeDuplicates(nums1) << endl;
	cout << s.removeDuplicates(nums2) << endl;
	cout << s.removeDuplicates(nums3) << endl;
	system("pause");
	return 0;
}