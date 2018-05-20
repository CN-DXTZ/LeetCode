#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = nums1.size(),m = nums2.size();
		if (n > m)   //保证nums1为短
			return findMedianSortedArrays(nums2, nums1);
		int L1, L2, R1, R2, mid1, mid2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
		while (lo <= hi)   //二分
		{
			mid1 = (lo + hi) / 2;  //c1是二分的结果
			mid2 = m + n - mid1;
			L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];   //map to original element
			R1 = (mid1 == 2 * n) ? INT_MAX : nums1[mid1 / 2];
			L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
			R2 = (mid2 == 2 * m) ? INT_MAX : nums2[mid2 / 2];

			if (L1 > R2)
				hi = mid1 - 1;
			else if (L2 > R1)
				lo = mid1 + 1;
			else
				break;
		}
		return (max(L1, L2) + min(R1, R2)) / 2.0;
	}
} s;

int main()
{
	vector<int> a1 = { 1,3 };
	vector<int> a2 = { 2 };
	vector<int> b1 = { 1,2 };
	vector<int> b2 = { 3,4 };
	cout << s.findMedianSortedArrays(a1, a2) << endl;
	cout << s.findMedianSortedArrays(b1, b2) << endl;
	system("pause");
	return 0;
}