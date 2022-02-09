package programmers.level2;

import java.util.ArrayList;
import java.util.List;

public class 거리두기확인하기 {
    public static void main(String[] args) {
        solution(new String[][]{{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    }

    public static int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        point: for(int i=0;i< places.length;i++){
            List<Person> list = new ArrayList<>();
            for(int j=0;j<places[i].length;j++){
                char[] chars = places[i][j].toCharArray();
                for(int k=0;k< chars.length;k++){
                    if (chars[k]=='P'){
                        list.add(new Person(j,k));
                    }
                }
            }

            for(int j=0;j<list.size();j++){
                for (int k=j+1;k<list.size();k++){
                    int space = list.get(j).getSpace(list.get(k));
                    if(space==1){
                        continue point;
                    }else if(space==2){
                        int[][] checkPoint = list.get(j).getCheckPoint(list.get(k));
                        for(int l=0;l<checkPoint.length;l++){
                            if(places[i][checkPoint[l][0]].charAt(checkPoint[l][1])=='O'){
                                continue point;
                            }
                        }
                    }else{
                        continue;
                    }
                }
            }
            answer[i] = 1;
        }
        return answer;
    }

    public static class Person{
        int x;
        int y;

        public Person(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getSpace(Person person){
            return Math.abs(this.x - person.x) + Math.abs(this.y - person.y);
        }

        public int[][] getCheckPoint(Person person){
            int[][] checkPoint;
            int xSpace = Math.abs(this.x-person.x);
            if(xSpace == 2){
                int xHigh = Math.max(this.x,person.x);
                checkPoint = new int[][]{{xHigh-1,this.y}};
            }else if(xSpace == 1){
                int xHigh = Math.max(this.x,person.x);
                int yHigh = Math.max(this.y,person.y);
                if((this.x> person.x && this.y> person.y) || (this.x< person.x && this.y< person.y)){
                    checkPoint = new int[][]{{xHigh-1,yHigh},{xHigh,yHigh-1}};
                }else{
                    checkPoint = new int[][]{{xHigh-1,yHigh-1},{xHigh,yHigh}};
                }
            }else{
                int yHigh = Math.max(this.y,person.y);
                checkPoint = new int[][]{{this.x,yHigh-1}};
            }
            return checkPoint;
        }
    }
}
