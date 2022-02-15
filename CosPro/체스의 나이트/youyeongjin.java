package cospro;

public class 체스의나이트 {
    public static void main(String[] args) {
        String pos = "A7";
        int ret = solution(pos);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }

    public static int solution(String pos) {
        int x = pos.charAt(0) - 64;
        int y = Integer.parseInt(pos.substring(1,2));
        int answer = 8;
        boolean flag = false;
        if(x==1 || x==8) {
            answer -= 4;
            flag = true;
        }
        else if(x==2 || x==7) {
            answer -= 2;
            flag = true;
        }
        if(y==1 || y==8) {
            if(flag) answer -=2;
            else answer -= 4;
        }
        else if(y==2 || y==7) {
            if(flag) answer --;
            else answer -=2;
        }

        return answer;
    }
}
