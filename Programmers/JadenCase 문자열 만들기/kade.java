package main.level_2;

public class JadenCase문자열만들기 {

    public static String solution(String s) {
        StringBuilder answer = new StringBuilder();
        char[] chars = s.toCharArray();
        int index = 0;
        for(char c : chars) {
            if(c == ' ') {
                answer.append(" ");
                index = 0;
            } else if(index == 0) {
                answer.append(Character.toUpperCase(c));
                index++;
            } else {
                answer.append(Character.toLowerCase(c));
                index++;
            }
        }

        return answer.toString();
    }

    public static void main(String[] args) {
        solution("a");
    }
}
