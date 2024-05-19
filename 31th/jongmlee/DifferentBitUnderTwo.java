class DifferentBitUnderTwo {
	public long[] solution(long[] numbers) {
		long[] answer = new long[numbers.length];
		for (int i = 0; i < numbers.length; i++) {
			answer[i] = diff(numbers[i]);
		}
		return answer;
	}
	static long diff(long n) {
		String s = Long.toBinaryString(n);
		StringBuilder ret = new StringBuilder();
		if (n % 2 == 0) {
			return n + 1;
		}
		int idx = s.lastIndexOf('0');
		if (idx == -1) {
			ret.append("10").append(s.substring(1, s.length()));
		} else {
			ret.append(s.substring(0, idx)).append("10").append(s.substring(idx + 2, s.length()));
		}
		return Long.parseLong(ret.toString(), 2);
	}
}