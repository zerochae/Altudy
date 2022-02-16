package main.cos_pro;

public class 소수의세제곱이몇개가있나요 {

    public int solution(int a, int b) {
        int answer = 0;

        for(int i = 1; i < b; i++) {
            int cnt = 0;
            int div = 2;
            while(div <= i) {
                if(i % div == 0) cnt++;
                div++;
            }
            if(cnt < 2) {
                if(Math.pow(i, 2) >= a && Math.pow(i, 2) <= b) answer++;
                if(Math.pow(i, 3) >= a && Math.pow(i, 3) <= b) answer++;
            }
        }

        return answer;
    }

}
