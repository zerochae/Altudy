package BackJoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 수정렬하기_2750 {

    static int[] arr;
    static boolean[] boolArr;

    // 풀이방법
    // 1. array.sort가 아닌 선택 정렬
    // 2. boolean arr로 카운트 정렬
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        arr = new int[N];

        /*
         * -1000~ 1000
         * 중간값 (0)은 1000을 의미
         */
        boolArr = new boolean[2001];

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            boolArr[Integer.parseInt(s) + 1000] = true;
            arr[i] = Integer.parseInt(s);
        }

        selectSort(N);
        countSort();
    }

    public static void selectSort(int N) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i : arr) {
            System.out.println("selectSort : " + i);
        }
    }

    public static void countSort() {
        for (int i = 0; i < 2001; i++) {
            if (boolArr[i]) {
                System.out.print("countSort : ");
                System.out.println(i - 1000);
            }
        }
    }
}
