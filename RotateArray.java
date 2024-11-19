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
        // Top row
        for (int j = idx; j < m - idx; j++) layer.add(arr[idx][j]);
        // Right column
        for (int i = idx + 1; i < n - idx; i++) layer.add(arr[i][m - idx - 1]);
        // Bottom row
        for (int j = m - idx - 2; j >= idx; j--) layer.add(arr[n - idx - 1][j]);
        // Left column
        for (int i = n - idx - 2; i > idx; i--) layer.add(arr[i][idx]);
        return layer.stream().mapToInt(Integer::intValue).toArray();
    }

    static void insertLayer(int idx, int[] layer) {
        int k = 0;
        // Top row
        for (int j = idx; j < m - idx; j++) arr[idx][j] = layer[k++];
        // Right column
        for (int i = idx + 1; i < n - idx; i++) arr[i][m - idx - 1] = layer[k++];
        // Bottom row
        for (int j = m - idx - 2; j >= idx; j--) arr[n - idx - 1][j] = layer[k++];
        // Left column
        for (int i = n - idx - 2; i > idx; i--) arr[i][idx] = layer[k++];
    }
}