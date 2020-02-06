#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
	// 分治
	int firstBadVersion(int n)
	{
		int min = 1, max = n, mid;
		while (max > min)
		{
			mid = (max - min) / 2 + min;
			if (isBadVersion(mid))
				max = mid;
			else
				min = mid + 1;
		}
		return max;
	}
	bool isBadVersion(int version)
	{
		return version >= 7;
	}
} s;

int main()
{
	cout << s.firstBadVersion(12) << endl;
	system("pause");
	return 0;
}