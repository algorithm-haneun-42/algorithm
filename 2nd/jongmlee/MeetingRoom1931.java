import java.util.*;

class MeetingRoom1931 {
	static class Meeting {
		int	start;
		int end;

		Meeting(int start, int end) {
			this.start = start;
			this.end = end;
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		List<Meeting> meetings = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			meetings.add(new Meeting(sc.nextInt(), sc.nextInt()));
		}

		meetings.sort((x1, x2) -> (x1.end != x2.end) ? x1.end - x2.end : x1.start - x2.start);

		int answer = 0, curEnd = 0;
		for (int i = 0; i < n; i++) {
			if (meetings.get(i).start >= curEnd) {
				answer++;
				curEnd = meetings.get(i).end;
			}
		}
		
		System.out.println(answer);
	}
}