#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	int countPrimes(int n)
	{
		if (n <= 2)
			return 0;

		vector<int> prime = { 2 };
		for (int i = 3; i < n; i++)
		{
			int j = 0, lim = sqrt(i);
			for (; prime[j] <= lim; j++)
			{
				if (!(i % prime[j]))
					break;
			}
			if (prime[j] > lim)
				prime.push_back(i);
		}
		return prime.size();
	}
} s;

int main()
{
	cout << s.countPrimes(3) << endl;
	cout << s.countPrimes(10) << endl;
	system("pause");
	return 0;
}