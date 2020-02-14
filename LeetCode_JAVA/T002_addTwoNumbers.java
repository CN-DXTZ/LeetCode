public class T002_addTwoNumbers {

	public static void main(String args[]) {
		ListNode l1 = new ListNode(2);
		l1.next = new ListNode(4);
		l1.next.next = new ListNode(3);
		ListNode l2 = new ListNode(5);
		l2.next = new ListNode(6);
		l2.next.next = new ListNode(4);

		ListNode ans = (new Solution()).addTwoNumbers(l1, l2);
		System.out.println(ans);
	}
}

class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode ans = new ListNode(0);
		ListNode p = ans;
		int CF = 0;
		while (l1 != null || l2 != null) {
			int val1 = (l1 != null) ? l1.val : 0;
			int val2 = (l2 != null) ? l2.val : 0;

			p = p.next = new ListNode(val1 + val2 + CF);
			CF = (p.val) / 10;
			p.val -= CF * 10;

			if (l1 != null)
				l1 = l1.next;
			if (l2 != null)
				l2 = l2.next;
		}
		if (CF == 1)
			p.next = new ListNode(1);
		return ans.next;
	}
}