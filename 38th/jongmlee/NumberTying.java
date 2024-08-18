import java.io.*;
import java.util.*;

public class NumberTying {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<Integer> negative = new ArrayList<>();
		List<Integer> positive = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int tmp = Integer.parseInt(br.readLine());
			if (tmp <= 0) {
				negative.add(tmp);
			} else {
				positive.add(tmp);
			}
		}
		negative.sort(Comparator.naturalOrder());
		positive.sort(Comparator.naturalOrder());
		long answer = 0;
		for (int i = 1; i < negative.size(); i += 2) {
			answer += negative.get(i) * negative.get(i - 1);
		}
		if (negative.size() % 2 == 1) {
			answer += negative.get(negative.size() - 1);
		}
		for (int i = positive.size() - 2; i >= 0 ; i -= 2) {
			int n1 = positive.get(i);
			int n2 = positive.get(i + 1);
			if (n1 * n2 > n1 + n2) {
				answer += n1 * n2;
			} else {
				answer += n1 + n2;
			}
		}
		if (positive.size() % 2 == 1) {
			answer += positive.get(0);
		}
		System.out.println(answer);
	}
}
