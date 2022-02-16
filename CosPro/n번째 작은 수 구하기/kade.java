package main.cos_pro;

import java.util.HashSet;
import java.util.Set;

public class n번째작은수구하기 {

    public static int solution(int[] card, int n) {
        Set<Integer> list = new HashSet<>();
        int[] output = new int[card.length];
        boolean[] visited = new boolean[card.length];
        perm(card, output, visited, 0, card.length, card.length, list, n);
        boolean flag = false;
        for(Integer i : list) {
            if (i == n) {
                flag = true;
                break;
            }
        }

        return flag ? list.size() : -1;
    }

    public static void perm(int[] arr, int[] output, boolean[] visited, int depth, int n, int r, Set<Integer> list, int target) {
        if(depth == r) {
            StringBuilder s = new StringBuilder();
            for(int o : output) {
                s.append(o);
            }
            if(Integer.parseInt(s.toString()) <= target) {
                list.add(Integer.parseInt(s.toString()));
            }
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                output[depth] = arr[i];
                perm(arr, output, visited, depth + 1, n, r, list, target);
                visited[i] = false;
            }
        }

    }

    public static void main(String[] args) {
        solution(new int[]{1, 2, 1, 3}, 1312); // 5
//        solution(new int[]{1, 1, 1, 2}, 1122); // -1
    }
}
