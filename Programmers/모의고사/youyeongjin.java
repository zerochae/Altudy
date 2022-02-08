package programmers.level1;

import java.util.Arrays;

public class 모의고사 {
    public static void main(String[] args) {
        solution(new int[]{1,2,3,4,5});
        solution(new int[]{1,3,2,4,2});
    }

    public static int[] solution(int[] answers) {
        int[] winner = {};
        int[][] randomly = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
        int[] humans = new int[3];
        for(int i=0; i<humans.length;i++){
            for(int j=0; j<answers.length;j++){
                if(answers[j] == randomly[i][j % randomly[i].length]){
                    humans[i]++;
                }
            }
        }
        int max = Arrays.stream(humans).max().getAsInt();
        for(int i=0 ; i<humans.length;i++){
            if(max == humans[i]){
                winner = Arrays.copyOf(winner,winner.length+1);
                winner[winner.length-1] = i+1;
            }
        }
        return winner;
    }
}
