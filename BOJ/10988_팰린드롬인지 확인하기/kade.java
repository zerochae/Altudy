package main.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        boolean flag = true;
        for(int i = 0, j = str.length() - 1; i < str.length(); i++, j--) {
            if(str.charAt(i) != str.charAt(j)) {
                flag = false;
                break;
            }
        }
        System.out.println(flag ? 1 : 0);
    }
}