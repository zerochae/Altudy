import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int n;
	static int arr[];
	static int count = 0;
	
	
	public static void main(String[] args) throws Exception, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		arr = new int[n];
		
		dfs(0);
		
		System.out.println(count);
		
		
	}


	public static void dfs(int depth) {
		
		if(n == depth) {
			count++;
			
//			for(int value : arr) {
//				
//				for(int i =0; i<n; i++) {
//					if(i == value) {
//						System.out.print("X ");
//					} else {
//						System.out.print("O ");
//					}
//				}
//				System.out.println();
//			}
//			System.out.println();
			
			return;
		}
		
		for(int i =0; i<n; i++) {
			
			arr[depth] = i;
			
			if(possible(depth)) {
				dfs(depth+1);
			}
		}
	}

	public static boolean possible(int col) {
		/*
		 
		 	false가 나올 경우!!!!!!!!!!!!!!!
		 	
		 	1. 같은 row에 있을 때 arr[i] == arr[col]
		 	2. 대각선 상에 위치 할 경우 Math.abs(i-col) == Math.abs(arr[i] - arr[col])
		 
		 */
		 
		for(int i = 0; i<col; i++) {
			
			if(arr[i] == arr[col]) {
				return false;
			}
			else if(Math.abs(arr[col] - arr[i]) == Math.abs(col - i)) {
				return false;
			}
		}
		
		return true;
	}
}
