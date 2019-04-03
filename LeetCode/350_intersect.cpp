#include<iostream>
#include<vector> 
#include<algorithm> 
#include<unordered_map>
using namespace std;

class Solution
{
public:
	// 法二:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int n1 = nums1.size(), n2 = nums2.size();
		int p1 = 0, p2 = 0;
		vector<int> ans;
		// 一个集合遍历完则不再有交集，退出循环，故不会越界
		while (p1 < n1 && p2 < n2)
		{
			if (nums1[p1] == nums2[p2])
			{
				ans.push_back(nums1[p1]);
				p1++, p2++;
			}
			else if (nums1[p1] > nums2[p2])
				p2++;
			else
				p1++;
		}
		return ans;
	}

	// 法一:
	//vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	//{
	//	unordered_map<int, int> dict;
	//	for (int i : nums1)
	//		dict[i]++;

	//	vector<int> ans;
	//	for (int i : nums2)
	//		if ((dict[i]--) > 0)
	//			ans.push_back(i);
	//	return ans;
	//}
} s;

int main()
{
	vector<int> v0 = { 1,2,2,3 };
	vector<int> v1 = { 2,2 };
	vector<int> v2 = {  };
	s.intersect(v0, v1);
	//s.intersect(v2, v1);
	system("pause");
	return 0;
}