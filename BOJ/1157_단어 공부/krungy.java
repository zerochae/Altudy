import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        int arr[] = new int[26];
        int max = -1;
        int index = 0;
        int cnt = 0;

        in.close();

        for (int i = 0; i < 26; i++) {
            arr[i] = 0;
        }

        for (int i = 0; i < S.length(); i++)
        {
            if(S.charAt(i) >= 'a' && S.charAt(i) <= 'z')
                arr[S.charAt(i) - 'a']++;
            else if(S.charAt(i) >= 'A' && S.charAt(i) <= 'Z')
                arr[S.charAt(i) - 'A']++;
        }
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == max)
                cnt++;
        }

        char ans = (char)(index + 'A');
        
        if (cnt == 1)
            System.out.println(ans);
        else 
            System.out.println('?');
    }
}