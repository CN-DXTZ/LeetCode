#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s)
	{
		int len = s.length();

		unordered_map<char, int> dict;
		for (char ch : s)
			dict[ch]++;
		for (int i = 0; i < len; i++)
			if (dict[s[i]]==1)
				return i;
		return -1;
	}
} s;

int main()
{
	cout << s.firstUniqChar("leetcode") << endl;
	cout << s.firstUniqChar("loveleetcode") << endl;
	cout << s.firstUniqChar("l") << endl;
	cout << s.firstUniqChar("ll") << endl;
	cout << s.firstUniqChar("") << endl;
	system("pause");
	return 0;
}