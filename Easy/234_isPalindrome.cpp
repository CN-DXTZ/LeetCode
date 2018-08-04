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
	// 时间O(n), 空间O(1)
	bool isPalindrome(ListNode* head)
	{
		if (!head || !(head->next))
			return true;

		ListNode *slow = head, *fast = head;
		ListNode *Before = NULL, *Next = NULL;
		// slow标记前半部分, fast标记后半部分
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;

			// 反转前半部分
			Next = slow->next;
			slow->next = Before;
			Before = slow;
			slow = Next;
		}

		// 确定前后两半部分的起点
		if (fast->next)	// 偶数个节点
		{
			fast = slow->next;
			slow->next = Before;
		}
		else			// 奇数个节点
		{
			fast = slow->next;
			slow = Before;
		}

		// 迭代判断是否回文
		while (slow)
		{
			if (slow->val != fast->val)
				return false;
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}
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
	p3->next->next->next->next = new ListNode(1);

	cout << s.isPalindrome(p1) << endl;
	cout << s.isPalindrome(p2) << endl;
	cout << s.isPalindrome(p3) << endl;
	system("pause");
	return 0;
}