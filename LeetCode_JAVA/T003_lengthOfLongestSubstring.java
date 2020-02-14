
public class T003_lengthOfLongestSubstring {

	public static void main(String args[]) {
		String s1 = "abcabcbb";
		String s2 = "bbbbb";
		String s3 = "pwwkew";

		System.out.println((new Solution()).lengthOfLongestSubstring(s1));
		System.out.println((new Solution()).lengthOfLongestSubstring(s2));
		System.out.println((new Solution()).lengthOfLongestSubstring(s3));
	}
}

// 滑动窗口+字符表查找（或哈希查找）
class Solution {
	public int lengthOfLongestSubstring(String s) {
		boolean[] table = new boolean[128];
		int left = 0, max_num = 0;
		for (int right = 0; right < s.length(); right++) {
			if (table[s.charAt(right)] == true) {
				if ((right - left) > max_num)
					max_num = (right - left);
				do {
					table[s.charAt(left)] = false;
				} while (s.charAt(left++) != s.charAt(right));
			}
			table[s.charAt(right)] = true;
		}
		if ((s.length() - left) > max_num)
			max_num = (s.length() - left);
		return max_num;
	}
}