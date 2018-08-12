#include<iostream>
using namespace std;

class Solution {
public:
	// 法三: 
	int const Max3PowerInt = 1162261467; // =3^19 (3^20 = 3486784401 > INT_MAX)
	bool isPowerOfThree(int n)
	{
		if (n <= 0 || n > Max3PowerInt)
			return false;
		return Max3PowerInt % n == 0;
	}

	// 法二: 循环
	//bool isPowerOfThree(int n)
	//{
	//	if (n > 1)
	//		while (!(n % 3))
	//			n /= 3;
	//	return n == 1;
	//}

	// 法一: 递归
	//bool isPowerOfThree(int n)
	//{
	//	if (n > 1)
	//		return !(n % 3) && isPowerOfThree(n / 3);
	//	else
	//		return n == 1;
	//}
} s;

int main()
{
	cout << s.isPowerOfThree(27) << endl;
	cout << s.isPowerOfThree(0) << endl;
	cout << s.isPowerOfThree(9) << endl;
	cout << s.isPowerOfThree(45) << endl;

	system("pause");
	return 0;
}