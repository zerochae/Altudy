package programmers.level2;

public class 일이사나라의숫자 {
    public static void main(String[] args) {
        solution(10);
    }

    public static String solution(int n) {
        StringBuilder sb = new StringBuilder();
        while(n>0){
            switch (n%3){
                case 0: sb.append(4); n-=1;break;
                case 1: sb.append(1); break;
                case 2: sb.append(2); break;
            }
            n /= 3;
        }
        return sb.reverse().toString();
    }
}
