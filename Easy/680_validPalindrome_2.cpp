#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	bool validPalindrome(string s)
	{
		return judge(s, 0, s.size() - 1, 0);
	}
	bool judge(string s, int i, int j, int flag)
	{
		while (s[i] == s[j])
		{
			if (i >= j)
				return true;
			else
				i++, j--;
		}
		if (flag)
			return false;
		else
		{
			bool ans = false;
			if (s[i + 1] == s[j])
				ans = ans || judge(s, i + 1, j, flag + 1);
			if (s[i] == s[j - 1])
				ans = ans || judge(s, i, j - 1, flag + 1);
			return ans;
		}
	}
} s;

int main()
{
	bool ans1 = s.validPalindrome("abcddba");
	cout << ans1 << endl;
	bool ans2 = s.validPalindrome("abddcba");
	cout << ans2 << endl;
	bool ans3 = s.validPalindrome("abcd");
	cout << ans3 << endl;
	system("pause");
	return 0;
}