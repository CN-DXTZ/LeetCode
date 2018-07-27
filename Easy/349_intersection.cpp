#include<iostream>
#include<vector> 
#include<unordered_set> 
using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> ans;
		unordered_set<int> s(nums1.begin(), nums1.end());
		for (int i : nums2)
			if (s.erase(i))
				ans.push_back(i);
		return ans;
	}
} s;

int main()
{
	vector<int> v0 = { 1,2,2,1 };
	vector<int> v1 = { 2,2 };
	s.intersection(v0, v1);
	system("pause");
	return 0;
}