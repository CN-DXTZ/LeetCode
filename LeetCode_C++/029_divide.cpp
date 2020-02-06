// https://leetcode.com/problems/divide-two-integers/discuss/13407/Detailed-Explained-8ms-C++-solution
#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
	// 二分
	// dividend = divisor*2^n + divisor*2^(n - 1) + ... + divisor*2 + divisor*1;
	// 可只含部分子项
	int divide(int dividend, int divisor)
	{
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;

		int num = 0;
		// 获得符号，正为0，负为-1
		int flag1 = dividend >> 31, flag2 = divisor >> 31, flag = (flag1^flag2);
		// 取正
		unsigned int d1 = flag1 ? -dividend : dividend;
		unsigned int d2 = flag2 ? -divisor : divisor;

		while (d1 >= d2)
		{
			unsigned int sub = 1;
			unsigned int d3 = d1 >> 1;
			unsigned int d4 = d2;
			while (d3 >= d4)
			{
				d4 <<= 1;
				sub <<= 1;
			}
			d1 -= d4;
			num += sub;
		}
		return ((bool)flag ? -num : num);
	}
} s;

int main()
{
	cout << s.divide(10, 3) << endl;
	cout << s.divide(7, -3) << endl;
	cout << s.divide(INT_MIN, -1) << endl;
	cout << s.divide(INT_MIN, 1) << endl;
	system("pause");
	return 0;
}
