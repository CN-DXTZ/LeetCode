#include<iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num)
	{
		// 4的幂次: 二进制时，从右往左数只有在第1,3,5...的某一奇数位为1
		// num & (num - 1)) == 0 ---- 保证二进制只有一位为1，即2的幂次
		// (num - 1) % 3 ---- 保证是4的幂次而非仅为2的幂次
		return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
	}
} s;

int main()
{
	cout << s.isPowerOfFour(16) << endl;
	cout << s.isPowerOfFour(15) << endl;
	system("pause");
	return 0;
}