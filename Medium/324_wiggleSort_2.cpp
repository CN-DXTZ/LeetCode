#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
	void wiggleSort(vector<int>& nums)
	{
		sort(nums.begin(),nums.end());
		vector<int> tmp = nums;
		int len = nums.size();
		int k = len - 1;
		//大数
		for (int i = 1; i<len; i += 2)
			nums[i] = tmp[k--];
		//小数
		for (int i = 0; i<len; i += 2)
			nums[i] = tmp[k--];
	}
} s;
int main()
{
	vector<int> nums = { 1, 5, 1, 1, 6, 4 };
	s.wiggleSort(nums);
	for (int i=0;i<nums.size();i++)
		cout << nums[i]<< endl;
	system("pause");
	return 0;
}