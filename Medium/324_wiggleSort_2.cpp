#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
	//法一:快排+重列
	void wiggleSort(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> tmp = nums;
		int len = nums.size();
		int k = len - 1;
		//保证大大对小大，大小对小小，因为大小对小大时值可能相同
		//大数
		for (int i = 1; i < len; i += 2)
			nums[i] = tmp[k--];
		//小数
		for (int i = 0; i < len; i += 2)
			nums[i] = tmp[k--];
	}
} s;

int main()
{
	vector<int> nums = { 4,5,5,6 };
	s.wiggleSort(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;
	system("pause");
	return 0;
}