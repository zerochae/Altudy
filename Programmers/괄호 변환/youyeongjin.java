package programmers.level2;

public class 괄호변환 {
    public static void main(String[] args) {
        solution("(()())()");
        solution(")(");
        solution("()))((()");
    }

    public static String solution(String p) {
        StringBuilder sb = new StringBuilder();
        while(!checkPerfect(p)){
            int leftCount = 0;
            int rightCount = 0;
            String u = null;
            for(int i=0; i<p.length();i++){
                if(p.charAt(i) == '(') leftCount++;
                else rightCount++;
                if(leftCount == rightCount) {
                    u = p.substring(0,i+1);
                    p = p.substring(i+1,p.length());
                    break;
                }
            }
            if(checkPerfect(u)){
                sb.append(u);
            }else{
                u = u.substring(1,u.length()-1);
                u = u.replaceAll("\\(","a");
                u = u.replaceAll("\\)","(");
                u = u.replaceAll("a",")");
                p = "(" + solution(p) + ")" + u;
            }
        }
        sb.append(p);
        System.out.println(sb.toString());
        return sb.toString();
    }

    public static boolean checkPerfect(String u){
        while(u.length()!=0){
            if(u.equals(u.replaceAll("\\(\\)",""))) return false;
            u = u.replaceAll("\\(\\)","");
        }
        return true;
    }
}
