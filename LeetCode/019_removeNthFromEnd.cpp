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
	// ����:ʱ��O(N),�ռ�O(1)
	ListNode * removeNthFromEnd(ListNode* head, int n)
	{
		ListNode** slow = &head;// �Է�ɾ��ͷ�ڵ�
		ListNode*fast = head;
		// ʹ�����ڵ���Ϊn
		while (--n)
			fast = fast->next;
		// �����ڵ�ͬʱ������ֱ����ڵ����յ�
		while (fast->next)
		{
			fast = fast->next;
			slow = &((*slow)->next);
		}
		*slow = (*slow)->next;
		return head;
	}

	// ��һ:ʱ��O(N),�ռ�O(N)
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
	//	// �߽�:ɾ����һ��
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
