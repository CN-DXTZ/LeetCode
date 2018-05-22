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

		// 仅需对短数组进行二分，长数组所选个数mid2可由mid1计算得出
		int mid1, mid2, n_mid_idx = (n + m + 1) / 2 - 2;
		int L1 = 0, R1 = n - 1;
		while (R1 - L1 > 1)
		{
			mid1 = (L1 + R1) / 2;
			mid2 = n_mid_idx - mid1;

			if (nums1[mid1] == nums2[mid2])
				break;
			else if (nums1[mid1] < nums2[mid2])
				L1 = mid1;
			else if (nums1[mid1] > nums2[mid2])
				R1 = mid1;
		}

		int L2 = max(n_mid_idx - R1, 0);
		int n_diff = n_mid_idx - L1 - L2;
		for (int i = 0; i <= n_diff; i++)
		{
			if (L1 < n && nums1[L1] <= nums2[L2])
				L1++;
			else
				L2++;
		}
		if ((m + n) % 2)
		{
			int t1 = (L1 < n) ? nums1[L1] : INT_MAX;
			int t2 = (L2 < m) ? nums2[L2] : INT_MAX;
			return min(t1, t2);
		}
		else
		{
			int min1;
			if (L1 < n  &&nums1[L1] <= nums2[L2])
				min1 = nums1[L1++];
			else
				min1 = nums2[L2++];
			int t1 = (L1 < n) ? nums1[L1] : INT_MAX;
			int t2 = (L2 < m) ? nums2[L2] : INT_MAX;
			int min2 = min(t1, t2);
			return (min1 + min2) / 2.0;
		}
	}
} s;

int main()
{
	vector<int> a1 = { 1,2 }, a2 = { 3,4 };
	vector<int> b1 = { 1,3,5,7,9,11 }, b2 = { 2,4,6,8,10,12 };
	vector<int> c1 = { 1,2,4 }, c2 = { 3,5 };
	vector<int> d1 = { 1,3,5,7,9,11 }, d2 = { 2,4,6,8,10,12,14 };
	vector<int> e1 = {  }, e2 = { 1 };
	vector<int>f1 = { 1,1 }, f2 = { 1,1 };
	vector<int>g1 = { 1,1,3,3 }, g2 = { 1,1,3,3 };
	vector<int>h1 = { 100001 }, h2 = { 100000 };
	cout << s.findMedianSortedArrays(a1, a2) << endl;
	cout << s.findMedianSortedArrays(b1, b2) << endl;
	cout << s.findMedianSortedArrays(c1, c2) << endl;
	cout << s.findMedianSortedArrays(d1, d2) << endl;
	cout << s.findMedianSortedArrays(e1, e2) << endl;
	cout << s.findMedianSortedArrays(f1, f2) << endl;
	cout << s.findMedianSortedArrays(g1, g2) << endl;
	printf("%.1f\n", s.findMedianSortedArrays(h1, h2));
	system("pause");
	return 0;
}