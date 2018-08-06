/*******���*******/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	// ��������
	int lengthOfLongestSubstring(string s)
	{
		bool ch[200] = { 0 };
		int max_num = 0, num = 0;
		for (int son_end = 0, son_start = 0; son_end < s.length(); son_end++)
		{
			// �ж��Ƿ�����ظ���ĸ
			if (!ch[s[son_end]])
				ch[s[son_end]] = 1;
			else
			{
				// ������󳤶�
				if (num > max_num)
					max_num = num;
				// �޳����Ӵ���ʼ���ظ���ĸ����һ�γ��ּ������ַ�
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