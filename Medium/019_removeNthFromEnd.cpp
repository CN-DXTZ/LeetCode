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
	ListNode * removeNthFromEnd(ListNode* head, int n)
	{
		vector<ListNode*> temp;
		ListNode* pt = head;
		while (true)
		{
			temp.push_back(pt);
			if (!(pt = pt->next))
				break;
		}
		// ɾ��ԭʼ(���Ǳ߽�)
		int sz = temp.size();
		if (sz == 1)
			return NULL;
		// �߽�:ɾ�����һ��
		ListNode* next = (n == 1) ? NULL : temp[sz - n + 1];
		// �߽�:ɾ����һ��
		if (sz == n)
			return next;
		else
			temp[sz - n - 1]->next = next;
		return head;
	}
} s;

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	//ListNode *ans = s.removeNthFromEnd(l1, 1);
	//ListNode *ans = s.removeNthFromEnd(l1, 2);
	ListNode *ans = s.removeNthFromEnd(l1, 3);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}
	system("pause");
	return 0;
}
