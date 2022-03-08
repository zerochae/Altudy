package programmers.level2;

public class 큰수만들기 {
    public static void main(String[] args) {
        solution("1924",2);
        solution("1231234",3);
        solution("4177252841",4);

    }

    public static String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        int index = 0;
        int max = 0;
        for(int i=0; i<number.length() - k; i++) {
            max = 0;
            for(int j = index; j<= k+i; j++) {
                if(max < number.charAt(j)-'0') {
                    max = number.charAt(j)-'0';
                    index = j+1;
                }
            }
            sb.append(max);
        }
        return sb.toString();
    }
}
