#include<iostream>
#include<vector> 
#include<unordered_map>
using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_map<int, int> dict;
		for (int i : nums)
			if (dict[i]++)
				return true;
		return false;
	}
} s;

int main()
{
	vector<int> v0 = { 1,2,3,1 };
	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2 = { 1,1,1,3,3,4,3,2,4,2 };
	cout << s.containsDuplicate(v0) << endl;
	cout << s.containsDuplicate(v1) << endl;
	cout << s.containsDuplicate(v2) << endl;
	system("pause");
	return 0;
}