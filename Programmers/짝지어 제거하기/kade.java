package main.level_2;

import java.util.*;

public class 짝지어제거하기 {

    public static int solution(String s) {
        Stack<Character> stack = new Stack<>();
        for(char c : s.toCharArray()) {
            if(stack.isEmpty()) {
                stack.add(c);
            } else if(stack.peek() == c) {
                stack.pop();
            } else {
                stack.add(c);
            }
        }

        return stack.size() == 0 ? 1 : 0;
    }

    public static void main(String[] args) {
        solution("baabaa");
        solution("cddc");
    }
}
