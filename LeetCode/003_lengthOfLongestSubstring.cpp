/*******完结*******/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	// 遍历两遍
	int lengthOfLongestSubstring(string s)
	{
		bool ch[200] = { 0 };
		int max_num = 0, num = 0;
		for (int son_end = 0, son_start = 0; son_end < s.length(); son_end++)
		{
			// 判断是否出现重复字母
			if (!ch[s[son_end]])
				ch[s[son_end]] = 1;
			else
			{
				// 更新最大长度
				if (num > max_num)
					max_num = num;
				// 剔除从子串开始至重复字母的上一次出现间所有字符
				for (; son_start < son_end; son_start++)
				{
					num--;
					if (s[son_start] != s[son_end])
						ch[s[son_start]] = 0;
					else
						break;
				}
				son_start++;
			}
			num++;
		}
		if (num > max_num)
			max_num = num;
		return max_num;
	}
}s;

int main()
{
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	system("pause");
	return 0;
}