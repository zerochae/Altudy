package main.level_2;

public class 다음큰숫자 {

    public static int solution(int n) {
        boolean flag = true;
        String binaryString = Integer.toBinaryString(n);
        int currentCnt = 0;
        for(int i = 0; i < binaryString.length(); i++) {
            if(binaryString.charAt(i) == '1') {
                currentCnt++;
            }
        }

        while(flag) {
            String temp = Integer.toBinaryString(++n);
            int j = 0;
            for(int i = 0; i < temp.length(); i++) {
                if(temp.charAt(i) == '1') {
                    j++;
                }
            }
            if(j == currentCnt) {
                flag = false;
            }
        }
        return n;
    }

    public static void main(String[] args) {
        solution(78);
    }
}
