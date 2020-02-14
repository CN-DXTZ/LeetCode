public class T704_search {

	public static void main(String args[]) {
		int[] n1 = new int[] { -1, 0, 3, 5, 9, 12 };
		int t1 = 9, t2 = 2;

		System.out.println((new Solution()).search(n1, t1));
		System.out.println((new Solution()).search(n1, t2));
	}
}

// 二分查找
class Solution {
	public int search(int[] nums, int target) {
		int left = 0, right = nums.length - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
}