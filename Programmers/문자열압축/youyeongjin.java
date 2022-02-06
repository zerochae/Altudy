package programmers.level2;

public class 문자열압축 {
    public static void main(String[] args) {
        solution("aabbaccc");
        solution("ababcdcdababcdcd");
        solution("abcabcdede");
        solution("abcabcabcabcdededededede");
        solution("xababcdcdababcdcd");
    }

    public static int solution(String s) {
        int length = s.length();
        int answer = s.length();
        for(int i=1; i<=length; i++){
            String now = "";
            String comp = "";
            String temp = "";
            int cnt = 1;
            for(int j= 0; j<=s.length()/i;j++){
                int from = i*j; int to = i*(j+1);
                if(to > s.length()) to = s.length();
                now = comp;
                comp = s.substring(from, to);
                if(now.equals(comp)) cnt++;
                else{
                    if(cnt>1) temp += String.valueOf(cnt);
                    temp += now;
                    cnt = 1;
                }
            }
            if(cnt>1) temp += String.valueOf(cnt);
            temp += comp;
            answer = Math.min(temp.length(), answer);
        }
        return answer;
    }
}
