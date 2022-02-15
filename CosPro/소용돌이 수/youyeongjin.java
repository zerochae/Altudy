package cospro;

public class 소용돌이숫자 {
    public static void main(String[] args) {
        int n1 = 3;
        int ret1 = solution(n1);
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

        int n2 = 2;
        int ret2 = solution(n2);
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
    }

    public static int solution(int n) {
        int[][] arr = new int[n][n];
        int answer = 0;
        int x = 0;
        int y = 0;
        char arrow = 'r';
        for (int i = 1; i <= n * n; i++) {
            arr[x][y] = i;
            switch (arrow) {
                case 'r':
                    if (x == n - 1 || arr[x + 1][y] != 0) {
                        arrow = 'd';
                        y++;
                    }else{
                        x++;
                    }
                    break;
                case 'd':
                    if (y == n-1 || arr[x][y+1] !=0){
                        arrow = 'l';
                        x--;
                    }else{
                        y++;
                    }
                    break;
                case 'l':
                    if(x == 0 || arr[x-1][y] !=0){
                        arrow = 'u';
                        y--;
                    }else{
                        x--;
                    }
                    break;
                case 'u':
                    if(arr[x][y-1] !=0){
                        arrow = 'r';
                        x++;
                    }else{
                        y--;
                    }
                    break;
            }
        }
        for(int i=0;i<n;i++){
            answer+= arr[i][i];
        }
        return answer;
    }
}
