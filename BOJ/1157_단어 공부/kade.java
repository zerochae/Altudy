package main.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toLowerCase().toCharArray();
        int[] cnt = new int[26];

        for(int i = 0; i < str.length; i++) {
            cnt[str[i] - 97]++;
        }
        int temp = 0;
        int index = 0;
        for(int i = 0; i < cnt.length; i++) {
            if(temp < cnt[i]) {
                temp = cnt[i];
                index = i;
            }
        }

        boolean flag = true;
        for(int i = 0; i < cnt.length; i++) {
            if(index == i) continue;
            if(temp == cnt[i] && cnt[i] != 0) {
                System.out.println("?");
                flag = false;
                break;
            }
        }

        if(flag) {
            System.out.println(((char)(index + 97) + "").toUpperCase());
        }
    }
}