#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	// ����:Manacher
	// ��һ:�������ͷ�
	string longestPalindrome(string s)
	{
		int left = 0, right = 0, max_num = 0;
		// ���Ĳ�ֵ����ԭ����[0,(N-1)]ӳ����[0,(2*(N-1))]
		// ӳ����������ڷ���ż���Ӵ����ı�ʾ
		int N = s.length(), n = (N - 1) * 2;
		for (int i = 1; i < n; i++)
		{
			// ��ԭ����
			int L = (i - 1) / 2, R = i / 2 + 1;
			// ����
			while (L >= 0 && R < N && s[L] == s[R])
				L--, R++;
			int num = R - L - 1;
			if (max_num < num)
			{
				max_num = num;
				left = L+1, right = R-1;
			}
		}
		return s.substr(left, right - left + 1);
	}
}s;

int main()
{
	cout << s.longestPalindrome("babad") << endl;
	cout << s.longestPalindrome("cbbd") << endl;
	cout << s.longestPalindrome("bb") << endl;
	system("pause");
	return 0;
}