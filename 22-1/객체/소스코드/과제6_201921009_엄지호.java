import java.util.ArrayList;
import java.util.Scanner;
import java.lang.*;

public class ����6_201921009_����ȣ {
    // �����Է��� string������ �Է¹޾� ����ϴ� ���α׷�(����)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("��갪: " + Calculator(str));
    }

    public static int Calculator(String str) {
        char[] arr = str.toCharArray();
        int result = 0;
        char ch = arr[1];
        String num1;
        String num2;
        // string -> char array, for(char array), char array -> string, string -> int
        for (int i = 0; '0' < arr[i] && arr[i] < '9'; i++) {

        }
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
