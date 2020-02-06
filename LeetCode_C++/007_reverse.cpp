#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int reverse(int x)
	{
		bool  negetive = (x < 0);
		if (negetive)
			x = -x;

		long long ans = 0;
		while (x > 0)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		// 溢出
		if ((ans - negetive) > INT_MAX)
			return 0;
		// 恢复符号
		if (negetive)
			ans = -ans;
		return (int)ans;
	}
} s;

int main()
{
	cout << s.reverse(123) << endl;
	cout << s.reverse(-321) << endl;
	cout << s.reverse(120) << endl;
	system("pause");
	return 0;
}