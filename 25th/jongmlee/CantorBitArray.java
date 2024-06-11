class CantorBitArray {
    public int solution(int n, long l, long r) {
        return recul(n, l, r, 1);
    }
    public static int recul(int n, long l, long r, long idx) {
        if (n == 0) {
            return 1;
        }
        int ans = 0;
        long tmp = (long)Math.pow(5, n - 1);
        for (int i = 0; i < 5; i++) {
            if (i == 2 || r < (tmp * i) + idx || l > (tmp * (i + 1)) + idx - 1) {
                continue;
            }
            ans += recul(n - 1, l, r, (tmp * i) + idx);
        }
        return ans;
    }
}