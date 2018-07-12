#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
#define INT_MAX       2147483647
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *ans = new ListNode(0);
		ListNode *p = ans;
		int  v1, v2;
		while (l1 || l2)
		{
			v1 = l1 ? l1->val : INT_MAX;
			v2 = l2 ? l2->val : INT_MAX;
			if (v1 <= v2)
			{
				l1 = l1 ? l1->next : NULL;
				p->next = new ListNode(v1);
				p = p->next;
			}
			else
			{
				l2 = l2 ? l2->next : NULL;
				p->next = new ListNode(v2);
				p = p->next;
			}
		}
		return ans->next;
	}
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