import java.util.*;

class  Camping4796{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int p, l, v, answer;
		int i = 0;
        while (true) {
			answer = 0;
			l = sc.nextInt(); // l일을 사용 가능
            p = sc.nextInt(); // 연속하는 p일 중
            v = sc.nextInt(); // v짜리 휴가
			if (l == 0 && p == 0 && v == 0) {
				break;
			}
            while (v > 0) {
                if (v > p) {
                    v -= p;
                    answer += l;
                } else {
					answer = v > l ? answer + l : answer + v;
					v = 0;
				}
			}
			System.out.printf("Case %d: %d\n", ++i , answer);
		}
    }
}