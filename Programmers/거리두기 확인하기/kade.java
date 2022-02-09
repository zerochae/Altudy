package main.level_2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 거리두기확인하기 {

    public static int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        int index = -1;
        for(String[] place : places) {
            index++;
            List<int[]> positions = new ArrayList<>();
            for(int i = 0; i < place.length; i++) {
                if(place[i].contains("P")) {
                    for(int j = 0; j < place[i].length(); j++) {
                        if(place[i].charAt(j) == 'P') {
                            positions.add(new int[]{i, j});
                        }
                    }
                }
            }

            if(positions.size() == 0) {
                answer[index] = 1;
                continue;
            }

            boolean flag = true;
            for(int i = 0; i < positions.size(); i++) {
                for(int j = i + 1; j < positions.size(); j++) {
                    int r = Math.abs(positions.get(i)[0] - positions.get(j)[0]);
                    int c = Math.abs(positions.get(i)[1] - positions.get(j)[1]);

                    if(r + c <= 2) {
                        int[] current = positions.get(i);
                        int[] target = positions.get(j);
                        if(current[0] == target[0] && place[current[0]].charAt(current[1] + 1) != 'X') {
                            flag = false;
                            break;
                        } else if(current[0] != target[0] && (place[target[0] - 1].charAt(target[1]) != 'X' || place[current[0] + 1].charAt(current[1]) != 'X')) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) {
                    break;
                }
            }
            if(flag) {
                answer[index] = 1;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(new String[][] {
                {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        });
    }
}
