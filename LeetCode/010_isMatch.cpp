// https://www.cnblogs.com/grandyang/p/4461713.html
#include<iostream>
#include<string> 
using namespace std;

class Solution
{
public:
	// "."可匹配任意一个字符; "x*"整体可匹配任意个（0~n）"x"

	// 法一: 递归
	bool isMatch(string s, string p)
	{
		if (p.empty())
			return s.empty();
		if (p.size() == 1)
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));

		if (p[1] != '*')
		{
			if (s.empty())
				return false;
			return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		else
		{
			while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
			{
				// "x*"不一定匹配完所有的"x"
				// 如: s="aaa", p="a*a", 其中"a*"只匹配"aa"
				if (isMatch(s, p.substr(2)))
					return true;
				s = s.substr(1);
			}
			return isMatch(s, p.substr(2));
		}
	}
} s;

int main()
{
	cout << s.isMatch("aaa", "a*a") << endl;
	cout << s.isMatch("a", "a*") << endl;
	cout << s.isMatch("", "a*") << endl;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
	system("pause");
	return 0;
}