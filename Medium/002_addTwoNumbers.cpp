/*******Íê½á*******/
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode ans(0);
		ListNode *p = &ans;
		int t_sum = 0, val1, val2;
		while (l1 || l2)
		{
			val1 = l1 ? l1->val : 0;
			val2 = l2 ? l2->val : 0;
			t_sum = val1 + val2 + t_sum / 10;

			p->next = new ListNode(t_sum % 10);
			p = p->next;

			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		if (t_sum / 10)
			p->next = new ListNode(1);
		return ans.next;
	}
} s;

int main()
{
	ListNode *l1 = new ListNode(9);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	ListNode *l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);
	ListNode *ans = s.addTwoNumbers(l1, l2);
	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}