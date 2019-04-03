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
		ListNode *HEAD = new ListNode(0);
		HEAD->next = head;

		ListNode *p = HEAD, *t1, *t2;
		while ((t1 = p->next) && (t1->next))
		{
			t2 = t1->next;
			// 交换
			t1->next = t2->next;
			t2->next = t1;
			p->next = t2;
			p = t1;
		}
		return HEAD->next;
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