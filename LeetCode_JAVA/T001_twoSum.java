import java.util.HashMap;

public class T001_twoSum {

	public static void main(String[] arr) {
		int[] nums = new int[] { 2, 7, 11, 15 };
		int target = 9;
		
		int[] ans = (new Solution()).twoSum(nums, target);
		System.out.println(ans[0] + "-----" + ans[1]);

	}
}

// 法一：暴力，O(n^2)
// 法二：快排，O(nlogn)
// 法三：哈希查找，O(n)
class Solution {
	public int[] twoSum(int[] nums, int target) {
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int index = 0; index < nums.length; index++) {
			int another = target - nums[index];
			// 哈希查找对应余数
			if (hm.get(another) != null) {
				return new int[] { hm.get(another), index };
			} else {
				hm.put(nums[index], index);
			}
		}
		return null;
	}
}