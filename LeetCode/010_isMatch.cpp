#include<iostream>
#include<string> 
#include<vector> 
using namespace std;

class Solution
{
#define 正则表达式
	// "."可匹配任意一个字符; "x*"整体可匹配任意（0~n）个"x"
public:
	// 法二: 动态规划
	bool isMatch(string s, string p)
	{
		int len_s = s.size(), len_p = p.size();
		// dp[i][j] 表示 s[0...i - 1] 和 p[0...j - 1] 匹配
		vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));

		// 边界:
		// 1.s 和 p 空
		dp[0][0] = true;
		// 2.p 空时
		for (int i = 1; i <= len_s; i++)
			dp[i][0] = false;
		// 3.s 空时
		for (int j = 1; j <= len_p; j++)
			dp[0][j] = j > 1 && dp[0][j - 2] && '*' == p[j - 1];
		// 内部:
		for (int i = 1; i <= len_s; i++)
			for (int j = 1; j <= len_p; j++)
			{
				if (p[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				else // 两种情况: 见递归法循环部分
					dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
			}
		return dp[len_s][len_p];
	}

	// 法一: 递归
	//bool isMatch(string s, string p)
	//{
	//	if (p.empty())
	//		return s.empty();
	//	if (p.size() == 1)
	//		return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));

	//	if (p[1] == '*')
	//	{
	//		while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
	//		{
	//			// "x*"不一定匹配完所有的"x"
	//			// 如: s="aaa",p="a*a", 其中"a*"只匹配"aa"
	//			if (isMatch(s, p.substr(2)))
	//				return true;
	//			s = s.substr(1);
	//		}
	//		return isMatch(s, p.substr(2));
	//		// 此部分用了循环,亦可用纯递归,即直接:
	//		// return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
	//	}
	//	else
	//		return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	//}
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