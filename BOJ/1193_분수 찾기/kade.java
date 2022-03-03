import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long num = Integer.parseInt(br.readLine());

        long depth = 1;
        long temp = 0;
        for (long i = 1; i < num; i++) {
            if(temp + i < num) {
                temp += i;
                depth++;
            } else {
                break;
            }
        }

        if(depth % 2 == 0) {
            System.out.println(num - temp + "/" + (depth + 1 - (num - temp)));
        } else {
            System.out.println((depth + 1 - (num - temp)) + "/" + (num - temp));
        }
    }
}