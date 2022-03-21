package programmers.level1;

import java.util.*;

public class 예산 {
    public static void main(String[] args) {
        solution(new int[]{1,3,2,5,4},9);
        solution(new int[]{2,2,3,3},10);
    }

    public static int solution(int[] d, int budget) {
        Arrays.sort(d);

        for(int i=0;i<d.length;i++){
            if(i>0) d[i] += d[i-1];
            if(budget<d[i]) return i;
            i++;
        }
    }
}
