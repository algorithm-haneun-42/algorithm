import java.io.*;
import java.util.*;

public class RotateArray {
    static int[][] arr;
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        rotateArray(r);

        // 출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void rotateArray(int r) {
        int layers = Math.min(n, m) / 2;
        for (int i = 0; i < layers; i++) {
            int[] temp = extractLayer(i);
            int len = temp.length;
            int[] rotated = new int[len];
            for (int j = 0; j < len; j++) {
                rotated[(j + r) % len] = temp[j];
            }
            insertLayer(i, rotated);
        }
    }

	static int[] extractLayer(int idx) {
		List<Integer> layer = new ArrayList<>();
		int startRow = idx, endRow = n - idx - 1;
		int startCol = idx, endCol = m - idx - 1;
	
		// 아래쪽 (Top -> Bottom)
		for (int i = startRow; i <= endRow; i++) layer.add(arr[i][startCol]);
		// 오른쪽 (Left -> Right)
		for (int j = startCol + 1; j <= endCol; j++) layer.add(arr[endRow][j]);
		// 위쪽 (Bottom -> Top)
		for (int i = endRow - 1; i >= startRow; i--) layer.add(arr[i][endCol]);
		// 왼쪽 (Right -> Left)
		for (int j = endCol - 1; j > startCol; j--) layer.add(arr[startRow][j]);
	
		return layer.stream().mapToInt(Integer::intValue).toArray();
	}

	static void insertLayer(int idx, int[] layer) {
		int k = 0;
		int startRow = idx, endRow = n - idx - 1;
		int startCol = idx, endCol = m - idx - 1;
	
		// 아래쪽 (Top -> Bottom)
		for (int i = startRow; i <= endRow; i++) arr[i][startCol] = layer[k++];
		// 오른쪽 (Left -> Right)
		for (int j = startCol + 1; j <= endCol; j++) arr[endRow][j] = layer[k++];
		// 위쪽 (Bottom -> Top)
		for (int i = endRow - 1; i >= startRow; i--) arr[i][endCol] = layer[k++];
		// 왼쪽 (Right -> Left)
		for (int j = endCol - 1; j > startCol; j--) arr[startRow][j] = layer[k++];
	}
}