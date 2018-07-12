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
#define INT_MAX       2147483647
public:
	ListNode * mergeKLists(vector<ListNode*>& lists)
	{
		ListNode *ans = new ListNode(0);
		ListNode *p = ans;
		int i;
		while (1)
		{
			// ÅÐ¶Ï½áÊø
			for (i = 0; i < lists.size(); i++)
				if (lists[i])
					break;
			if (i == lists.size())
				break;

			int minVal = INT_MAX;
			ListNode** minNodeAdress = NULL;
			for (i = 0; i < lists.size(); i++)
			{
				if (!lists[i])
					continue;
				if (lists[i]->val < minVal)
				{
					minVal = lists[i]->val;
					minNodeAdress = &lists[i];
				}
			}

			*minNodeAdress = (*minNodeAdress)->next;
			p->next = new ListNode(minVal);
			p = p->next;
		}
		return ans->next;
	}
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

	ListNode *ans = s.mergeKLists(v);

	while (ans != NULL)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}

	system("pause");
	return 0;
}