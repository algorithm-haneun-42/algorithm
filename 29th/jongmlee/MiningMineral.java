import java.util.*;

class MiningMineral {
	static int[][] weights = {{1,1,1},{5,1,1},{25,5,1}};
	public int solution(int[] picks, String[] minerals) {
		int answer = 0;
		int pickCnt = Arrays.stream(picks).sum();
		PriorityQueue<Group> groups = new PriorityQueue<>(Collections.reverseOrder()); 
		for (int i = 0; i < minerals.length; i += 5){
			Group g = new Group();
			g.list = new ArrayList<>();
			for (int j = i; j < (i + 5); j++) {
				if (j >= minerals.length)    break;
				if (minerals[j].equals("diamond"))  {
					g.list.add(0);
					g.total += 25;
				}
				else if(minerals[j].equals("iron")) {
					g.list.add(1);
					g.total += 5;
				}
				else {
					g.list.add(2);
					g.total += 1;
				}
			}
			groups.add(g);
			if (groups.size() == pickCnt)   break;
		}
		while(!groups.isEmpty()){
			Group g = groups.poll();
			int pick = 0;
			if (picks[0] > 0) {
				picks[0]--;
				pick = 0;
			}
			else if (picks[1] > 0) {
				picks[1]--;
				pick = 1;
			}
			else if (picks[2] > 0) {
				picks[2]--;
				pick = 2;
			}
			for(int m : g.list){
				answer += weights[pick][m];
			}
		}
		return answer;
	}
	static class Group implements Comparable<Group>{
		int total;
		ArrayList<Integer> list;
		
		@Override
		public int compareTo(Group g){
			return this.total - g.total;
		}
	}
}
