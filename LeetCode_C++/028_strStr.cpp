#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty())
			return 0;
		int i, j, n = haystack.size(), m = needle.size();
		for (i = 0; i <= (n - m); i++)
		{
			for (j = 0; j < m; j++)
				if (haystack[i + j] != needle[j])
					break;
			if (j == m)
				return i;
		}
		return -1;
	}
} s;

int main()
{
	cout << s.strStr("hello", "ll") << endl;
	cout << s.strStr("hello", "bba") << endl;
	system("pause");
	return 0;
}