#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

// ����
class Solution {
public:
	// ����: ��������ν������ı���ɸ�� 
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

	// ��һ: �����ж������������ܷ�С����ƽ��������������
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