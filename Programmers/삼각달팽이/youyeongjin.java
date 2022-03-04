package programmers.level2;

public class 삼각달팽이 {

    public static void main(String[] args) {
        solution(4);
        solution(5);
        solution(6);
    }

    public static int[] solution(int n) {
        int[][] triangle = new int[n][n];

        char arrow = 'd'; // d down u up r right
        int x = 0 , y = 0;
        for(int i = 1; i <= n*(n+1)/2; i++){
            switch (arrow){
                case 'd' :
                    triangle[x][y] = i;
                    if(y == n-1 || triangle[x][y+1] != 0) {
                        arrow = 'r';
                        x++;
                    }
                    else{
                        y++;
                    }
                    break;

                case 'r' :
                    triangle[x][y] = i;
                    if(x == n-1 || triangle[x+1][y] != 0) {
                        arrow = 'u';
                        x--;
                        y--;
                    }
                    else{
                        x++;
                    }
                    break;

                case 'u' :
                    triangle[x][y] = i;
                    if(triangle[x-1][y-1] != 0) {
                        arrow = 'd';
                        y++;
                    }
                    else{
                        x--;
                        y--;
                    }
                    break;
            }
        }
        int[] answer = new int[n*(n+1)/2];
        int cnt = 0;
        for(int i = 0; i<n;i++){
            for(int j=0; j<=i;j++){
                answer[cnt++] = triangle[j][i];
            }
        }


        return answer;
    }
}
