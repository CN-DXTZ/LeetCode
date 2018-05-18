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
		if ((ans - negetive) > ((1 << 31) - 1))
			return 0;
		if (negetive)
			ans = -ans;
		return (int)ans;
	}
} s;

int main()
{
	int a = 123, b = -321, c = 120;
	cout << s.reverse(a) << endl;
	cout << s.reverse(b) << endl;
	cout << s.reverse(c) << endl;
	system("pause");
	return 0;
}