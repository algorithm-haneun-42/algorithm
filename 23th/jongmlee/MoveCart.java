import java.util.*;

public class MoveCart {
	static int[][] map;
	static int n, m;
	static boolean redEnd, blueEnd;
	static int[][] dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	static boolean[][][] v;
	static class Node {
		int x;
		int y;
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public int solution(int[][] maze) {
		int answer = 0;
		n = maze.length;
		m = maze[0].length;
		map = new int[n][m];
		v = new boolean[n][m][2];
		Node redStart = null;
		Node blueStart = null;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = maze[i][j];
				if (map[i][j] == 1) {
					redStart = new Node(i, j);
				} else if (map[i][j] == 2) {
					blueStart = new Node(i, j);
				}
			}
		}
		// red는 0, blue는 1
		v[redStart.x][redStart.y][0] = true;
		v[blueStart.x][blueStart.y][1] = true;
		answer = backtracking(redStart, blueStart, 0);
		
		return answer == Integer.MAX_VALUE ? 0 : answer;
	}
	static Node getNext(int x, int y, int idx) {
		int nx = x + dir[idx][0];
		int ny = y + dir[idx][1];
		return new Node(nx, ny);
	}
	static boolean isPossible(Node cntRed, Node red, Node cntBlue, Node blue) {
		if(red.x < 0 || red.y < 0 || red.x >= n || red.y >= m
			|| blue.x < 0 || blue.y < 0 || blue.x >= n || blue.y >= m
			|| map[red.x][red.y] == 5 || map[blue.x][blue.y] == 5) return false;
		
		if((cntRed.x == blue.x && cntRed.y == blue.y)
			&& (cntBlue.x == red.x && cntBlue.y == red.y)) return false;
		
		if((!redEnd && v[red.x][red.y][0])
			|| (!blueEnd && v[blue.x][blue.y][1])) return false;
		
		if(red.x == blue.x && red.y == blue.y) return false;
		return true;
	}
	static int backtracking(Node red, Node blue, int result) {
		if (redEnd && blueEnd) return result;
		int answer = Integer.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				Node nRed = (!redEnd) ? getNext(red.x, red.y, i) : red;
				Node nBlue = (!blueEnd) ? getNext(blue.x, blue.y, j) : blue;
				if (!isPossible(red, nRed, blue, nBlue)) continue;
				v[nRed.x][nRed.y][0] = true;
				v[nBlue.x][nBlue.y][1] = true;
				if(map[nRed.x][nRed.y] == 3) redEnd = true;
				if(map[nBlue.x][nBlue.y] == 4) blueEnd = true;
				
				answer = Math.min(answer, backtracking(nRed, nBlue, result + 1));
				
				v[nRed.x][nRed.y][0] = false;
				v[nBlue.x][nBlue.y][1] = false;
				redEnd = false;
				blueEnd = false;
			}
		}
		return answer;
}
}
