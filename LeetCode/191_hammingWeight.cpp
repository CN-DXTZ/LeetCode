#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std;
class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int n = x xor y;
		int cnt = 0;
		while (n)
		{
			if (n & 1)
				cnt++;
			n >>= 1;
		}
		return cnt;
	}
} s;

int main()
{
	cout << s.hammingDistance(1, 4) << endl;
	system("pause");
	return 0;
}
