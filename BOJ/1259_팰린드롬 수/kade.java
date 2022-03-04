import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 펠린드롬수 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while(!(s = br.readLine()).equals("0")) {
            boolean answer = true;
            for(int i = 0, j = s.length() - 1; i < s.length(); i++, j--) {
                if(s.charAt(i) != s.charAt(j)) {
                    answer = false;
                    break;
                }
            }
            System.out.println(answer ? "yes" : "no");
        }
    }
}
