class Solution {
	public int solution(int n) {
		String bin = Integer.toBinaryString(n);
		int origin = oneCnt(bin);
		while (true) {
			if (origin == oneCnt(Integer.toBinaryString(++n))) {
				break;
			}
		}
		return n;
	}
	public int oneCnt(String s) {
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				cnt++;
			}
		}
		return cnt;
	}
}