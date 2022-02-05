package BackJoon;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 일로만들기 {

	static Integer [] dp;

	// key : 2와 3의 공배수 6으로 나눠지는 경우의 수도 존재한다.

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		dp = new Integer[N + 1];

		dp[0] = dp[1] = 0;

//		System.out.println(recur(N));
		System.out.println(recur2(N, 0));
	}
	// Math.min은 2개의 매개변수 중 작은 값을 리턴한다.
	// int float long double등 자료형 사용 가능
	public static int recur(int N){
		if(dp[N] == null) {
			// 6으로 나누어지는경우
			if (N % 6 == 0) {
				dp[N] = Math.min(recur(N - 1), Math.min(recur(N / 3), recur(N / 2))) + 1;
			} else if (N % 3 == 0) {
				// 3으로만 나눠지는경우
				dp[N] = Math.min(recur(N / 3), recur(N - 1)) + 1;
			} else if (N % 2 == 0) {
				// 2로만 나눠지는 경우
				dp[N] = Math.min(recur(N / 2), recur(N - 1)) + 1;
			} else {
				// 2와 3으로 나눠지지 않는 경우
				dp[N] = recur(N - 1) + 1;
			}
		}
		return dp[N];
	}

	public static int recur2(int N, int cnt){
		if (N < 2){
			return cnt;
		}
		return Math.min(recur2(N / 2, cnt + 1 + ( N % 2)),
				recur2(N / 3, cnt + 1 + (N % 3)));
	}
}
