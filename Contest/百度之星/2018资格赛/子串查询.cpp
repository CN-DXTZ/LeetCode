// 2018�ٶ�֮���ʸ��� �Ӵ���ѯ

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100005
int a[MAX][26]; // ��¼�ӵ�1���ַ�����i���ַ�26����ĸ�����ֵĴ���
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
		scanf("%s", s + 1); // �ַ���Ŵ�1��ʼ

		// ǰ׺�ʹ��
		for (int i = 1; s[i]; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				a[i][j] = a[i - 1][j];
			}
			a[i][s[i] - 'A']++;
		}

		// ѯ��
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