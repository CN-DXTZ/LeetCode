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
	// ����:
	//ListNode * removeNthFromEnd(ListNode* head, int n)
	//{
	//	ListNode** p_left = &head;// �Է�ɾ��ͷ�ڵ�
	//	ListNode*p_right = head;
	//	// ���ҽڵ����n
	//	for (int i = 1; i < n; ++i)
	//	{
	//		p_right = p_right->next;
	//	}
	//	// ���ҽڵ�ͬʱ������ֱ���ҽڵ����յ�
	//	while (p_right->next)
	//	{
	//		p_left = &((*p_left)->next);
	//		p_right = p_right->next;
	//	}
	//	*p_left = (*p_left)->next;
	//	return head;
	//}

	// ��һ:
	ListNode * removeNthFromEnd(ListNode* head, int n)
	{
		vector<ListNode*> temp;
		ListNode* p = head;
		while (true)
		{
			temp.push_back(p);
			if (!(p = p->next))
				break;
		}

		int size = temp.size();
		ListNode* next = temp[size - n]->next;
		// �߽�:ɾ����һ��
		if (size == n)
			return next;
		else
			temp[size - n - 1]->next = next;
		return head;
	}
} s;

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode *ans = s.removeNthFromEnd(l1, 1);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}
