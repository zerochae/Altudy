package main.cos_pro;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 체스의나이트 {

    public int solution(String pos) {
        int answer = 0;
        char[] chars = pos.toCharArray();
        int[] column = new int[]{1, 2, 3, 4, 5, 6, 7, 8};
        int row = Integer.parseInt(chars[1] + "");
        int col = column[(int)chars[0] % 65];
        List<int[]> list = new ArrayList<>();

        list.add(new int[]{row + 1, col - 2});
        list.add(new int[]{row + 1, col + 2});
        list.add(new int[]{row - 1, col - 2});
        list.add(new int[]{row - 1, col + 2});

        list.add(new int[]{row + 2, col - 1});
        list.add(new int[]{row + 2, col + 1});
        list.add(new int[]{row - 2, col - 1});
        list.add(new int[]{row - 2, col + 1});

        for(int i = 0; i < list.size(); i++) {
            if(
                    (list.get(i)[0] <= 8 && list.get(i)[1] <= 8) &&
                    (list.get(i)[0] > 0 && list.get(i)[1] > 0)
            ) {
                answer++;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        체스의나이트 sol = new 체스의나이트();
        String pos = "A7";
        int ret = sol.solution(pos);

        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}
