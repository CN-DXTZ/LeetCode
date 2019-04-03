#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	// 法二:Manacher
	// 法一:中心膨胀法
	string longestPalindrome(string s)
	{
		int left = 0, right = 0, max_num = 0;
		// 中心插值，将原索引[0,(N-1)]映射至[0,(2*(N-1))]
		// 映射的意义在于方便偶数子串中心表示
		int N = s.length(), n = (N - 1) * 2;
		for (int i = 1; i < n; i++)
		{
			// 还原索引
			int L = (i - 1) / 2, R = i / 2 + 1;
			// 膨胀
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