import java.util.*;

class Solution {
    static class Node {
        int idx;
        int prio;
        public Node(int idx, int prio) {
            this.idx = idx;
            this.prio = prio;
        }
    }
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            q.add(new Node(i, priorities[i]));
        }
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (check(q, cur)) {
                q.add(cur);
            } else {
                answer++;
                if (cur.idx == location) {
                    return answer;
                }
            }
        }
        return answer;
    }
    static public boolean check(Queue<Node> q, Node cur) {
        for (Node n : q) {
            if (n.prio > cur.prio) {
                return true;
            }
        }
        return false;
    }
}