#include<iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num)
	{
		// 4���ݴ�: ������ʱ������������ֻ���ڵ�1,3,5...��ĳһ����λΪ1
		// num & (num - 1)) == 0 ���� ��֤������ֻ��һλΪ1����2���ݴ�
		// (num - 1) % 3 ���� ��֤��4���ݴζ��ǽ�Ϊ2���ݴ�
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