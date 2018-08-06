#include<iostream>
#include<vector> 
using namespace std;
class Solution
{
public:
	vector<int> v;
	// ¶þ·Ö
	int findPeakElement(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (right - left > 0)
		{
			int mid = (left+right) >> 1;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else 
				right = mid;
		}
		return  left;
	}
} s;

int main()
{
	vector<int> a = { 1,2 };
	cout << s.findPeakElement(a) << endl;
	system("pause");
	return 0;
}