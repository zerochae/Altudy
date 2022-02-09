package programmers.level2;

import java.util.*;

public class 양궁대회 {
    static int[] apeachArray;
    static List<Score> list;

    public static void main(String[] args) {
        solution(5,new int[]{2,1,1,1,0,0,0,0,0,0,0});
        solution(1,new int[]{1,0,0,0,0,0,0,0,0,0,0});
        solution(9,new int[]{0,0,1,2,0,1,1,1,1,1,1});
        solution(10,new int[]{0,0,0,0,0,0,0,0,3,4,3});
    }

    public static int[] solution(int n, int[] info) {
        apeachArray = info;
        list = new ArrayList<Score>();

        int depth = Arrays.stream(apeachArray).max().getAsInt();
        for(;depth>=0 ; depth--){
            getScore(n,depth,new Score(new int[11]));
        }

        if(list.get(0).difference<=0){
            System.out.println(-1);
            return new int[]{-1};
        }

        for (int item :list.get(0).lionArray){
            System.out.print(item);
        }
        System.out.println();
        return list.get(0).lionArray;
    }

    public static void getScore(int N,int depth,Score score){
        for(int i=0; i<apeachArray.length;i++){
            if(apeachArray[i]==depth){
                if(N < depth+1){
                    getScore(N,depth-1,score);
                    break;
                }

                score.lionArray[i] = depth+1;
                N -= depth+1;
                for(int newDepth = depth-1;newDepth>=0 ; newDepth--){
                    int[] newArray = Arrays.copyOf(score.lionArray,11);
                    Score newScore = new Score(newArray);
                    getScore(N,newDepth,newScore);
                }
            }
        }

        if(depth == 0 && N !=0){
            score.lionArray[10] = N;
            N = 0;
        }

        if(N == 0){
            score.setDifference();
            if(list.size()==0){
                list.add(score);
            }else{
                list.add(score);
                Collections.sort(list);
                list.remove(1);
            }
        }
    }

    public static class Score implements Comparable<Score>{
        int[] lionArray;
        int difference;

        public Score(int[] lionArray) {
            this.lionArray = lionArray;
            this.difference = 0;
        }

        public int setDifference() {
            int lion = 0;
            int apeach = 0;
            for (int i=0;i<11;i++){
                if(lionArray[i]>apeachArray[i]){
                    lion += 10-i;
                }else if(lionArray[i]<=apeachArray[i] && apeachArray[i] !=0){
                    apeach += 10-i;
                }
            }
            this.difference = lion - apeach;
            return this.difference;
        }

        @Override
        public int compareTo(Score o) {
            if(this.difference > o.difference){
                return -1;
            }else if(this.difference == o.difference){
                for(int i=lionArray.length-1;i>0;i--){
                    if(this.lionArray[i] > o.lionArray[i]){
                        return -1;
                    }else if(this.lionArray[i] < o.lionArray[i]){
                        return 1;
                    }
                }
            }
            return 1;
        }
    }
}
