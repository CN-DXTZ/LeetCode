#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

// 质数
class Solution {
public:
	// 法二: 打表——依次将质数的倍数筛除 
	int countPrimes(int n)
	{
		if (n <= 2)
			return 0;

		vector<bool> table_prime(n, true);
		int sum = n >> 1;
		int lim = sqrt(n - 1);
		for (int i = 3; i <= lim; i += 2)
		{
			if (table_prime[i])
			{
				for (int j = i * i, step = i << 1; j < n; j += step)
					if (table_prime[j])
						table_prime[j] = false, --sum;

			}
		}
		return sum;
	}

	// 法一: 依次判断质数——看能否被小于其平方根的质数整除
	//int countPrimes(int n)
	//{
	//	if (n <= 2)
	//		return 0;

	//	vector<int> prime = { 2 };
	//	for (int i = 3; i < n; i += 2)
	//	{
	//		int j = 0, lim = sqrt(i);
	//		for (; prime[j] <= lim; j++)
	//		{
	//			if (!(i % prime[j]))
	//				break;
	//		}
	//		if (prime[j] > lim)
	//			prime.push_back(i);
	//	}
	//	return prime.size();
	//}
} s;

int main()
{
	time_t start, stop;
	int a = 10000000;

	start = time(NULL);
	cout << s.countPrimes(a) << endl;
	stop = time(NULL);
	cout << stop - start << endl;

	start = time(NULL);
	cout << s.countPrimes(a) << endl;
	stop = time(NULL);
	cout << stop - start << endl;

	system("pause");
	return 0;
}