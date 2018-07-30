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
	ListNode * reverseList(ListNode* head)
	{

	}
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