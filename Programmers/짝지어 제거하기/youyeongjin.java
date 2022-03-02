package programmers.level1;

public class 짝지어제거하기 {
    public static void main(String[] args) {
        solution("baabaa");
        solution("cddc");
    }

    public static int solution(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == c) stack.pop();
            else stack.push(c);
        }

        return stack.isEmpty() ? 1 : 0;
    }
}
