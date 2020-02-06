#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std;
class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t num = n & 1;
		for (int i = 0; i < 31; i++)
		{
			num <<= 1;
			n >>= 1;
			num |= (n & 1);
		}
		return num;
	}
} s;

int main()
{
	cout << s.reverseBits(43261596) << endl;
	system("pause");
	return 0;
}
