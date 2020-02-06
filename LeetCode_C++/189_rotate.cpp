// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C++-solutions
#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution
{
public:
	// 法三: 
	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size(), start = 0, curr_n = n;
		// 每次将后 k 个元素放对至剩余部分的前 k 个
		// k = k % curr_n: 既可以在每次循环后更新, 以防下次越界, 亦可作为结束标志, 十分机巧
		for (; k = k % curr_n; curr_n -= k, start += k)
			for (int i = 0; i < k; i++)
				swap(nums[start + i], nums[n - k + i]);
	}

	// 法二: 反转前 n-k 个元素，然后最后 k 个元素，最后所有 n 个元素
	//void rotate(vector<int>& nums, int k)
	//{
	//	int n = nums.size();
	//	k = k % n;
	//	reverse(nums.begin(), nums.begin() + n - k);
	//	reverse(nums.begin() + n - k, nums.end());
	//	reverse(nums.begin(), nums.end());
	//}

	// 法一: 从一个元素开始旋转所有元素
	//void rotate(vector<int>& nums, int k)
	//{
	//	int n = nums.size();
	//	int p_start = -1, p_curr, p_next;
	//	int temp1, temp2;
	//	for (int cnt = 0; cnt < n;)
	//	{
	//		// 当 n%k==0 时, 需更换起始点多次旋转
	//		p_curr = ++p_start;
	//		temp2 = nums[p_curr];
	//		do
	//		{
	//			p_next = (p_curr + k) % n;
	//			temp1 = nums[p_next];
	//			nums[p_next] = temp2;

	//			p_curr = p_next;
	//			temp2 = temp1;
	//			cnt++;
	//		} while (p_curr != p_start);
	//	}
	//}
} s;

int main()
{
	vector<int> v0 = { 1,2,3,4,5,6,7 };
	vector<int> v1 = { -1,-100,3,99 };
	s.rotate(v0, 3);
	s.rotate(v1, 2);
	system("pause");
	return 0;
}