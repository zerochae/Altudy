package main.level_2;

import java.util.*;

public class 괄호변환 {

    public static String solution(String p) {
        if(p.length() == 0) {
            return "";
        }

        int open = 0;
        int close = 0;
        String u = "";
        String v = "";
        StringBuilder answer = new StringBuilder();

        for(int i = 0; i < p.length(); i++) {
            if(p.charAt(i) == '(') {
                open++;
            } else {
                close++;
            }

            if(open != 0 && open == close) {
                u = p.substring(0, i + 1);
                v = p.substring(i + 1);
                break;
            }
        }


        if(check(u)) {
            answer.append(u);
            answer.append(solution(v));
        } else {
            answer.append("(");
            answer.append(solution(v));
            answer.append(")");

            for(int i = 1; i < u.length() - 1; i++) {
                if(u.charAt(i) == '(') {
                    answer.append(")");
                } else {
                    answer.append("(");
                }
            }
        }

        return answer.toString();
    }

    public static boolean check(String u) {
        int left = 0;
        int right = 0;
        for(int i = 0; i < u.length(); i++) {
            if(u.charAt(i) == '(') {
                left++;
            } else if(u.charAt(i) == ')') {
                right++;
            }
            if(left < right){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
//        System.out.println(solution("(()()))(")); // (()())()
//        System.out.println(solution(")(")); // ()
//        System.out.println(solution("()))((()")); // ()(())()
//        System.out.println(solution(")()(()")); // ((()))
//        System.out.println(solution(")()()()(")); // (((())))
        System.out.println(solution("(()())))((")); // (()())(())
    }
}
