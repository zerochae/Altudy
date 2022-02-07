import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 피보나치수5_10870 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

//		System.out.println(fibo(N));

		int [] fibonacci = new int [ N + 1 ];

		for(int i = 0; i < fibonacci.length; i++ ){
			if ( i == 0){
				fibonacci[i] = 0;
			}else if( i == 1){
				fibonacci[i] = 1;
			}else{
				fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
			}
		}

		System.out.println(fibonacci[N]);

	}

//	public static int fibo(int n){
//		if(n == 0) return 0;
//		if(n == 1) return 1;
//
//		return fibo(n - 1) + fibo(n - 2 );
//	}

}
