import java.util.*;

class Emoticons {
	static int[] ratio = {0, 10, 20, 30 ,40};
	static int[] answer, arr, sale, semoticons;
	static int[][] susers;
	static int n;
	public int[] solution(int[][] users, int[] emoticons) {
		susers = users;
		semoticons = emoticons;
		answer = new int[2];
		n = emoticons.length;
		sale = new int[n];
		recul(0);
		return answer;
	}
	public static void recul(int depth) {
		if (depth == n) {
			arr = new int[2];
			cal();
			if (arr[0] > answer[0]) {
				answer[0] = arr[0];
				answer[1] = arr[1];
				return;
			}
			if (arr[0] == answer[0] && arr[1] > answer[1]) {
				answer[1] = arr[1];
			}
			return;
		}
		for (int i = 1; i <= 4; i++) {
			sale[depth] = i;
			recul(depth + 1);
		}
	}
	public static void cal() {
		double sum = 0;
		for (int i = 0; i < susers.length; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				if (susers[i][0] <= ratio[sale[j]]) {
					sum += semoticons[j] * (100 - ratio[sale[j]]) / 100;
				}
			}
			if (sum >= susers[i][1]) {
				arr[0]++;
			} else {
				arr[1] += sum;
			}
		}
	}
}
