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
	// 法一: 标记遍历过的节点
	bool hasCycle(ListNode *head)
	{
		ListNode *flag = new ListNode(0), *next;
		while (head)
		{
			next = head->next;
			if (flag == next)
				return true;
			else
			{
				head->next = flag;
				head = next;
			}
		}
		return false;
	}

	// 法二: 快走2步, 慢走1步
	//bool hasCycle(ListNode *head)
	//{
	//	if (!head)
	//		return false;

	//	ListNode *fast = head, *slow = head;
	//	while (fast->next && fast->next->next)
	//	{
	//		fast = fast->next->next;
	//		slow = slow->next;
	//		if (fast == slow)
	//			return true;
	//	}
	//	return false;
	//}
} s;

int main()
{
	ListNode *p1 = new ListNode(1);
	p1->next = new ListNode(2);
	ListNode *p2 = new ListNode(1);
	p2->next = new ListNode(2);
	p2->next->next = new ListNode(2);
	p2->next->next->next = new ListNode(1);
	ListNode *p3 = new ListNode(1);
	p3->next = new ListNode(2);
	p3->next->next = new ListNode(3);
	p3->next->next->next = new ListNode(2);
	p3->next->next->next->next = p3;

	cout << s.hasCycle(p1) << endl;
	cout << s.hasCycle(p2) << endl;
	cout << s.hasCycle(p3) << endl;
	cout << s.hasCycle(NULL) << endl;
	system("pause");
	return 0;
}