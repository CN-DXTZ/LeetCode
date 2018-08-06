// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C++-solutions
#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution
{
public:
	// ����: 
	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size(), start = 0, curr_n = n;
		// ÿ�ν��� k ��Ԫ�طŶ���ʣ�ಿ�ֵ�ǰ k ��
		// k = k % curr_n: �ȿ�����ÿ��ѭ�������, �Է��´�Խ��, �����Ϊ������־, ʮ�ֻ���
		for (; k = k % curr_n; curr_n -= k, start += k)
			for (int i = 0; i < k; i++)
				swap(nums[start + i], nums[n - k + i]);
	}

	// ����: ��תǰ n-k ��Ԫ�أ�Ȼ����� k ��Ԫ�أ�������� n ��Ԫ��
	//void rotate(vector<int>& nums, int k)
	//{
	//	int n = nums.size();
	//	k = k % n;
	//	reverse(nums.begin(), nums.begin() + n - k);
	//	reverse(nums.begin() + n - k, nums.end());
	//	reverse(nums.begin(), nums.end());
	//}

	// ��һ: ��һ��Ԫ�ؿ�ʼ��ת����Ԫ��
	//void rotate(vector<int>& nums, int k)
	//{
	//	int n = nums.size();
	//	int p_start = -1, p_curr, p_next;
	//	int temp1, temp2;
	//	for (int cnt = 0; cnt < n;)
	//	{
	//		// �� n%k==0 ʱ, �������ʼ������ת
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