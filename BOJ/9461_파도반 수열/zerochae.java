import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static Long[] dp;
	
	public static void main(String[] args) throws Exception, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		dp = new Long[101];
		dp[0] = 0L;
		dp[1] = 1L;
		dp[2] = 1L;
		dp[3] = 1L;
		
		while(t --> 0) {
			
			int n = Integer.parseInt(br.readLine());
			System.out.println(solve(n));
			
		}
	}

	private static Long solve(int n) {
		
		if(dp[n] == null) {
			dp[n] = solve(n-2) + solve(n-3);
		}
		return dp[n];
	}
}
