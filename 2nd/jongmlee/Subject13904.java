import java.util.*;

class Subject13904 {
	static class Subject {
		int deadline;
		int score;

		Subject(int deadline, int score) {
			this.deadline = deadline;
			this.score = score;
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Subject[] arr = new Subject[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Subject(sc.nextInt(), sc.nextInt());
		}

		int max, maxIdx, answer = 0;
		for (int i = n; i >= 1; i--) {
			max = 0;
			maxIdx = -1;
			for (int j = 0; j < n; j++) {
				// i일보다 deadline이 크거나 같은것중에 score가 제일 큰 수
				if (i <= arr[j].deadline && arr[j].score > max) {
					max = arr[j].score;
					maxIdx = j;
				}
			}
			if (maxIdx >= 0) {
				answer += max;
				arr[maxIdx].deadline = 0;
			}
		}
		System.out.println(answer);
	}
}