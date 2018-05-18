#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string convertToBase7(int num)
	{
		if (num == 0)
			return "0";
		string str = "";
		int t = abs(num);
		while (t > 0)
		{
			str += '0' + t % 7;
			t = t / 7;
		}
		if (num < 0)
			str = str + "-";
		reverse(str.begin(), str.end());
		return str;
	}
} s;

int main()
{
	cout << s.convertToBase7(100) << endl;
	cout << s.convertToBase7(-7) << endl;
	cout << s.convertToBase7(0) << endl;
	system("pause");
	return 0;
}