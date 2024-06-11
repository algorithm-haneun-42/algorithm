import java.util.*;

class DoingSubject {
	static class Subject {
		String name;
		int start;
		int taskTime;
		int progress;
		public Subject(String name, String sstart, String staskTime) {
			this.name = name;
			String[] chunks = sstart.split(":");
			this.start = Integer.parseInt(chunks[0]) * 60 + Integer.parseInt(chunks[1]);
			this.taskTime = Integer.parseInt(staskTime);
			this.progress = 0;
		}
	}
	public String[] solution(String[][] plans) {
		PriorityQueue<Subject> subjects = new PriorityQueue<>((o1, o2) -> o1.start - o2.start);
		Stack<Subject> ready = new Stack<>();
		for (String[] x : plans) {
			subjects.add(new Subject(x[0], x[1], x[2]));
		}
		int len = subjects.size();
		subjects.forEach(x -> System.out.println(x.name));
		Subject cur = subjects.poll();
		int time = cur.start;
		cur.progress++;
		List<String> answer = new ArrayList<>();
		while (true) {
			if (cur.progress == cur.taskTime) {
				answer.add(cur.name);
				if (answer.size() == len) break;
				if (!ready.isEmpty()) cur = ready.pop();
				else if (!subjects.isEmpty()) {
					cur = subjects.poll();
					time += cur.start - time;
				}
			} else {
				if (!subjects.isEmpty()) {
					if (subjects.peek().start == time) {
						ready.push(cur);
						cur = subjects.poll();
					}
				}
				cur.progress++;
				time++;
			}
		}
		return answer.toArray(new String[0]);
	}
}