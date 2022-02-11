import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 일_이_삼_더하기_9095 {
	public static void main(String[] args) throws Exception {
		// 점화식 먼저 구하기
		/*  1 => {1}
			2 => {1+1, 2}
			3 => {1+1+1, 1+2, 2+1, 3}
			4 => {1+3, 2+2, 3+1}
			즉 1, 2, 3의 경우의 수에 +1, +2, +3을 해준다
			총 7개
			1 + 4, 2 + 3, 3 + 2
			5는 13개

			점화식 => dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3]
		*/
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		int dp[] = new int[11];

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for(int i = 4; i <= 10; i++){
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		for(int i = 0; i < T; i ++){
			int tmp = Integer.parseInt(br.readLine());
			System.out.println(dp[tmp]);
		}
	}
}
