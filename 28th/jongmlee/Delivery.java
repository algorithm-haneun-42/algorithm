class Delivery {
	public long solution(int cap, int n, int[] deliveries, int[] pickups) {
		long answer = 0;
		int cnt, j;
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += deliveries[i] + pickups[i];
		}
		int i = n - 1;
		while (total > 0) {
			for (; i >= 0; i--) {
				if (deliveries[i] > 0 || pickups[i] > 0) {
					answer += (i + 1) * 2;
					cnt = cap;
					j = i;
					while (cnt > 0 && j >= 0) {
						if (deliveries[j] > 0) {
							cnt--; deliveries[j]--; total--;
						} else {
							j--;
						}
					}
					cnt = cap;
					j = i;
					while (cnt > 0 && j >= 0) {
						if (pickups[j] > 0) {
							cnt--; pickups[j]--; total--;
						} else {
							j--;
						}
					}
					break;
				}
			}
		}
		return answer;
	}
}