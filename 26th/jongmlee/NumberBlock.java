class NumberBlock {
    public int[] solution(long begin, long end) {
        int[] answer = new int[(int)(end - begin + 1)];
    		int num=0;
    		long total=0;
            int j;
    		for(long i = begin; i <= end; i++) {
    			int sqrt = (int)Math.sqrt(i);
    			for(j = 2; j <= sqrt; j++) {
    				if(i % j == 0) {
    					long div = i / j;
    					if(div <= 10000000) {
    						answer[num] = (int)(div);
    						break;
    					} else {
                            answer[num] = Math.max(answer[num], j);
                        }
    				}
    			}
    			if(i != 1 && answer[num] == 0) {
                    answer[num] = 1;
                }
    			total += sqrt - j + 1;
    			num++;
    		}
    		return answer;
    }
}
