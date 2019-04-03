#include<iostream>
#include<vector>
using namespace std;

// 动态规划 斐波那契
class Solution
{
public:
	// 法二:时间O(n),空间O(1)
	int climbStairs(int n) 
	{
		int a = 1, b = 1;
		while (n--)
			a = (b += a) - a;
		return a;
	}
	// 法一:时间O(n),空间O(n)
	//int climbStairs(int n)
	//{
	//	vector<int> a(n + 5);
	//	a[0] = 1, a[1] = 1;
	//	for (int i = 2; i <= n; i++)
	//		a[i] = a[i - 1] + a[i - 2];
	//	return a[n];
	//}
} s;

int main()
{
	cout << s.climbStairs(1) << endl;
	cout << s.climbStairs(2) << endl;
	cout << s.climbStairs(3) << endl;
	cout << s.climbStairs(5) << endl;
	system("pause");
	return 0;
}