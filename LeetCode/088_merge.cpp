#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m - 1, j = n - 1, p = m + n - 1;
		while (j >= 0)
			nums1[p--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
	}
} s;

int main()
{
	vector<int> v0 = { 1,2,3,0,0,0 };
	vector<int> v1 = { 2,5,6 };
	s.merge(v0, 3, v1, 3);
	system("pause");
	return 0;
}