import java.util.ArrayList;
import java.util.Scanner;

public class ����6_201921009_����ȣ {
    // �����Է��� string������ �Է¹޾� ����ϴ� ���α׷�
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("��갪: " + Calculator(str));
    }

    public static int Calculator(String str) {
        char[] arr = str.toCharArray();
        int result = 0;
        char ch;
        int num1 = Character.getNumericValue(arr[0]);
        int num2 = Character.getNumericValue(arr[2]);
        switch (arr[1]) {
            case '-':
                result = num1 - num2;
                break;
            case '+':
                result = num1 + num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }
        return result;
    }
}
