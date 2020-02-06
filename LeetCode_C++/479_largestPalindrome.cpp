#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution
{
public:
	// 未证明回文长度为2n
	int largestPalindrome(int n)
	{
		if (n == 1) return 9;
		int upper = pow(10, n) - 1;
		for (int i = upper; ; i--) 
		{
			string t = to_string(i);
			long long pld =stoll(t + string(t.rbegin(), t.rend())); 
			for (long long j = upper; j*j >= pld; j--)
			{
				if (pld % j == 0)
				{
					return pld % 1337;
				}
			}
		}
		return -1;
	}
} s;

int main()
{
	cout << s.largestPalindrome(8) << endl;
	system("pause");
	return 0;
}