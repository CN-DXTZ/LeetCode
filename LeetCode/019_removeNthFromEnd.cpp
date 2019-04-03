#include<iostream>
#include<vector> 
#include<string> 
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	// 法二:时间O(N),空间O(1)
	ListNode * removeNthFromEnd(ListNode* head, int n)
	{
		ListNode** slow = &head;// 以防删除头节点
		ListNode*fast = head;
		// 使快慢节点间隔为n
		while (--n)
			fast = fast->next;
		// 快慢节点同时步进，直至快节点至终点
		while (fast->next)
		{
			fast = fast->next;
			slow = &((*slow)->next);
		}
		*slow = (*slow)->next;
		return head;
	}

	// 法一:时间O(N),空间O(N)
	//ListNode * removeNthFromEnd(ListNode* head, int n)
	//{
	//	vector<ListNode*> temp;
	//	ListNode* p = head;
	//	while (p)
	//	{
	//		temp.push_back(p);
	//		p = p->next;
	//	}

	//	int size = temp.size();
	//	ListNode* next = temp[size - n]->next;
	//	// 边界:删除第一个
	//	if (size == n)
	//		return next;
	//	else
	//		temp[size - n - 1]->next = next;
	//	return head;
	//}
} s;

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode *ans = s.removeNthFromEnd(l1, 3);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}
