import java.util.Scanner;

public class PrintStar {
    public static void main(String[] args) {
        // ���ڸ� �Է¹ް� �� �� ��ŭ ���� ����
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        PrintStar(n);
    }

    public static void PrintStar(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print("*");
        }
        System.out.println();
    }
}
