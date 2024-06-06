class MatrixMultiplication {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr2[0].length];
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2[0].length; j++) {
                answer[i][j] = cal(arr1, arr2, i, j);
            }
        }
        return answer;
    }
    static int cal(int[][] arr1, int[][] arr2, int x, int y) {
        int sum = 0;
        for (int i = 0; i < arr1[0].length; i++) {
                sum += arr1[x][i] * arr2[i][y]; 
        }
        return sum;
    }
}