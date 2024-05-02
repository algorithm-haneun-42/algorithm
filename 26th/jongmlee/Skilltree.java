import java.util.*;

public class Skilltree {
	public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for (int i = 0; i < skill_trees.length; i++) {
            String cur = skill_trees[i];
            if (isPossible(skill, cur)) answer++;
        }
        return answer;
    }
    public static boolean isPossible(String skill, String cur) {
        int s = 0;
        HashSet<Character> set = new HashSet<>();
        for (char c : skill.toCharArray()) {
            set.add(c);
		}
        for (int i = 0; i < cur.length(); i++) {
            if (skill.charAt(s) == cur.charAt(i)) {
                s++;
                if (s >= skill.length()) break;
                continue;
            }
            if (set.contains(cur.charAt(i))) {
                return false;
            }
        }
        return true;
    }
}
