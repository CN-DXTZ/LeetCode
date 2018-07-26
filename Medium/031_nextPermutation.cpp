// https://leetcode.com/problems/next-permutation/discuss/13867/A-simple-algorithm-from-Wikipedia-with-C++-implementation-(can-be-used-in-Permutations-and-Permutations-II)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int left = -1;
		// 倒序找到第一个升序对的位置，即交换可增大字典序
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				left = i;
				break;
			}
		}
		// 若字典序已最大
		if (left == -1)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		// 在上述位置的后续子序列中，找出交换可使字典序增大最小的位置
		// 由于子序列降序排列，即倒序找出第一个字典序大于上述位置的进行交换
		// 最后将子序列反转即可
		int right = -1;
		for (int i = nums.size() - 1; i > left; i--)
		{
			if (nums[i] > nums[left])
			{
				right = i;
				break;
			}
		}
		swap(nums[left], nums[right]);
		reverse(nums.begin() + left + 1, nums.end());
	}
} s;

int main()
{
	system("pause");
	return 0;
}
