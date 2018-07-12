#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		unsigned int num = 0;
		// 获得符号，正为0，负为-1
		int flag1 = dividend >> 31, flag2 = divisor >> 31, flag = (flag1^flag2);
		// 取正
		unsigned int d1 = flag1 ? add(~dividend, 1) : dividend;
		unsigned int d2 = flag2 ? add(~divisor, 1) : divisor;
		// 减数=-d2
		unsigned int d3 = add(~d2, 1);

		while (d1 >= d2)
		{
			d1 = add(d1, d3);
			num++;
		}

		if (flag)
			return (int)(add(~num, 1));
		else
		{
			return (num == (1 << 31)) ? INT_MAX : (int)num;
		}
	}
	unsigned int add(unsigned int num1, unsigned int num2)
	{
		if (num2 == 0)
			return num1;
		unsigned int sum = num1 ^ num2;
		unsigned int carry = (num1 & num2) << 1;	//	进位
		return add(sum, carry);
	}
} s;

int main()
{
	cout << s.divide(10, 3) << endl;
	cout << s.divide(7, -3) << endl;
	cout << s.divide(0, 1) << endl;
	system("pause");
	return 0;
}
