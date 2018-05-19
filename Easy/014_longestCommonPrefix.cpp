#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string s = "";
		// ¿ÕÊý×é¼ì²â 
		if (!strs.size())
			return s;
		char ch, temp;
		// ¿Õ×Ö·û´®¼ì²â 
		for (int i = 0; i < strs[0].size(); i++)
		{
			ch = i < strs[0].size() ? strs[0][i] : -1;
			for (int j = 1; j < strs.size(); j++)
			{
				temp = i < strs[j].size() ? strs[j][i] : -2;
				if (ch == -1 || ch != temp)
					return s;
			}
			s += ch;
		}
		return s;
	}
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