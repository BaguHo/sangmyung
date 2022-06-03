import java.util.StringTokenizer;

public class document14_1 {
    public static void main(String[] args) {
        int[] array = { 0, 1, 2 };
        // int a의 위치에 따라 어떤 Exception이 발생하는지, try에 걸리는지 알아보기
        int a = 3 / 0;
        try {
            int a = 3 / 0;
            System.out.println(array[3]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("원소가 존재하지 않습니다");
        } catch (Exception e) {
            System.err.println("나머지 error");
        } finally {
            System.out.println("finally");
        }

        /*
         * // NoSuchElementException
         * String s = "This is a ";
         * StringTokenizer st = new StringTokenizer(s);
         * while (st.hasMoreTokens()) {
         * System.out.print(st.nextToken() + "+");
         * }
         * System.out.print(st.nextToken());
         */
    }
}