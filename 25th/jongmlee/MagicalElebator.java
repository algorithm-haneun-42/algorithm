import java.io.*;
import java.util.*;

class Solution {
	public int solution(int storey) {
		int answer = 0;
		int prev = -1;
		
		while (storey > 0) {
			int digit = storey % 10;
			if (digit < 5) {
				answer += digit;
			} else if (digit > 5) {
				answer += 10 - digit;
				storey += digit;
			} else if (digit == 5) {
				answer += digit;
				if (prev >= 6) {
					storey++;
				}
				if (prev == -1) {
					if ((storey / 10) % 10 >= 5) {
						storey += digit;
					}
				}
			}
			storey /= 10;
			prev = digit;
		}
		return answer;
}
}