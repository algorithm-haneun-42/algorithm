import java.util.*;

class Knight7562 {
    static class Point {
        int x;
        int y;
        int d;
        Point(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }
    static boolean[][] board;
    static int[][] dir = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Queue<Point> q = new LinkedList<>();
        while (t-- > 0) {
            int l = sc.nextInt();
            board = new boolean[l][l];
            Point pos = new Point(sc.nextInt(), sc.nextInt(), 0);
            Point target = new Point(sc.nextInt(), sc.nextInt(), 0);
            q.clear();
            board[pos.x][pos.y] = true;
            q.add(pos);
            while(!q.isEmpty()) {
                Point cur = q.poll();
                if (cur.x == target.x && cur.y == target.y) {
                    System.out.println(cur.d);
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int newX = cur.x + dir[i][0];
                    int newY = cur.y + dir[i][1];
                    if (newX >= 0 && newX < l && newY >= 0 && newY < l && !board[newX][newY]) {
                        board[newX][newY] = true;
                        q.add(new Point(newX, newY, cur.d + 1));
                    }
                }
            }
        }
    }
}