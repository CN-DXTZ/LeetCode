public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }

    @Override
    public String toString() {
        String s = String.valueOf(this.val);
        ListNode p = this;
        while ((p = p.next) != null) {
            s += " -> " + String.valueOf(p.val);
        }
        return s;
    }
}