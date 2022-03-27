import java.util.Scanner;

public class Test {
    public static void main(String[] arg) {
        Scanner input = new Scanner(System.in);
        System.out.println("숫자를 입력해주세요");
        int temp = input.nextInt();
        while (temp != 0) {
            System.out.println(temp);
            System.out.println("숫자를 입력해주세요");
            temp = input.nextInt();
        }
    }
}