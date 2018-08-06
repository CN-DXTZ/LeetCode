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
	// 法一:时间O(N),空间O(1)
	ListNode * reverseKGroup(ListNode *head, int k)
	{
		if (!head || k == 1)
			return head;

		ListNode *HEAD = new ListNode(0);
		HEAD->next = head;

		ListNode *slow = head, *fast = HEAD;
		// fast快k
		for (int i = 0; i < k && fast; i++)
			fast = fast->next;
		ListNode *Before = HEAD, *Next = NULL, *K_head = HEAD, *K_tail = head;
		while (fast)
		{
			for (int i = 0; i < k; i++)
			{
				fast = fast ? fast->next : NULL;

				// 翻转
				Next = slow->next;
				slow->next = Before;
				Before = slow;
				slow = Next;
			}

			K_head->next = Before;
			K_tail->next = Next;

			K_head = K_tail;
			K_tail = Next;
		}
		return HEAD->next;
	}

	// 法一:时间O(N),空间O(K)
	//ListNode * reverseKGroup(ListNode* head, int k)
	//{
	//	ListNode *ans = new ListNode(0);
	//	ans->next = head;

	//	ListNode *p = ans;
	//	vector<ListNode*> v(k);
	//	int i;
	//	while (p->next)
	//	{
	//		v.clear();
	//		v.push_back(p->next);
	//		for (i = 1; i < k; i++)
	//		{
	//			if (v.back()->next)
	//				v.push_back(v.back()->next);
	//			else
	//				return ans->next;
	//		}

	//		v[0]->next = v.back()->next;
	//		p->next = v.back();
	//		for (int i = v.size() - 1; i > 0; i--)
	//			v[i]->next = v[i - 1];
	//		p = v[0];
	//	}
	//	return ans->next;
	//}
} s;

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode *ans = s.reverseKGroup(head, 4);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}