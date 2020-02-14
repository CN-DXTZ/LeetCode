public class T069_mySqrt {

	public static void main(String args[]) {
		int n1 = 4;
		int n2 = 8;

		System.out.println((new Solution()).mySqrt(n1));
		System.out.println((new Solution()).mySqrt(n2));
	}
}

// 二分查找
class Solution {
	public int mySqrt(int x) {
		long min = 0, max = x;
		while (min < max) {
			long mid = (min + max + 1) >>> 1;
			if (mid * mid <= x)
				min = mid;
			else
				max = mid - 1;
		}
		return (int) min;
	}
}