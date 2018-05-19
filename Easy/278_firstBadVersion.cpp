#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool isBadVersion(int version)
{
	return version >= 1;
}
class Solution {
public:
	// ¶þ·Ö
	int firstBadVersion(int n)
	{
		int min = 1, max = n, mid;
		while (abs(max - min) > 1)
		{
			mid = (max - min) / 2 + min;
			if (isBadVersion(mid))
				max = mid;
			else
				min = mid;
		}
		if (isBadVersion(min))
			return min;
		return max;
	}
} s;

int main()
{
	cout << s.firstBadVersion(2) << endl;
	system("pause");
	return 0;
}