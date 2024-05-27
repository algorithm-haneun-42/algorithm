import java.util.*;

class Solution {
    static class Point {
        int l;
        int lo;
        int hi;
        public Point(int l, int lo, int hi) {
            this.l = l;
            this.lo = lo;
            this.hi = hi;
        }
    }
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        PriorityQueue<Point> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.l == o2.l) {
                return o1.lo - o2.lo;
            } else {
                return o1.l - o2.l;
            }
        });
        int lo = 0;
        int hi = 0;
        int sum = 0;
        while (hi < sequence.length && lo <= hi) {
            // System.out.println(lo + " " + hi);
            sum = 0;
            if (lo == hi) {
                sum = sequence[lo];
            } else {
                for (int i = lo; i <= hi; i++) {
                    sum += sequence[i];
                }
            }
            if (sum < k) {
                hi++;
            } else if (sum > k) {
                lo++;
            } else {
                pq.add(new Point((hi - lo + 1), lo, hi));
                hi++;
            }
        }
        answer[0] = pq.peek().lo;
        answer[1] = pq.peek().hi;
        return answer;
    }
}