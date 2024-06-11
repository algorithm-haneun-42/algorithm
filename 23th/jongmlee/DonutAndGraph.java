import java.util.*;

class DonutAndGraph {
    static boolean[] visited;
    static int[] indegrees;
    static List<List<Integer>> graph = new ArrayList<>();
    static int[] answer = new int[4];
    public static int[] solution(int[][] edges) {
        int maxVertex = 0;
        for (int[] e : edges) {
            maxVertex = Math.max(Math.max(e[0], e[1]), maxVertex);
        }
        for (int i = 0; i < maxVertex + 1; i++) {
            graph.add(new ArrayList<>());
        }
		indegrees = new int[maxVertex + 1];
        visited = new boolean[maxVertex + 1];
        for (int i = 0; i < edges.length; i++) {
            graph.get(edges[i][0]).add(edges[i][1]);
            indegrees[edges[i][1]]++;
        }
		for (int i = 1; i < indegrees.length; i++) {
			if (indegrees[i] == 0 && graph.get(i).size() > 1) {
				answer[0] = i;
                visited[i] = true;
				break;
			}
		}
        int cnt = graph.get(answer[0]).size();
        for (int end : graph.get(answer[0])) {
            indegrees[end]--;
        }
        graph.set(answer[0], new LinkedList<>());
        
        answer[2] = getBar(); // 나가는 간선이 없는 정점
        answer[3] = getEight(); // 들어오는 간선 2개, 나가는 간선 2개인 정점
        answer[1] = cnt - (answer[2] + answer[3]);
        return answer;
    }
    static int getBar() {
        int cnt = 0;
        for (int i = 1; i < graph.size(); i++) {
            if (!visited[i] && graph.get(i).isEmpty()) {
                visited[i] = true;
                cnt++;
            }
        }
        return cnt;
    }
    static int getEight() {
        int cnt = 0;
        for (int i = 1; i < graph.size(); i++) {
            if (!visited[i] && graph.get(i).size() == 2 && indegrees[i] == 2) {
                visited[i] = true;
                cnt++;
            }
        }
        return cnt;
    }
	 // public static void main(String args[]) {
	 // 	int[][] edges = {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};
	 // 	System.out.println(Arrays.toString(Solution.solution(edges)));
	 // }
}
