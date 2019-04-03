#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	// 法二:时间O(N),空间O(1)
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *HEAD = new ListNode(0);
		ListNode *p = HEAD;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p = p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p = p->next = l2;
				l2 = l2->next;
			}
		}
		// 有一条链合并完后, 其余部分直接指向另外链的子链的头节点即可
		p->next = l1 ? l1 : l2;
		return HEAD->next;
	}

	// 法一:时间O(N),空间O(N)
	//ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
	//{
	//	ListNode *HEAD = new ListNode(0);
	//	ListNode *p = HEAD;
	//	int  v1, v2;
	//	while (l1 || l2)
	//	{
	//		v1 = l1 ? l1->val : INT_MAX;
	//		v2 = l2 ? l2->val : INT_MAX;
	//		if (v1 <= v2)
	//		{
	//			l1 = l1 ? l1->next : NULL;
	//			p->next = new ListNode(v1);
	//			p = p->next;
	//		}
	//		else
	//		{
	//			l2 = l2 ? l2->next : NULL;
	//			p->next = new ListNode(v2);
	//			p = p->next;
	//		}
	//	}
	//	return HEAD->next;
	//}
} s;

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	ListNode *ans = s.mergeTwoLists(l1, l2);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}

	system("pause");
	return 0;
}