package programmers.level2;

import java.util.Arrays;

public class 행렬테두리회전하기 {
    public static void main(String[] args) {
        solution(6,6,new int[][]{{2,2,5,4},{3,3,6,6},{5,1,6,3}});
        solution(3,3,new int[][]{{1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3}});
        solution(100,97,new int[][]{{1,1,100,97}});
    }

    public static int[] solution(int rows, int columns, int[][] queries) {
        int[][] box = new int[rows][columns];

        int cnt = 1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                box[i][j] = cnt++;
            }
        }

        int[] answer = {};

        for(int i=0;i< queries.length;i++){
            int row = queries[i][0]-1;
            int column = queries[i][1]-1;
            int rowGoal = queries[i][2]-1;
            int columnGoal = queries[i][3]-1;
            int temp = box[row][column];
            int min = temp;
            int newTemp = 0;

            for(int j=column;j<columnGoal;j++){
                newTemp = box[row][j+1];
                box[row][j+1] = temp;
                temp = newTemp;
                min = Integer.min(min,temp);
            }

            for(int j=row;j<rowGoal;j++){
                newTemp = box[j+1][columnGoal];
                box[j+1][columnGoal] = temp;
                temp = newTemp;
                min = Integer.min(min,temp);
            }

            for(int j=columnGoal;j>column;j--){
                newTemp = box[rowGoal][j-1];
                box[rowGoal][j-1] = temp;
                temp = newTemp;
                min = Integer.min(min,temp);
            }

            for(int j=rowGoal;j>row;j--){
                newTemp = box[j-1][column];
                box[j-1][column] = temp;
                temp = newTemp;
                min = Integer.min(min,temp);
            }

            answer = Arrays.copyOf(answer,answer.length+1);
            answer[answer.length-1] = min;
        }

        return answer;
    }
}
