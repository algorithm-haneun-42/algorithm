class Joystick {
	//public static void main(String args[]) {
	//	System.out.println(solution("JOAPOAAAAAAAAQP"));
	//}
	public static int solution(String name) {
		int answer = 0;
		int pre = 0;
		int cnt = Integer.MAX_VALUE;
		for (int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			if (c != 'A') {
				answer += Math.min('Z' - c + 1, c - 'A');
				if (i == 0) continue;
				int tmp = pre + name.length() - i;
				cnt = Math.min(cnt, tmp + Math.min(pre, name.length() - i));
				System.out.println("i = " + i + ", tmp = " + tmp + ", pre = " + pre + ", name.length() - i = " + (name.length() - i));
				pre = i;
			}
		}
		cnt = Math.min(pre, cnt);
		return answer + cnt;
	}
}