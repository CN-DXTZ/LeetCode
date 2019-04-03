#include<iostream>
#include<algorithm>
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
	// 法二: 分治:两两合并 - 时间O(NlogK),空间O(1)
	ListNode * mergeKLists(vector<ListNode *>& lists)
	{
		if (lists.empty()) 
			return NULL;
		
		while (lists.size() > 1) 
		{
			lists.push_back(mergeTwoLists(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists.front();
	}
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *HEAD = new ListNode(0);
		ListNode *p = HEAD;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p = p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p = p->next = l2;
				l2 = l2->next;
			}
		}
		p->next = l1 ? l1 : l2;
		return HEAD->next;
	}

	// 法一: 遍历每个链表合并 - 时间O(NK),空间O(1)
	//ListNode * mergeKLists(vector<ListNode *>& lists)
	//{
	//	ListNode *HEAD = new ListNode(0);
	//	ListNode *p = HEAD;

	//	int cnt = 0, n = lists.size();
	//	while (cnt < n)
	//	{
	//		cnt = 1;
	//		int min_Val = INT_MAX, min_Idx = -1;
	//		for (int i = 0; i < n; i++)
	//		{
	//			if (!lists[i])
	//				cnt++;
	//			else if (lists[i]->val < min_Val)
	//			{
	//				min_Idx = i;
	//				min_Val = lists[i]->val;
	//			}
	//		}
	//		if (min_Idx == -1)
	//			break;

	//		p = p->next = lists[min_Idx];
	//		lists[min_Idx] = (lists[min_Idx])->next;
	//	}
	//	return HEAD->next;
	//}
} s;

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	ListNode *l3 = new ListNode(2);
	l3->next = new ListNode(6);
	vector<ListNode*> v = { l1,l2,l3 };
	vector<ListNode*> v2 = { NULL,NULL };

	ListNode *ans = s.mergeKLists(v);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}

	system("pause");
	return 0;
}