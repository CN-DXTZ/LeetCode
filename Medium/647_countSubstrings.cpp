#include<iostream>
#include<string> 
using namespace std;
// ����:
class Solution
{
public:
	int countSubstrings(string  s)
	{
		int num = 0;
		int sz = s.size();
		bool dp[1000][1000] = { 0 };
		for (int i = 0; i < sz; i++) // �Ӵ�����-1
			for (int j = 0; j < (sz - i); j++) // �Ӵ����
			{
				dp[j][j + i] = (i < 2 || dp[j + 1][j + i - 1]) && (s[j] == s[j + i]);
				if (dp[j][j + i])
					num++;
			}
		return num;
	}
} s;
// ��һ:
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