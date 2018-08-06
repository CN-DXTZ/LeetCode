#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
	// ·¨Ò»:Öð×Ö·ûÅÐ¶Ï
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty())
			return "";
		string s = strs[0];
		int i, j, len = s.length(), n = strs.size();
		for (i = 0; i < len; i++)
			for (j = 1; j < n; j++)
			{
				if (strs[j].size() <= i || strs[j][i] != s[i])
					goto flag;
			}
	flag:return  s.substr(0, i);
	}
	// ·¨¶þ:Öð´®ÅÐ¶Ï
	//string longestCommonPrefix(vector<string>& strs)
	//{
	//	if (strs.empty())
	//		return "";
	//	int n = strs.size();
	//	string s = strs[0];
	//	for (int i = 1; i < n; i++)
	//	{
	//		if (s.length() > strs[i].length())
	//			s = s.substr(0, strs[i].length());
	//		for (int j = 0; j < s.length(); j++)
	//			if (s[j] != strs[i][j])
	//			{
	//				s = s.substr(0, j);
	//				break;
	//			}
	//	}
	//	return s;
	//}
} s;

int main()
{
	vector<string> strs1 = { "flower","flow","flight" };
	vector<string> strs2 = { "" };
	vector<string> strs3 = { };
	cout << s.longestCommonPrefix(strs1) << endl;
	cout << s.longestCommonPrefix(strs2) << endl;
	cout << s.longestCommonPrefix(strs3) << endl;
	system("pause");
	return 0;
}