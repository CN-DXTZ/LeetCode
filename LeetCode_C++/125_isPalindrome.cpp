#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution
{
public:
	bool isPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			while ((!isalnum(s[i])) && i < j)
				i++;
			while ((!isalnum(s[j])) && i < j)
				j--;
			if (tolower(s[i++]) != tolower(s[j--]))
				return false;
		}
		return true;
	}
} s;

int main()
{
	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << s.isPalindrome("race a car") << endl;
	cout << s.isPalindrome(".,") << endl;
	system("pause");
	return 0;
}