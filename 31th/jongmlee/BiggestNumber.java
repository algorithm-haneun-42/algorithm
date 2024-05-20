import java.util.*;

class BiggestNumber {
	public String solution(int[] numbers) {
		String[] sn = new String[numbers.length];
		for (int i = 0 ; i < numbers.length; i++) {
			sn[i] = Integer.toString(numbers[i]);
		}
		Arrays.sort(sn, (x, y) -> (y + x).compareTo(x + y));
		if (sn[0].equals("0")) return "0";
		StringBuilder sb = new StringBuilder();
		for (String x : sn) {
			sb.append(x);
		}
		return sb.toString();
	}
}