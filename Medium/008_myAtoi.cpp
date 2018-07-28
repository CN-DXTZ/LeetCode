/*******Íê½á*******/
#include<iostream>
#include<cctype>
using namespace std;
class Solution {
public:
	int myAtoi(string str)
	{
		// ÌÞ³ý¿Õ°×
		int i = 0;
		while (i < str.length()&&str[i] == ' ')
			i++;
		// ·ûºÅ
		bool negetive = 0;
		if (str[i] == '-' || str[i] == '+')
			negetive = (str[i++] == '-');
		// ¾ø¶ÔÖµ
		long long ans = 0;
		if (isdigit(str[i]))
		{
			while (isdigit(str[i]))
			{
				ans = ans * 10 + str[i] - '0';
				if ((ans - negetive) > INT_MAX)
					return negetive ? INT_MIN : INT_MAX;
				i++;
			}
		}
		if (negetive)
			ans = -ans;
		return (int)ans;
	}
}s;

int main()
{
	cout << s.myAtoi("42") << endl;
	cout << s.myAtoi("   -42") << endl;
	cout << s.myAtoi("4193 with words") << endl;
	cout << s.myAtoi("words and 987") << endl;
	cout << s.myAtoi("-91283472332") << endl;
	cout << s.myAtoi("  0000000000012345678") << endl;
	cout << s.myAtoi("2147483648") << endl;
	system("pause");
	return 0;
}