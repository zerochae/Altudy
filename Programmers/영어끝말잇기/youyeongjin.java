package programmers.level2;

import java.util.HashSet;
import java.util.Set;

public class 영어끝말잇기 {
    public static void main(String[] args) {
        solution(3,new String[]{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
        solution(5,new String[]{"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"});
        solution(2,new String[]{"hello", "one", "even", "never", "now", "world", "draw"});
    }

    public static int[] solution(int n, String[] words) {
        Set<String> set = new HashSet<>();
        set.add(words[0]);

        for(int i=1;i<words.length;i++){
            String pre = words[i-1];
            String now = words[i];
            if(set.contains(now) || pre.charAt(pre.length()-1)!=now.charAt(0)) {
                return new int[]{i%n+1, i/n+1};
            }
            set.add(now);
        }

        return new int[]{0,0};
    }
}
