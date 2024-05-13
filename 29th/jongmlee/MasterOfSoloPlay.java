import java.util.*;

class MasterOfSoloPlay {
	int[] parents;
	
	public int solution(int[] cards) {
		int answer = 0;
		for (int i = 0; i < cards.length; i++) {
			cards[i] -= 1;
		}
		parents = new int[cards.length];
		for (int i = 0; i < parents.length; i++) {
			parents[i] = i;
		}
		for (int i = 0; i < cards.length; i++) {
			int start = i;
			int end = cards[i];

			while (parents[start] != parents[end]) {
				union(start, end);
				start = end;
				end = cards[end];
			}
		}
		
		int[] count = new int[cards.length];
		for(int i = 0; i < parents.length; i++){
			int key = parents[i];
			if(count[key] > 0){
				continue;
			}
			for(int j = 0; j < parents.length; j++){
				if(key == parents[j]){
					count[key]++;
				}
			}
		}
		Arrays.sort(count);
		answer = count[count.length - 1] * count[count.length - 2];
		return answer;
	}
	
	public void union(int a, int b) {
		a = find(a);
		b = find(b);
		
		if(a != b) {
			parents[b] = a;
		}
	}
	
	public int find(int a) {
		if(a == parents[a])
			return a;
		else
			return parents[a] = find(parents[a]);
	}
}