package programmers.level2;

import java.util.*;

public class 괄호회전하기 {
    public static void main(String[] args) {
        solution("[](){}");
        //solution("}]()[{");
        //solution("[)(]");
        //solution("}}}");
    }

    public static int solution(String s) {
        int answer = 0;
        for(int i=0; i<s.length(); i++){
            Stack<String> stack = new Stack();
            s = s.substring(1,s.length())+s.substring(0,1);

            for(int j=0; j<s.length(); j++){
                String word = s.substring(j,j+1);
                if(stack.isEmpty()){
                    stack.push(word);
                    continue;
                }

                if(word.equals(")") && stack.peek().equals("(")){
                    stack.pop();
                }else if(word.equals("}") && stack.peek().equals("{")){
                    stack.pop();
                }else if(word.equals("]") && stack.peek().equals("[")){
                    stack.pop();
                }else{
                    stack.push(word);
                }
            }

            if(stack.isEmpty()){
                answer++;
            }

        }
        return answer;
    }
}


