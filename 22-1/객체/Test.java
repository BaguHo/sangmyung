import java.util.Scanner;

public class Test {
    public static void main(String[] arg) {
        Scanner input = new Scanner(System.in);
        System.out.println("���ڸ� �Է����ּ���");
        int temp = input.nextInt();
        while (temp != 0) {
            System.out.println(temp);
            System.out.println("���ڸ� �Է����ּ���");
            temp = input.nextInt();
        }
    }
}