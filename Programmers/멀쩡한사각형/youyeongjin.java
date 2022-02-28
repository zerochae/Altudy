package programmers.level2;

public class 멀쩡한사각형 {
    public static void main(String[] args) {
        solution(8,12);
    }

    public static long solution(int w, int h) {
        long answer = 1;

        Long width = Long.valueOf(w);
        Long height = Long.valueOf(h);

        answer = width*height - (width + height - getNum(width, height));

        return answer;
    }

    public static long getNum(long width, long height) {
        long small = height;
        long big = width;

        if (width < height) {
            big = height;
            small = width;
        }

        long temp = 0;
        while (small > 0) {
            temp = big % small;

            big = small;
            small = temp;
        }

        return (big);
    }
}
