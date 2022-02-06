package main.level_2;

import java.util.*;

public class 올바른괄호 {

    public static boolean solution(String s) {
        int left = 0;
        int right = 0;
        boolean isTrue = true;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if(left < right) {
                isTrue = false;
                break;
            }
        }
        if(left != right) {
            isTrue = false;
        }

        return isTrue;
    }

    public static void main(String[] args) {
        boolean solution = solution("()())(");
        System.out.println(solution);
    }
}
