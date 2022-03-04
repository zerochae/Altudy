import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 명령프롬포트 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        StringBuilder str = null;
        for(int i = 0; i < num; i++) {
            String temp = br.readLine();
            if(str == null) {
                str = new StringBuilder(temp);
            } else {
                for(int j = 0; j < str.length(); j++) {
                    if(str.charAt(j) != temp.charAt(j)) {
                        str.replace(j, j + 1, "?");
                    }
                }
            }
        }
        System.out.println(str);
    }
}
