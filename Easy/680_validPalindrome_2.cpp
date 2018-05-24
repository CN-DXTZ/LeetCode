#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string str;
	bool validPalindrome(string s)
	{
		str = s;
		return judge(0, s.size() - 1, 1);
	}
	bool judge(int left, int right, int flag)
	{
		while (str[left] == str[right])
		{
			if (left >= right)
				return true;
			else
				left++, right--;
		}
		if (flag)
			return judge(left + 1, right, 0) | judge(left, right - 1, 0);
		else
			return false;
	}
} s;

int main()
{
	cout << s.validPalindrome("abcddba") << endl;
	cout << s.validPalindrome("abddcba") << endl;
	cout << s.validPalindrome("abcd") << endl;
	system("pause");
	return 0;
}