// 2018百度之星资格赛 度度熊拼三角

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);

		int i;
		for (i = n - 1; i >= 2; i--)
		{
			if (a[i] < (a[i - 1] + a[i - 2]))
			{
				printf("%d\n", a[i] + a[i - 1] + a[i - 2]);
				break;
			}
		}
		if (i < 2)
			printf("-1\n");
	}
	return 0;
}