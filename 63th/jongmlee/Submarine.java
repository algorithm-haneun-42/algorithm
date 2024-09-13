import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Submarine {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		Pattern pattern = Pattern.compile("(100+1+|01)+");
		if (pattern.matcher(s).matches()) {
			System.out.println("SUBMARINE");
		} else {
			System.out.println("NOISE");
		}
	}
}
