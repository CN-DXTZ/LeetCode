#include<iostream>
#include<vector> 
#include<numeric> 
using namespace std;
class Solution
{
public:
	// 法二: 位操作
	int missingNumber(vector<int>& nums)
	{
		int n = nums.size();
		int ans = n; // 相当于预先异或一次最大值
		for (int i = 0; i < n; i++)
			ans ^= nums[i] ^ i;
		return ans;
	}

	// 法一: 总和减去所有数
	//int missingNumber(vector<int>& nums)
	//{
	//	long long n = nums.size();
	//	long long ans = (n * (n + 1)) >> 1;
	//	for (int i : nums)
	//		ans -= i;
	//	return ans;
	//}
} s;

int main()
{
	vector<int> v1 = { 3,0,1 };
	vector<int> v2 = { 9,6,4,2,3,5,7,0,1 };
	cout << s.missingNumber(v1) << endl;
	cout << s.missingNumber(v2) << endl;
	system("pause");
	return 0;
}
