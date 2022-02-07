package programmers.level1;

import java.util.HashMap;
import java.util.Map;

public class 키패드누르기 {
    public static void main(String[] args) {
        solution(new int[]{1,3,4,5,8,2,1,4,5,9,5},"right");
        solution(new int[]{7,0,8,2,8,3,1,5,7,6,2},"left");
        solution(new int[]{1,2,3,4,5,6,7,8,9,0},"right");
    }

    public static String solution(int[] numbers, String hand) {
        StringBuilder answer = new StringBuilder();
        int[] right = {1,1};
        int[] left = {3,1};
        Map<Integer,int[]> pattern = new HashMap();
        pattern.put(1,new int[]{1,4});
        pattern.put(2,new int[]{2,4});
        pattern.put(3,new int[]{3,4});
        pattern.put(4,new int[]{1,3});
        pattern.put(5,new int[]{2,3});
        pattern.put(6,new int[]{3,3});
        pattern.put(7,new int[]{1,2});
        pattern.put(8,new int[]{2,2});
        pattern.put(9,new int[]{3,2});
        pattern.put(0,new int[]{2,1});

        for(int number : numbers){
            if(number == 1 || number == 4 || number == 7){
                left = pattern.get(number);
                answer.append("L");
            }else if(number == 3 || number == 6 || number == 9){
                right = pattern.get(number);
                answer.append("R");
            }else{
                int leftWidth = Math.abs(left[0]-pattern.get(number)[0]) + Math.abs(left[1]-pattern.get(number)[1]);
                int rightWidth = Math.abs(right[0]-pattern.get(number)[0]) + Math.abs(right[1]-pattern.get(number)[1]);
                if(leftWidth > rightWidth){
                    right = pattern.get(number);
                    answer.append("R");
                }else if(leftWidth < rightWidth){
                    left = pattern.get(number);
                    answer.append("L");
                }else{
                    if(hand.equals("right")){
                        right = pattern.get(number);
                        answer.append("R");
                    }else {
                        left = pattern.get(number);
                        answer.append("L");
                    }
                }
            }
        }
        System.out.println(answer.toString());
        return answer.toString();
    }
}
