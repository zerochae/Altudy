package main.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 카드 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        List<Integer> list = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        for(int i = 1; i <= num; i++) {
            list.add(i);
        }

        while(list.size() > 1) {
            result.add(list.remove(0));
            Integer remove = list.remove(0);
            list.add(remove);
        }
        result.add(list.get(0));
        result.forEach(item -> System.out.print(item + " "));
    }
}
