import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int answer = -1;
        if(n % 5 == 0) {
            answer = n / 5;
        } else {
            int threeCnt = 1;

            while(true) {
                if(3 * threeCnt > n) break;
                if((n - 3 * threeCnt) % 5 == 0) {
                    answer = threeCnt + ((n - 3 * threeCnt) / 5);
                    break;
                }
                threeCnt++;
            }

        }

        System.out.println(answer);
    }
}