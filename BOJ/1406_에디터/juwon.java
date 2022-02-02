import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Editor_1406 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();

		String str = br.readLine();

		Stack<Character> left = new Stack<>();
		Stack<Character> right = new Stack<>();

		for(int i = 0; i < str.length(); i++){
			left.push(str.charAt(i));
		}
		int N = Integer.parseInt(br.readLine());

		for(int i = 0; i < N; i++){
			String temp = br.readLine();
			switch (temp.charAt(0)){
				case 'L':
					if(left.isEmpty()){
						break;
					}
					right.push(left.pop());
					break;
				case 'D':
					if(right.isEmpty()){
						break;
					}
					left.push(right.pop());
					break;
				case 'B':
					if(left.isEmpty()){
						break;
					}
					left.pop();
					break;
				case 'P':
					left.push(temp.charAt(2));
					break;
			}
		}
		while(!left.isEmpty()){
			right.push(left.pop());
		}
		while(!right.isEmpty()){
			sb.append(right.pop());
		}
		System.out.println(sb);
	}
}
