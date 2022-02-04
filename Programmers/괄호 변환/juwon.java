public class 괄호변환 {
	public static void main(String[] args) {
		String solution = solution(new String("(()())()"));
		String solution1 = solution(new String(")("));
		String solution2 = solution(new String("()))((()"));

		System.out.println(solution);
		System.out.println(solution1);
		System.out.println(solution2);
	}
	public static String solution(String p) {
		String answer = "";
		if(checkInputs(p)){
			return p;
		}
		answer = split(p);
		return answer;
	}

	public static boolean checkInputs(String p){
		int open = 0;
		if(p.charAt(0) == ')') return false;
		for(int i = 0; i < p.length(); i++){
			if(p.charAt(i) == '('){
				open++;
			}else{
				open --;
				if(open < 0) return false;
			}
		}
		return true;
	}

	public static String reverse(String str){
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i < str.length() -1; i++){
			if(str.charAt(i) == '('){
				sb.append(")");
			}else{
				sb.append("(");
			}
		}
		return sb.toString();
	}

	public static String split(String str){
		StringBuilder u = new StringBuilder();
		StringBuilder v = new StringBuilder();
		int open = 0;

		if(str.length() == 0){
			return "";
		}

		for(int i = 0; i < str.length(); i++){
			if(str.charAt(i) == '('){
				open ++;
			}else{
				open --;
			}

			if(open == 0){
				u.append(str.substring(0, i+1));
				v.append(str.substring(i+1, str.length()));
				if(checkInputs(u.toString())){
					u.append(split(v.toString()));
				}else{
					StringBuilder sb = new StringBuilder();
					sb.append("(");
					sb.append(split(v.toString()));
					sb.append(")");
					sb.append(reverse(u.toString()));
					return sb.toString();
				}
				break;
			}
		}
		return u.toString();
	}
}
