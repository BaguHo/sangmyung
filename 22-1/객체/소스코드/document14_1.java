import java.util.StringTokenizer;

public class document14_1 {
    public static void main(String[] args) {
        int[] array = { 0, 1, 2 };
        // int a�� ��ġ�� ���� � Exception�� �߻��ϴ���, try�� �ɸ����� �˾ƺ���
        int a = 3 / 0;
        try {
            int a = 3 / 0;
            System.out.println(array[3]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("���Ұ� �������� �ʽ��ϴ�");
        } catch (Exception e) {
            System.err.println("������ error");
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