import java.util.*;

class ThatSong {
    static class Info {
        int id;
        int time;
        String title;
        int[] sheet;
        public Info(int id, String info) {
            String[] infos = info.split(",");
            int start = (Integer.parseInt(infos[0].split(":")[0]) * 60) + Integer.parseInt(infos[0].split(":")[1]);
            int end = (Integer.parseInt(infos[1].split(":")[0]) * 60) + Integer.parseInt(infos[1].split(":")[1]);
            this.id = id;
            this.time = end - start;
            this.title = infos[2];
            this.sheet = convert(infos[3]);
        }
    }
    public String solution(String m, String[] musicinfos) {
        PriorityQueue<Info> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.time == o2.time) {
                return o1.id - o2.id;
            } else {
                return o2.time - o2.time;
            }
        });
        int[] im = convert(m);
        for (int i = 0; i < musicinfos.length; i++) {
            Info cur = new Info(i, musicinfos[i]);
            pq.add(cur);
            List<Integer> list = new ArrayList<>();
            int p = 0;
            for (int j = 0; j < cur.time; j++) {
                list.add(cur.sheet[p]);
                p = p == cur.sheet.length ? 0 : p;
                if (!sm.substring(0, sb.length()).equals(sb.toString())) {
                    sb = new StringBuilder();
                    continue;
                }
                if (sm.equals(sb.toString())) {
                    pq.add(cur);
                    break;
                }
            }
        }
        return pq.poll().title;
    }
    static int[] convert(String s) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && s.charAt(i + 1) == '#') {
                list.add((int)s.charAt(i) + 100);
                i++;
                continue;
            }
            list.add((int)s.charAt(i));
        }
        int[] array = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            array[i] = list.get(i);
        }
        return array;
    }
}