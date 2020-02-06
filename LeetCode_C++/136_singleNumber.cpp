#include<iostream>
#include<vector> 
using namespace std;

class Solution
{
public:
	// x XOR x = 0
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		for (int i : nums)
			result ^= i;
		return result;
	}
} s;

int main()
{
	vector<int> v0 = { 2,2,1 };
	vector<int> v1 = { 4,1,2,1,2 };
	cout << s.singleNumber(v0) << endl;
	cout << s.singleNumber(v1) << endl;
	system("pause");
	return 0;
}