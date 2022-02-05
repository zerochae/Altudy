import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 피보나치함수_1003 {
	// 재귀( Top - Down ) 호출의 기본 피보나치
	// 피보나치는 수열 종류 중 하나이다.
	// 1 1 2  3 5 8 13 21 34...
	// N, N+1 숫자를 더한 것을 나열하는 것이다.
	static Integer [][] dp = new Integer[41][2];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		dp[0][0] = 1; // N이 0 일때의 0 호출 횟수
		dp[0][1] = 0; // N이 0 일때의 1 호출 횟수
		dp[1][0] = 0; // N이 1 일때의 0 호출 횟수
		dp[1][1] = 1; // N이 1 일때의 1 호출 횟수

		while (T -- > 0){
			int N = Integer.parseInt(br.readLine());
			fibonacci(N);
			sb.append(dp[N][0] + " " + dp[N][1]).append("\n");
		}
		System.out.println(sb);
	}

	public static Integer[] fibonacci(int N) {
		// N에 대한 0, 1 호출 횟수가 없을 때 ( 탐색하지 않은 값일 때 )
		if(dp[N][0] == null || dp[N][1] == null){
			dp[N][0] = fibonacci(N - 1)[0] + fibonacci(N - 2)[0];
			dp[N][1] = fibonacci(N - 1)[1] + fibonacci( N - 2)[1];
		}
		return dp[N];
	}
//	public static int fibonachi(int n){
//		if( n <= 1){
//			return n;
//		} else {
//			return fibonachi(n - 2) + fibonachi( n -1);
//		}
//	}
}
