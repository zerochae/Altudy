package programmers.level2;

public class 주식가격 {

    public static void main(String[] args) {
        solution(new int[]{1,2,3,2,3});
    }

    public static int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        for(int i=0; i<prices.length-1;i++){
            int cnt = 0;
            for(int j=i;j<prices.length-1;j++){
                if(prices[i]>prices[j]) break;
                cnt++;
            }
            answer[i] = cnt;
        }
        answer[prices.length-1] = 0;

        return answer;
    }
}
