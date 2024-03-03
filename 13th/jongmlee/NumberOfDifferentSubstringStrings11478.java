import java.io.*;
import java.util.*;


public class NumberOfDifferentSubstringStrings11478 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i < line.length(); i++) {
			for (int j = i + 1; j <= line.length(); j++) {
				set.add(line.substring(i, j));
			}
		}
		System.out.println(set.size());
	}
}
