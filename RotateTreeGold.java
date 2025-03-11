import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RotateTreeGold {
	private static class Node {
		int root;
		Node left;
		Node right;

		public Node(int root) {
			this.root = root;
		}

		public void set(Node left, Node right) {
			this.left = left;
			this.right = right;
		}
	}

	private static int visitedCnt = 0;
	private static boolean[] visited;
	private static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		n = Integer.parseInt(br.readLine());
		Node[] nodes = new Node[n];
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			nodes[i] = new Node(i);
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int left = Integer.parseInt(st.nextToken()) - 1;
			int right = Integer.parseInt(st.nextToken()) - 1;

			if (left != -2 && right != -2) {
				nodes[a].set(nodes[left], nodes[right]);
			} else if (left != -2) {
				nodes[a].set(nodes[left], null);
			} else if (right != -2) {
				nodes[a].set(null, nodes[right]);
			}
		}
		System.out.println(dfs(nodes[0]));
	}

	private static int dfs(Node now) {
		int score = 0;

		if (now.left != null && !visited[now.left.root]) {
			score++;
			score += dfs(now.left);
			score++;
		}

		visited[now.root] = true;
		visitedCnt++;

		if (now.right != null && !visited[now.right.root]) {
			score++;
			score += dfs(now.right);
			if (visitedCnt == n) {
				return score;
			}
			score++;
		}

		return score;

	}
}