// 2018百度之星资格赛 子串查询

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100005
int a[MAX][26]; // 记录从第1个字符到第i个字符26个字母各出现的次数
char s[MAX];

int main()
{
	int round;
	scanf("%d", &round);
	for (int CASE = 1; CASE <= round;)
	{
		printf("Case #%d:\n", CASE++);

		int n, q;
		scanf("%d%d", &n, &q);
		scanf("%s", s + 1); // 字符序号从1开始

		// 前缀和打表
		for (int i = 1; s[i]; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				a[i][j] = a[i - 1][j];
			}
			a[i][s[i] - 'A']++;
		}

		// 询问
		for (int i = 0; i < q; i++)
		{
			int left, right;
			scanf("%d%d", &left, &right);
			for (int j = 0; j < 26; j++)
			{
				if (a[right][j] - a[left - 1][j])
				{
					printf("%d\n", a[right][j] - a[left - 1][j]);
					break;
				}
			}
		}
	}
	return 0;
}