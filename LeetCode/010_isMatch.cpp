#include<iostream>
#include<string> 
#include<vector> 
using namespace std;

class Solution
{
#define ������ʽ
	// "."��ƥ������һ���ַ�; "x*"�����ƥ�����⣨0~n����"x"
public:
	// ����: ��̬�滮
	bool isMatch(string s, string p)
	{
		int len_s = s.size(), len_p = p.size();
		// dp[i][j] ��ʾ s[0...i - 1] �� p[0...j - 1] ƥ��
		vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));

		// �߽�:
		// 1.s �� p ��
		dp[0][0] = true;
		// 2.p ��ʱ
		for (int i = 1; i <= len_s; i++)
			dp[i][0] = false;
		// 3.s ��ʱ
		for (int j = 1; j <= len_p; j++)
			dp[0][j] = j > 1 && dp[0][j - 2] && '*' == p[j - 1];
		// �ڲ�:
		for (int i = 1; i <= len_s; i++)
			for (int j = 1; j <= len_p; j++)
			{
				if (p[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				else // �������: ���ݹ鷨ѭ������
					dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
			}
		return dp[len_s][len_p];
	}

	// ��һ: �ݹ�
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
	//			// "x*"��һ��ƥ�������е�"x"
	//			// ��: s="aaa",p="a*a", ����"a*"ֻƥ��"aa"
	//			if (isMatch(s, p.substr(2)))
	//				return true;
	//			s = s.substr(1);
	//		}
	//		return isMatch(s, p.substr(2));
	//		// �˲�������ѭ��,����ô��ݹ�,��ֱ��:
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