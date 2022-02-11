import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 이곱하기N타일링_11726 {
	public static void main(String[] args) throws Exception {
		/*
			2 x n 크기의 직사각형을 1 x 2, 2 x 1 타일로 채우는 방법의 수
			1 x 2 => 1
			2 x 2 => 2
			2 x 3 => 3
			2 x 4 => 5
			2 x 5 => 8

			dp[n] => dp[n - 1] + dp[n - 2]

			if(n == 1) dp[n] = 1;

		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int [] dp = new int [N + 2];

		dp[1] = 1;
		dp[2] = 2;

		for(int i = 3; i <= N; i++){
			dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
		}
		System.out.println(dp[N]);
	}
}
