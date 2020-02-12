public class T035_searchInsert {

	public static void main(String[] arr) {
		int[] n1 = new int[] { 1, 3, 5, 6 };
		int t1 = 5, t2 = 2, t3 = 7, t4 = 0;

		System.out.println((new Solution()).searchInsert(n1, t1));
		System.out.println((new Solution()).searchInsert(n1, t2));
		System.out.println((new Solution()).searchInsert(n1, t3));
		System.out.println((new Solution()).searchInsert(n1, t4));
	}
}

// 二分查找
class Solution {
	public int searchInsert(int[] nums, int target) {
		if (nums[nums.length - 1] < target)
			return nums.length;
		int left = 0, right = nums.length - 1;
		while (left < right) {
			int mid = (left + right) >>> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
}