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
		// �����ҵ���һ������Ե�λ�ã��������������ֵ���
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				left = i;
				break;
			}
		}
		// ���ֵ��������
		if (left == -1)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		// ������λ�õĺ����������У��ҳ�������ʹ�ֵ���������С��λ��
		// ���������н������У��������ҳ���һ���ֵ����������λ�õĽ��н���
		// ��������з�ת����
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
