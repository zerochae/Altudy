import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    /**
     * AABCDD
     * afzz
     * 09121
     * a8EWg6
     * P5h3kx
     *
     * Aa0aPAf985Bz1EhCz2W3D1gkD6x
     *
     * ABCDE
     * abcde
     * 01234
     * FGHIJ
     * fghij
     *
     * Aa0FfBb1GgCc2HhDd3IiEe4Jj
     */

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] strs = new String[5];
        int maxLen = 0;
        for (int i = 0; i < 5; i++) {
            strs[i] = br.readLine();
            if(strs[i].length() > maxLen) {
                maxLen = strs[i].length();
            }
        }
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < maxLen; i++) {
            sb.append(strs[0].length() - 1 < i ? "" : strs[0].charAt(i));
            sb.append(strs[1].length() - 1 < i ? "" : strs[1].charAt(i));
            sb.append(strs[2].length() - 1 < i ? "" : strs[2].charAt(i));
            sb.append(strs[3].length() - 1 < i ? "" : strs[3].charAt(i));
            sb.append(strs[4].length() - 1 < i ? "" : strs[4].charAt(i));
        }
        System.out.println(sb);
    }
}
