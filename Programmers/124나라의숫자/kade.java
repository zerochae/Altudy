package main.level_2;

public class _124나라의숫자 {

    // 1 2 4
    // 11 12 14
    // 21 22 24
    // 41 42 44
    // 111 112 114
    // 121 122 124
    // 141 142 144

    public static String solution(int n) {
        StringBuilder str = new StringBuilder();
        int current = n;
        int reminder = 0;

        while(current != 0){
            reminder = current % 3;
            current = current / 3;

            if(reminder == 0) {
                str.insert(0, 4);
                current--;
            } else {
                str.insert(0, reminder);
            }
        }
        return str.toString();
    }

    public static void main(String[] args) {
//        solution(1); // 1
//        solution(2); // 2
//        solution(3); // 4
        solution(9); // 24
        solution(13); // 111
        solution(20); // 142

    }
}
