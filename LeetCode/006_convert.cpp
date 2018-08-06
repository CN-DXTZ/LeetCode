#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows)
	{
		vector <string> strs(numRows);

		int n = numRows - 1, m = max(n * 2, 1);
		for (int i = 0; i < s.length(); i++)
		{
			int j = i % m;
			if (j > n)
				j = (m - j);
			strs[j].push_back(s[i]);
		}
		string ans;
		for (int i = 0; i < numRows; i++)
			ans.append(strs[i]);
		return ans;
	}
}s;

int main()
{
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	cout << s.convert("PAYPALISHIRING", 4) << endl;
	cout << s.convert("A", 1) << endl;
	system("pause");
	return 0;
}