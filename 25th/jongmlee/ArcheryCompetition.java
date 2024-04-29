public class ArcheryCompetition {
	static int[] res = {-1};
	static int[] lion;
	static int max = Integer.MIN_VALUE;

	public int[] solution(int n, int[] info) {
		lion = new int[11];
		recul(info, 1, n);
		return res;
	}

	public static void recul(int[] info, int depth, int n) {
		if(depth == n + 1) {
			int aPoint = 0;
			int lPoint = 0;
			for(int i = 0; i <= 10; i++) {
				if(info[i] != 0 || lion[i] != 0) {
					if(info[i] < lion[i]) {
						lPoint += 10 - i;
					} else {
						aPoint += 10 - i;
					}
				}
			}
			if(lPoint > aPoint) {
				if(lPoint - aPoint >= max) {
					res = lion.clone();
					max = lPoint - aPoint;
				}
			}
			return ;
		}
		for(int j = 0; j <= 10 && lion[j] <= info[j]; j++) {
			lion[j]++;
			recul(info, depth + 1, n);
			lion[j]--;
		}
	}
}
