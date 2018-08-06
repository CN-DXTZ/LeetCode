#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> st;
		char ch;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				st.push(s[i]);
			else
			{
				if (st.empty())
					return false;
				ch = st.top();
				st.pop();
				if (abs(s[i] - ch) > 3)
					return false;
			}
		}
		if (st.empty())
			return true;
		else
			return false;
	}
} s;

int main()
{
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("{[]}") << endl;
	system("pause");
	return 0;
}