#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode * swapPairs(ListNode* head)
	{
		ListNode *ans = new ListNode(0);
		ans->next = head;

		ListNode *p = ans, *t1, *t2;
		while (p->next)
		{
			t1 = p->next;
			if (t1->next)
			{
				t2 = t1->next;

				t1->next = t2->next;
				t2->next = t1;
				p->next = t2;
			}
			else
				break;
			p = t1;
		}
		return ans->next;
	}
} s;

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode *ans = s.swapPairs(head);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}

	system("pause");
	return 0;
}