// https://www.cnblogs.com/grandyang/p/4461713.html
#include<iostream>
#include<string> 
using namespace std;

class Solution
{
public:
	// "."��ƥ������һ���ַ�; "x*"�����ƥ���������0~n��"x"

	// ��һ: �ݹ�
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
				// "x*"��һ��ƥ�������е�"x"
				// ��: s="aaa", p="a*a", ����"a*"ֻƥ��"aa"
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