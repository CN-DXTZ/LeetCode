#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	// 法三:递归2	★递归调用的次序很重要
	//ListNode * reverseList(ListNode* head)
	//{
	//	if (!head || !(head->next))
	//		return head;

	//	ListNode* node = reverseList(head->next);
	//	head->next->next = head;
	//	head->next = NULL;
	//	return node;
	//}

	// 法一:迭代
	ListNode * reverseList(ListNode* head)
	{
		ListNode *Before = NULL, *Next = NULL;
		while (head)
		{
			Next = head->next;
			head->next = Before;

			Before = head;
			head = Next;
		}
		return Before;
	}

	// 法二:递归1(完全由法一改写)
	//ListNode * Before = NULL, *Next = NULL;
	//ListNode * reverseList(ListNode* head)
	//{
	//	if (!head)
	//		return Before;

	//	Next = head->next;
	//	head->next = Before;

	//	Before = head;
	//	return reverseList(Next);
	//}
} s;

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode *ans = s.reverseList(head);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}