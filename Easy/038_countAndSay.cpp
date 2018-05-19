#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string countAndSay(int n)
	{
		string ans = "1";
		n--;
		while (n--)
		{
			ans = say(ans);
		}
		return ans;
	}
	string say(string s)
	{
		string ans = "";
		char ch = s[0];
		int n = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ch)
				n++;
			else
			{
				ans = ans + to_string(n) + ch;
				ch = s[i];
				n = 1;
			}
		}
		ans = ans + to_string(n) + ch;
		return ans;
	}
} s;

int main()
{
	cout << s.countAndSay(1) << endl;
	cout << s.countAndSay(4) << endl;
	system("pause");
	return 0;
}