import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

class Solution {

    static int[][] arr;
    static Set<Integer> set;

     public static int[] solution(int rows, int columns, int[][] queries) {

        arr = new int[rows][columns];

        int number = 1;

        // 배열 생성
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = number;
                number++;
            }
        }

        int[] result = new int[queries.length]; // 결과가 저장될 배열
        int index = 0; // Index of Result[]

        for (int[] query : queries) {

            set = new HashSet<>();

            // 좌표 변수 선언
            int x1 = query[0] - 1;
            int y1 = query[1] - 1;
            int x2 = query[2] - 1;
            int y2 = query[3] - 1;

            // 모서리 값 저장
            int rightTop = arr[x1][y2];
            int leftBottom = arr[x2][y1];
            int rightBottom = arr[x2][y2];

            //시계방향 으로 회전  ( right -> down -> left -> up )
            //1회전 --> right
            right(x1, y2, y1);
            //2회전 --> down
            down(y2, x2, x1);
            //3회전 --> left
            left(x2, y2, y1);
            //4회전 --> up
            up(y1, x2, x1);

//            for(int[] s: arr){
//                System.out.println(Arrays.toString(s));
//            } // test 출력

            // 각 모서리 값 대입
            backUp(x2, x1, y2, y1, rightTop, leftBottom, rightBottom);
            result[index++] = minValue(set);
        }
        return result;
    }
    public static void right(int row, int max, int min) {

        for (int i = max; i > min; i--) {
            arr[row][i] = arr[row][i - 1];
            set.add(arr[row][i]);
        }
    }

    public static void down(int col, int max, int min) {

        for (int i = max; i > min; i--) {
            arr[i][col] = arr[i - 1][col];
            set.add(arr[i][col]);
        }
    }

    public static void left(int row, int max, int min) {

        for (int i = min; i < max; i++) {
            arr[row][i] = arr[row][i + 1];
            set.add(arr[row][i]);
        }
    }

    public static void up(int col, int max, int min) {

        for (int i = min; i < max; i++) {
            arr[i][col] = arr[i + 1][col];
            set.add(arr[i][col]);
        }
    }

    // set에 들어있는 최소값 비교
    public static int minValue(Set<Integer> set) {

        int MAX = Integer.MAX_VALUE;

        for (int value : set) {
            if (MAX > value) {
                MAX = value;
            }
        }
        return MAX;
    }
    // 모서리 값 대입
    public static void backUp(int x2, int x1, int y2, int y1, int rightTop, int leftBottom, int rightBottom) {

        set.add(rightTop);
        set.add(leftBottom);
        set.add(rightBottom);

        arr[x1 + 1][y2] = rightTop;
        arr[x2][y2 - 1] = rightBottom;
        arr[x2 - 1][y1] = leftBottom;
    }
}