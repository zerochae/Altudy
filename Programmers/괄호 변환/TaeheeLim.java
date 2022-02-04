package com.example.codingtest.level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class 괄호변환 {
    public static void main(String[] args) {
        String data1 = "(()())()";
        String data2 = ")(";
        String data3 = "()))((()";

        System.out.println(solution(data3));
    }

    public static String solution(String p){
        if(p.equals("")){
            return "";
        }

        String u = "";
        String v = "";
        int first = 0;
        int second = 0;

        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '(') {
                first++;
            } else {
                second++;
            }
            u += p.charAt(i);
            if(first == second) {
                v = p.substring(i + 1);
                break;
            }
        } //for 끝

        // u가 올바른 괄호 문자열인지 확인
        if(check(u)) { // 올바른 괄호 문자열 일때
            // v에 대해 1단계부터 다시 확인
            u += solution(v);
        } else { // 올바르지 않은 괄호 문자열 일때
            // 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
            String temp = "(";
            // 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
            temp += solution(v);
            // ')'를 다시 붙입니다.
            temp += ")";
            // u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
            for(int i = 1; i < u.length() -1; i++){
                if(u.charAt(i) == '('){
                    temp += ')';
                } else {
                    temp += '(';
                }
            }
            // 생성된 문자열을 반환합니다.
            return temp;
        }
        return u;
    }

    public static boolean check(String p) {
        if(p.charAt(0) == ')'){
            return false;
        }
        Stack<String> stack = new Stack<>();
        for(int i = 0; i < p.length(); i++){
            if(p.charAt(i) == '('){
                stack.push("(");
            } else {
                if(!stack.isEmpty()){
                    stack.pop();
                }
            }
        }
        if(stack.isEmpty()){
            return true;
        }
        return false;
    }
}
