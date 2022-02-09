package programmers.level1;

import java.util.Arrays;

public class 비밀지도 {
    public static void main(String[] args) {
        solution(5,new int[]{9,20,28,18,11},new int[]{30,1,21,17,28});
        solution(6,new int[]{46,33,33,22,31,50},new int[]{27,56,19,14,14,10});
    }

    public static String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0;i<n;i++){
            StringBuilder sb = new StringBuilder();
            for(int j=0;j<n;j++){
                if(arr1[i]%2 == 0 && arr2[i]%2 == 0){
                    sb.append(" ");
                }else{
                    sb.append("#");
                }
                arr1[i] = arr1[i]/2;
                arr2[i] = arr2[i]/2;
            }
            answer[i] = sb.reverse().toString();
        }
        for(String a : answer){
            System.out.println(a);
        }
        return answer;
    }
}
