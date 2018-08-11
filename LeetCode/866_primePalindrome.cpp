#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool primeTable[10003] = { 1,1 };
vector<int> primeList;
class Solution
{
public:
	int primePalindrome(int N)
	{
		listPrime();
		string n_s = to_string(N);
		if (n_s.size() == 1)
		{
			for (int i = 0;; i++)
				if (primeList[i] >= N)
					return primeList[i];
		}
		bool flag = n_s.size() % 2;
		int max = pow(10, n_s.size() / 2), x = N / max;
		if (flag)
		{
			int mid = N / max % 10;
			x /= 10;
			if ((transpose(x) < (N % max)) && (++mid == 10))
				x++, mid = 0;
			return createPalindrome(max, x, mid);
		}
		else
		{
			if (transpose(x) < (N % max))
				x++;
			return createPalindrome(max, x);
		}
	}
	// 生成奇位数回文
	int createPalindrome(int max, int x, int mid)
	{
		int temp = (x * 10 + mid)*max + transpose(x), i;
		if (isPrime(temp))
			return temp;
		if (++mid == 10)
		{
			if (++x < max)
				return createPalindrome(max, x, 0);
			else
				return createPalindrome(max * 10, x);
		}
		return createPalindrome(max, x, mid);
	}
	// 生成偶位数回文
	int createPalindrome(int max, int x)
	{
		int temp = x * max + transpose(x), i;
		if (isPrime(temp))
			return temp;
		if (++x < max)
			return createPalindrome(max, x);
		else
			return createPalindrome(max, max / 10, 0);
	}
	// 转置
	int transpose(int x)
	{
		int ans = 0;
		while (x)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return ans;
	}
	// 判断素数
	int isPrime(int x)
	{
		int i = 0;
		while (i < primeList.size())
		{
			if (!(x % primeList[i++]))
				break;
		}
		if (x == primeList[i - 1] || i == primeList.size())
			return x;
		return 0;
	}
	// 素数打表
	void listPrime()
	{
		for (int i = 2; i < 102; i++)
		{
			if (!primeTable[i])
			{
				int j = i << 1;
				while (j < 10003)
				{
					primeTable[j] = 1;
					j += i;
				}
			}
		}
		for (int i = 2; i < 10003; i++)
			if (!primeTable[i])
				primeList.push_back(i);
	}
} s;

int main()
{
	cout << s.primePalindrome(0) << endl;
	cout << s.primePalindrome(2) << endl;
	cout << s.primePalindrome(6) << endl;
	cout << s.primePalindrome(8) << endl;
	cout << s.primePalindrome(13) << endl;
	cout << s.primePalindrome(102) << endl;
	cout << s.primePalindrome(192) << endl;
	cout << s.primePalindrome(3073704) << endl;
	cout << s.primePalindrome(100000000) << endl;
	system("pause");
	return 0;
}