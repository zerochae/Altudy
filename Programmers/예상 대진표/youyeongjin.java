package programmers.level2;

public class 예상대진표 {
    public static void main(String[] args) {
        solution(8,4,7);
    }

    public static int solution(int n, int a, int b)
    {
        int answer = 1;
        a--;
        b--;
        while(a/2!=b/2) {
            a/=2;
            b/=2;
            answer++;
        }
        return answer;
    }
}
