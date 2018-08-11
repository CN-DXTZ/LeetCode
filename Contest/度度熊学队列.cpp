// 2018百度之星资格赛 度度熊学队列

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct ListNode {
	int val;
	ListNode *next, *prev;
	ListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

ListNode *a[150001][2];

void f1()
{
	int u, w, val;
	scanf("%d%d%d", &u, &w, &val);

	ListNode *node = new ListNode(val);
	if (!a[u][0])
		a[u][0] = a[u][1] = node;
	else if (w)
	{
		a[u][1]->next = node;
		node->prev = a[u][1];
		a[u][1] = node;
	}
	else
	{
		a[u][0]->prev = node;
		node->next = a[u][0];
		a[u][0] = node;
	}
}

void f2()
{
	int u, w;
	scanf("%d%d", &u, &w);

	if (!a[u][0])
		printf(":::-1\n");
	else if (w)
	{
		printf(":::%d\n", a[u][1]->val);
		a[u][1] = a[u][1]->prev;

		if (!a[u][1])
			a[u][0] = NULL;
		else
			a[u][1]->next = NULL;
	}
	else
	{
		printf(":::%d\n", a[u][0]->val);
		a[u][0] = a[u][0]->next;

		if (!a[u][0])
			a[u][1] = NULL;
		else
			a[u][0]->prev = NULL;
	}
}

void f3()
{
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);

	if (!a[v][0]);
	else if (!a[u][0])
	{
		a[u][0] = a[v][0];
		a[u][1] = a[v][1];
		a[v][0] = a[v][1] = NULL;
	}
	else if (w)
	{
		a[u][1]->next = a[v][1];
		ListNode *node = a[v][1]->prev;
		a[v][1]->prev = a[u][1];
		while (node != a[v][0])
		{
			ListNode *temp = node->next;
			node->next = node->prev;
			node->prev = temp;
			node = node->next;
		}
		a[v][0]->prev = a[v][0]->next;
		a[v][0]->next = NULL;

		a[u][1] = a[v][0];
		a[v][0] = a[v][1] = NULL;
	}
	else
	{
		a[u][1]->next = a[v][0];
		a[v][0]->prev = a[u][1];
		a[u][1] = a[v][1];
		a[v][0] = a[v][1] = NULL;
	}

}

int main()
{
	int n, q;
	while (cin >> n >> q)
	{
		memset(a, NULL, sizeof(ListNode*) * 300002);
		int f;
		while (q--)
		{
			scanf("%d", &f);
			if (f == 1)
				f1();
			else if (f == 2)
				f2();
			else
				f3();
		}
	}
	system("pause");
	return 0;
}