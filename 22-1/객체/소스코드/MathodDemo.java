public class MathodDemo {
    public static void main(String[] args) {
        sum(1, 10);
        sum(1, 100);
        sum(100, 1000);
    }

    public static void sum(int start, int end) {
        int result = 0;
        for (int i = start; i <= end; i++) {
            result += i;
        }
        System.out.println(start + " ~ " + end + "까지의 합:" + result);
    }
}
