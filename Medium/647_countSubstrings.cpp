#include<iostream>
#include<string> 
#include<vector> 
using namespace std;
// ����:DP
class Solution
{
public:
	int countSubstrings(string  s)
	{
		int sz = s.size();
		vector<vector<int> > dp(sz, vector<int>(sz, 0));

		int num = 0;
		for (int i = 0; i < sz; i++) // �Ӵ�����-1
			for (int j = 0; j < (sz - i); j++) // �Ӵ����
				if (dp[j][j + i] = (i < 2 || dp[j + 1][j + i - 1]) && (s[j] == s[j + i]))
					num++;
		return num;
	}
} s;
// ��һ: DFS
//class Solution
//{
//	string str;
//public:
//	int countSubstrings(string  s)
//	{
//		str = s;
//		int num = 0;
//		for (int i = 0; i < str.size(); i++)
//			for (int j = i; j < str.size(); j++)
//			{
//				if (check(i, j))
//					num++;
//			}
//		return num;
//	}
//	bool check(int a, int b)
//	{
//		for (int i = 0; i < (b - a + 1) / 2; i++)
//			if (str[a + i] != str[b - i])
//				return false;
//		return true;
//	}
//} s;

int main()
{
	cout << s.countSubstrings("abc") << endl;
	cout << s.countSubstrings("aaa") << endl;
	system("pause");
	return 0;
}