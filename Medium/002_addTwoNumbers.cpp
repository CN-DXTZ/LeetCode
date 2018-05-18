#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *ans = NULL, *p = NULL;
		int CF = 0, t_sum = 0, v1, v2;
		while (l1|| l2)
		{
			v1 = l1 ? l1->val : 0;
			v2 = l2 ? l2->val : 0;
			t_sum = v1 + v2 + CF;

			CF = t_sum / 10;
			t_sum = t_sum % 10;
			
			if (ans == NULL)
			{
				ans = new ListNode(t_sum);
				p = ans;
			}
			else
			{
				p->next = new ListNode(t_sum);
				p = p->next;
			}
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		if(CF)
			p->next = new ListNode(CF);
		return ans;
	}
} s;

int main()
{

	ListNode *l1 = new ListNode(5);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *ans = s.addTwoNumbers(l1, l2);

	while (ans->next != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	cout << ans->val << endl;

	system("pause");
	return 0;
}