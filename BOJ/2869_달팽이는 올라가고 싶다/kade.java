import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int up = Integer.parseInt(str[0]);
        int down = Integer.parseInt(str[1]);
        int totalLen = Integer.parseInt(str[2]);

        System.out.println((totalLen - down - 1) / (up - down) + 1);
    }
}