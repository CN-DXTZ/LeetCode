#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = nums1.size(), m = nums2.size();
		if (n == 0)
			return (nums2[m / 2] + nums2[(m - 1) / 2]) / 2.0;
		else if (n > m)   // 保证nums1为短数组
			return findMedianSortedArrays(nums2, nums1);

		int mid_idx1, mid_idx2, n_mid_idx = (n + m + 1) / 2 - 2;
		int L1 = 0, R1 = n - 1;
		// 确定中位数位置范围
		while (R1 - L1 > 1)
		{
			// 仅需对短数组进行二分标记，则长数组标记位置可推知
			mid_idx1 = (L1 + R1) / 2;
			mid_idx2 = n_mid_idx - mid_idx1;

			// 根据两数组标记的值的大小,动态调整标记位置
			if (nums1[mid_idx1] == nums2[mid_idx2])
				break;
			else if (nums1[mid_idx1] < nums2[mid_idx2])
				L1 = mid_idx1;
			else if (nums1[mid_idx1] > nums2[mid_idx2])
				R1 = mid_idx1;
		}

		// 确定中位数
		int L2 = max(n_mid_idx - R1, 0);
		int n_diff = n_mid_idx - L1 - L2;
		int t1, t2;
		vector<int> mid;
		for (int i = 0; i <= n_diff + 2; i++)
		{
			t1 = (L1 < n) ? nums1[L1] : INT_MAX;
			t2 = (L2 < m) ? nums2[L2] : INT_MAX;
			mid.push_back((t1 <= t2 ? nums1[L1++] : nums2[L2++]));
		}
		if ((m + n) % 2)
			return *(mid.end()-2);
		else
			return (*(mid.end() - 1) + *(mid.end() - 2)) / 2.0;
	}
} s;

int main()
{
  /*2.5
	6.5
	3
	7
	1
	1
	2
	1000.5*/
	vector<int> a1 = { 1,2 }, a2 = { 3,4 };
	vector<int> b1 = { 1,3,5,7,9,11 }, b2 = { 2,4,6,8,10,12 };
	vector<int> c1 = { 1,2,4 }, c2 = { 3,5 };
	vector<int> d1 = { 1,3,5,7,9,11 }, d2 = { 2,4,6,8,10,12,14 };
	vector<int> e1 = {  }, e2 = { 1 };
	vector<int>f1 = { 1,1 }, f2 = { 1,1 };
	vector<int>g1 = { 1,1,3,3 }, g2 = { 1,1,3,3 };
	vector<int>h1 = { 1001 }, h2 = { 1000 };
	cout << s.findMedianSortedArrays(a1, a2) << endl;
	cout << s.findMedianSortedArrays(b1, b2) << endl;
	cout << s.findMedianSortedArrays(c1, c2) << endl;
	cout << s.findMedianSortedArrays(d1, d2) << endl;
	cout << s.findMedianSortedArrays(e1, e2) << endl;
	cout << s.findMedianSortedArrays(f1, f2) << endl;
	cout << s.findMedianSortedArrays(g1, g2) << endl;
	cout << s.findMedianSortedArrays(h1, h2) << endl;
	system("pause");
	return 0;
}