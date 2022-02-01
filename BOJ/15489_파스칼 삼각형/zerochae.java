import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static Integer dp[][];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input[] = br.readLine().split(" ");
		
		int r = Integer.parseInt(input[0]);
		int c = Integer.parseInt(input[1]);
		int w = Integer.parseInt(input[2]);
		
		dp = new Integer[31][31];
	
		int sum = 0;
		for(int i =0; i<w; i++) {
			for(int j = 0; j<i+1; j++) {
				sum+= solve(r+i,c+j);
			}
		}
		System.out.println(sum);
	}

	private static int solve(int r, int c) {
		
		if(r == c || c == 1) dp[r][c] = 1;
		if(dp[r][c] == null) dp[r][c] = solve(r-1,c-1) + solve(r-1,c);
		return dp[r][c];
	}
}